#ifndef SORT_FILE_H
#define SORT_FILE_H

#include <stdio.h>
#include "print_file.h"

#define SUCCESSFUL 0
#define FAIL_SORT -1
#define WRONG_ACCESS -2
#define NO_INTEGER -3

void command_sort_file(FILE *f, int *rc);

int bubble_sort(FILE *f);

void swap(FILE *f, int pos_1, int pos_2, size_t size);

int get_number_by_pos(FILE *f, size_t pos, size_t size, int *result);

int put_number_by_pos(FILE *f, size_t pos, size_t size, int number);

#endif // SORT_FILE_H
