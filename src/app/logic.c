//
// Created by Robert on 2023/4/13.
//

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "data.h"


void* logic_thread(void* param) {
    struct ThreadData* data = (struct ThreadData*)param;

    while (data->_run) {
        sleep(2);

        printf("thread:%s......\n", data->_thread_name);

        handle_msg_queue(data->_msgs);
        for(int i=0; i<data->_msgs->_handle_idx; i++) {
            printf("%s\n", data->_msgs->_handle_buf[i]);

            free(data->_msgs->_handle_buf[i]);
            data->_msgs->_handle_buf[i] = NULL;
        }

        printf("\n");
    }

    return NULL;
}

