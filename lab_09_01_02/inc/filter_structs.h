#ifndef LAB_09_01_02_PREFIX_STRUCTS_H
#define LAB_09_01_02_PREFIX_STRUCTS_H

#include <stdlib.h>
#include <string.h>

#include "../inc/main.h"
#include "../inc/memory_work.h"

int find_items_with_prefix(item_t *items_array, int items_num, item_t **new_items_array, int *new_items_num, char *prefix);

int filter_items(item_t *items_array, int items_num, item_t **new_items_array, int *new_items_num, char *prefix, int *count);

void copy_items(item_t *dest, item_t *src);

#endif //LAB_09_01_02_PREFIX_STRUCTS_H
