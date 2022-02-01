#ifndef COUNT_CHANGES_OF_SIGN_H
#define COUNT_CHANGES_OF_SIGN_H

#include <stdio.h>

#define SUCCESSFUL 0
#define FAIL_READ -1
#define COULD_NOT_OPEN_FILE -2
#define ONE_ELEMENT -3

int create_int_file(FILE *f);

int process(FILE *f, int *count);

#endif // COUNT_CHANGES_OF_SIGN_H
