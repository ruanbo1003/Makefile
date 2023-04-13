//
// Created by Robert on 2023/4/13.
//

#include <time.h>

int now_seconds() {
    time_t now_s = time(NULL);
    return now_s;
}
