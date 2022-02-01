#include "filter_structs.h"

void filter_structs(item *items_arr, int items_num, item *new_items_arr, int *new_items_num, char *prefix)
{
    for (int i = 0; i < items_num; i++)
        if (strncmp(prefix, items_arr[i].title, strlen(prefix)) == SUCCESSFUL)
        {
            new_items_arr[*new_items_num] = items_arr[i];
            (*new_items_num)++;
        }
}