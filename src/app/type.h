//
// Created by Robert on 2023/4/13.
//

#ifndef MAKEFILE_TYPE_H
#define MAKEFILE_TYPE_H

#include <pthread.h>
#include <stdbool.h>

#define BUF_SIZE 128

//enum ThreadType;
enum ThreadType {
    THREAD_IO,
    THREAD_LOGIC,
};

struct MsgQueue {
    pthread_mutex_t _mtx;

    char** _buf;
    int _buf_idx;

    char** _handle_buf;
    int _handle_idx;
};


struct ThreadData {
    enum ThreadType _thread_type;
    struct MsgQueue* _msgs;
    const char* _thread_name;

    int _start_time;
    int _stop_time;
    bool _run;
};

void* io_thread(void* param);
void* logic_thread(void* param);

#endif //MAKEFILE_TYPE_H
