#ifndef LAB_07_1_4_SORT_FILE_H
#define LAB_07_1_4_SORT_FILE_H

#include <stdio.h>

#define SUCCESSFUL 0

void mysort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *));

int func_cmp(const void *value_1, const void *value_2);

void swap(void *value_1, void *value_2, int size);

#endif //LAB_07_1_4_SORT_FILE_H
