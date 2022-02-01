#ifndef LAB_06_02_MAIN_H
#define LAB_06_02_MAIN_H

#include <stdio.h>
#include <string.h>

#define SUCCESSFUL 0
#define INVALID_ARGS -1
#define NO_FILE -2
#define FAIL_READ -3
#define FAIL_CLOSE -4
#define INVALID_NUM -5
#define INVALID_LEN_TITLE -6

#define MAX_NUM 15
#define LEN_ITEM_TITLE 25

typedef struct
{
    char title[LEN_ITEM_TITLE + 1];
    double mass;
    double volume;
} item;

#endif //LAB_06_02_MAIN_H
