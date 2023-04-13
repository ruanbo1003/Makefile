//
// Created by Robert on 2023/4/13.
//

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "data.h"


void* io_thread(void* param) {
    struct ThreadData* data = (struct ThreadData*)param;

    int count = 0;
    while (data->_run) {
        sleep(1);
        count += 1;

        char* msg = (char*) malloc(16);
        sprintf(msg, "%s-%d", data->_thread_name, count);
        add_msg_to_queue(data->_msgs, msg);
    }

    return NULL;
}
