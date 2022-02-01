#ifndef NEW_FILE_SUBSTRING_H
#define NEW_FILE_SUBSTRING_H

#include <stdio.h>
#include <string.h>
#include "main.h"
#include "sort_students.h"

#define SUCCESSFUL 0
#define NO_FILE -1
#define NO_STUDENTS -2

int command_students_with_substr(char *str_1, char *str_2, char *str_3);

int new_file(FILE *f, int size, char *new_file, char *string);

#endif // NEW_FILE_SUBSTRING_H
