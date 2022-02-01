#ifndef LAB_06_02_MAIN_H
#define LAB_06_02_MAIN_H

#include <stdio.h>
#include <string.h>

#define SUCCESSFUL 0
#define INVALID_ARGS -1
#define NO_FILE -2
#define FAIL_READ -3
#define FAIL_CLOSE -4
#define FAIL_ALLOC -5
#define INVALID_NUM -6
#define FAIL_FIND -7
#define INVALID_FILE -8

#define MAX_NUM 15

#define ARGS_AMOUNT_NO_PREFIX 2
#define ARGS_AMOUNT_PREFIX 3

typedef struct
{
    char *title;
    double mass;
    double volume;
} item_t;

#endif //LAB_06_02_MAIN_H
