//
// Created by Robert on 2023/4/13.
//

#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "data.h"
#include "../utils/util.h"


void* logic_thread(void* param) {
    struct ThreadData* data = (struct ThreadData*)param;

    char path[128];
    if(getcwd(path, sizeof(path)) != NULL) {
        printf("current path:%s\n", path);
    }

    char time_str[32];
    get_time_str(time_str, 32);
    char log_file[128];
    sprintf(log_file, "%s/data/log/%s.log", path, time_str);
    printf("log_file:%s\n", log_file);

    FILE *log_f = fopen(log_file, "a+");
    if(log_f == NULL) {
        printf("fopen failed:%d\n", errno);
    }

    while (data->_run) {
        sleep(2);

        printf("thread:%s......\n", data->_thread_name);

        handle_msg_queue(data->_msgs);
        for(int i=0; i<data->_msgs->_handle_idx; i++) {
            printf("%s\n", data->_msgs->_handle_buf[i]);

            if(log_f) {
                fputs(data->_msgs->_handle_buf[i], log_f);
                fputs("\n", log_f);
            }
        }

        if(log_f) {
            fflush(log_f);
        }
    }

    if(log_f) {
        fflush(log_f);
        fclose(log_f);
    }

    return NULL;
}

