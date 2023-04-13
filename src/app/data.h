//
// Created by Robert on 2023/4/13.
//

#ifndef MAKEFILE_APP_H
#define MAKEFILE_APP_H

#include <stddef.h>
#include <pthread.h>
#include <stdbool.h>
#include "type.h"


struct MsgQueue* new_msg_queue();
void delete_msg_queue(struct MsgQueue* msg_queue);
void add_msg_to_queue(struct MsgQueue* msg_queue, char* msg);
void handle_msg_queue(struct MsgQueue* msg_queue);

struct ThreadData* new_thread_data(struct MsgQueue* msg_queue, const char* name, enum ThreadType thread_type);
void delete_thread_data(struct ThreadData* data);


#endif //MAKEFILE_APP_H
