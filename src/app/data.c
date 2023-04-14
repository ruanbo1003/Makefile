//
// Created by Robert on 2023/4/13.
//

#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <strings.h>
#include <string.h>
#include "type.h"


struct MsgQueue* new_msg_queue() {
    struct MsgQueue* queue = (struct MsgQueue*)malloc(sizeof(struct MsgQueue));

    queue->_buf = (char **) malloc(sizeof(char*) * BUF_SIZE);
    for(int i=0; i<BUF_SIZE; i++) {
        queue->_buf[i] = (char*) malloc(sizeof(char)*64);
    }
    queue->_buf_idx = 0;

    queue->_handle_buf = (char **) malloc(sizeof(char*) * BUF_SIZE);
    for(int i=0; i<BUF_SIZE; i++) {
        queue->_handle_buf[i] = (char*) malloc(sizeof(char)*64);
    }
    queue->_handle_idx = 0;

    pthread_mutex_init(&queue->_mtx, NULL);

    return queue;
}

void delete_msg_queue(struct MsgQueue* msg_queue) {
    for(int i=0; i<BUF_SIZE; i++) {
        free(msg_queue->_buf[i]);
        free(msg_queue->_handle_buf[i]);
    }

    free(msg_queue->_buf);
    free(msg_queue->_handle_buf);

    pthread_mutex_destroy(&msg_queue->_mtx);

    free(msg_queue);
}

void add_msg_to_queue(struct MsgQueue* msg_queue, char* msg) {
    pthread_mutex_lock(&msg_queue->_mtx);

    strcpy(msg_queue->_buf[msg_queue->_buf_idx], msg);
    msg_queue->_buf_idx += 1;

    pthread_mutex_unlock(&msg_queue->_mtx);
}

void handle_msg_queue(struct MsgQueue* msg_queue) {
    pthread_mutex_lock(&msg_queue->_mtx);

    char** tmp = msg_queue->_handle_buf;

    msg_queue->_handle_buf = msg_queue->_buf;
    msg_queue->_buf = tmp;
    msg_queue->_handle_idx = msg_queue->_buf_idx;
    msg_queue->_buf_idx = 0;

    pthread_mutex_unlock(&msg_queue->_mtx);
}

struct ThreadData* new_thread_data(struct MsgQueue* msg_queue, const char* name, enum ThreadType thread_type) {
    struct ThreadData* data = (struct ThreadData*)malloc(sizeof(struct ThreadData));
    data->_thread_type = thread_type;
    data->_msgs = msg_queue;
    data->_thread_name = name;

    data->_start_time = 0;
    data->_stop_time = 0;
    data->_run = true;

    return data;
}
void delete_thread_data(struct ThreadData* data) {
    data->_msgs = NULL;
    free(data);
}
