#ifndef LAB_06_02_READ_PRINT_STRUCTS_H
#define LAB_06_02_READ_PRINT_STRUCTS_H

#include "../inc/main.h"
#include "memory_work.h"

int read_structs(FILE *f, item_t *items_array, int *items_num);

int is_empty_file(FILE *f);

void print_structure(item_t *one_item);

void print_data(item_t *items_arr, int num_of_items);

#endif //LAB_06_02_READ_PRINT_STRUCTS_H
