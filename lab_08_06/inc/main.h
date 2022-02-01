#ifndef LAB_08_06_MAIN_H
#define LAB_08_06_MAIN_H

#define SUCCESSFUL 0
#define FAIL_ALLOC -1
#define FAIL_INPUT_SIZE -2
#define FAIL_INPUT_ELEMENT -3
#define FAIL_INPUT_EXP -4

typedef struct
{
    int **data;
    int rows;
    int columns;
} matrix_t;

#endif //LAB_08_06_MAIN_H
