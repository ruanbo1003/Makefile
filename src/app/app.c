//
// Created by Robert on 2023/4/13.
//

#include <unistd.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include "data.h"
#include "../utils/util.h"


void app() {
    struct MsgQueue* msgs = new_msg_queue();  // init msg queue

    struct ThreadData* io_1_thread_data = NULL;
    struct ThreadData* io_2_thread_data = NULL;
    struct ThreadData* logic_thread_data = NULL;

    // init thread data
    {
        io_1_thread_data = new_thread_data(msgs, "io-1", THREAD_IO);
        io_2_thread_data = new_thread_data(msgs, "io-2", THREAD_IO);
        logic_thread_data = new_thread_data(msgs, "logic", THREAD_LOGIC);
    }

    pthread_t io_1_t = create_thread(io_thread, (void*)io_1_thread_data);
    pthread_t io_2_t = create_thread(io_thread, (void*)io_2_thread_data);
    pthread_t logic_t = create_thread(logic_thread, (void*)logic_thread_data);

    char input[128];
    while (true) {
        bzero(input, sizeof(char)*128);
        scanf("%s", input);
        printf("main thread: [%s]..\n", input);

        if(strcmp(input, "quit") == 0) {
            break;
        }

        sleep(1);
    }

    // stop threads
    {
        io_1_thread_data->_run = false;
        io_2_thread_data->_run = false;
        logic_thread_data->_run = false;
    }

    // wait for threads done
    {
        pthread_join(io_1_t, NULL);
        pthread_join(io_2_t, NULL);
        pthread_join(logic_t, NULL);
    }


    // release resource
    {
        delete_thread_data(io_1_thread_data);
        delete_thread_data(io_2_thread_data);
        delete_thread_data(logic_thread_data);

        delete_msg_queue(msgs);
    }

}
