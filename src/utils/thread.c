//
// Created by Robert on 2023/4/13.
//

#include <pthread.h>
#include <stdio.h>
#include <errno.h>

typedef void* (*thread_func)(void *);


pthread_t create_thread(thread_func func, void* data) {
    pthread_t pid;
    int ret = pthread_create(&pid, NULL, func, data);
    if(ret != 0) {
        printf("pthread_create() failed:%d\n", errno);
        return 0;
    }

    return pid;
}
