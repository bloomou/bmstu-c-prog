#ifndef NEW_FILE_H
#define NEW_FILE_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS_WRITE 1
#define SUCCESSFUL 0
#define FAIL_WRITE -1

#define MIN -1000
#define MAX 1000

void command_create_file(FILE *f, int *rc, int number);

int create_file_from_rand_nums(FILE *f, int num);

int get_rand_from_range(const int min, const int max);

#endif // NEW_FILE_H
