#ifndef PRINT_FILE_H
#define PRINT_FILE_H

#include <stdio.h>

#define SUCCESS_READ 1
#define SUCCESSFUL 0
#define FAIL_READ -1
#define FAIL_SEEK -2

void command_print_file(FILE *f, int *rc);

int print_int_file(FILE *f);

int file_size(FILE *f, size_t *size);

#endif // PRINT_FILE_H
