#ifndef LAB_07_1_4_ANALYSIS_H
#define LAB_07_1_4_ANALYSIS_H

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <sys/time.h>
#include <limits.h>

#include "mysort.h"

#define MAX_LEN 1000
#define N_REPEAT 1000

#define SUCCESSFUL 0
#define NO_FILE -1

void arr_of_rand_nums(int *arr, int n);

void arr_of_sorted_nums(int *arr, int n);

void arr_of_reversed_nums(int *arr, int n);

void write_measurements_to_files(FILE *f, FILE *g, int *array);

int64_t get_time(int *arr, int n, void func_sort(void *, size_t, size_t, int (*comparator)(const void *, const void *)));

#endif //LAB_07_1_4_ANALYSIS_H
