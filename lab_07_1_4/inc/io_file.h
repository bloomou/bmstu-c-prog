#ifndef LAB_07_1_4_IO_FILE_H
#define LAB_07_1_4_IO_FILE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESSFUL 0
#define NO_FILE -1
#define FAIL_READ -2
#define NO_NUMBERS -3
#define FAIL_MEM_ALLOC -4

int count_numbers_in_file(char *file_name, int *count_nums);

int read_elements_from_file(char *file_name, int *pb, int *pe);

int write_elements_into_file(char *file_name, int *pb, int *pe);

int allocate_mem_array(int num_of_elements, int **pb);

void free_mem_array(int **pb, int **pe);

#endif //LAB_07_1_4_IO_FILE_H
