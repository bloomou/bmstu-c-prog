#ifndef LAB_09_01_02_MEMORY_WORK_H
#define LAB_09_01_02_MEMORY_WORK_H

#define _GNU_SOURCE

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../inc/main.h"

int alloc_array(item_t **items_array, int *items_len, FILE *f);

int alloc_str(char **str, FILE *file);

void free_array(item_t **items_array, int n);

#endif //LAB_09_01_02_MEMORY_WORK_H
