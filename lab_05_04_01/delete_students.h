#ifndef DELETE_STUDENTS_H
#define DELETE_STUDENTS_H

#include <stdio.h>
#include <string.h>
#include "main.h"
#include "sort_students.h"

#define SUCCESSFUL 0
#define NO_FILE -1
#define NO_STUDENTS -2

int command_delete_students(char *string);

int check_students(FILE *f, int size, FILE *t);

void delete_students(FILE *f, int size, FILE *t);

double avg_mark_of_student(student *stud);

double overall_avg_mark(FILE *f, int size);

#endif // DELETE_STUDENTS_H
