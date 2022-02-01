#include "../inc/sort_file.h"

void mysort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *))
{
    int last_swap = number - 1;
    for (int i = 1; i < number; i++)
    {
        int curr_swap = -1;
        for (int j = 0; j < last_swap; j++)
        {
            if (comparator((char*) first + j * size, (char*)first + (j + 1) * size) > 0)
            {
                swap((char*) first + j * size, (char*) first + (j + 1) * size, size);
                curr_swap = j;
            }
        }
        last_swap = curr_swap;
    }
}

int func_cmp(const void *value_1, const void *value_2)
{
    return (*(int *) value_1 - *(int *) value_2);
}

void swap(void *value_1, void *value_2, int size)
{
    for (int i = 0; i < size; i++)
    {
        char tmp = *((char*)value_1 + i);
        *((char*)value_1 + i) = *((char*)value_2 + i);
        *((char*)value_2 + i) = tmp;
    }
}