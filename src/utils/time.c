//
// Created by Robert on 2023/4/13.
//

#include <time.h>

int now_seconds() {
    time_t now_s = time(NULL);
    return now_s;
}

void get_time_str(char* str, int len) {
    time_t now;
    time(&now);
    struct tm* info = localtime(&now);

    strftime(str, len, "%Y%m%d-%H%M", info);
}