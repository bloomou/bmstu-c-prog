#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>

#define LEN_SURNAME 25
#define LEN_NAME 10
#define COUNT_MARKS 4

#define SUCCESSFUL 0
#define INVALID_ARGS 53

#define ARGS_AMOUNT_TASK_A_C 3
#define ARGS_AMOUNT_TASK_B 5

typedef struct
{
    char surname[LEN_SURNAME + 1];
    char name[LEN_NAME + 1];
    unsigned int marks[COUNT_MARKS];
} student;

#endif // MAIN_H
