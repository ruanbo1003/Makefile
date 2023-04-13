//
// Created by Robert on 2023/4/13.
//

#include <unistd.h>
#include <stdio.h>
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

    pthread_join(io_1_t, NULL);
    pthread_join(io_2_t, NULL);
    pthread_join(logic_t, NULL);

    while (true) {
        sleep(3);
        printf("main thread..");
    }

    // release resource
    {
        delete_msg_queue(msgs);

        delete_thread_data(io_1_thread_data);
        delete_thread_data(io_2_thread_data);
        delete_thread_data(logic_thread_data);
    }

}
