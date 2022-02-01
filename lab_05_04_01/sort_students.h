#ifndef SORT_STUDENTS_H
#define SORT_STUDENTS_H

#include <stdio.h>
#include <string.h>
#include "main.h"

#define SUCCESSFUL 0
#define NO_FILE -1
#define WRONG_SIZE_FILE -2
#define WRONG_LEN_NAME -3

int command_sort_students(char *string);

void sort_students(FILE *f, int size);

int check_size_of_file(FILE *f);

int check_struct_file(FILE *f, int *size);

student get_student(FILE *f, int index);

void swap(FILE *f, int pos_1, int pos_2);

void put_student_by_pos(FILE *f, student *stud, int pos);

void print_students(char *string);

#endif // SORT_STUDENTS_H
