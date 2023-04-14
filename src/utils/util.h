//
// Created by Robert on 2023/4/13.
//

#ifndef MAKEFILE_UTIL_H
#define MAKEFILE_UTIL_H

#include <pthread.h>

// time
int now_seconds();
void get_time_str(char* str, int len);

// thread
typedef void* (*thread_func)(void *);

pthread_t create_thread(thread_func func, void* data);


#endif //MAKEFILE_UTIL_H
