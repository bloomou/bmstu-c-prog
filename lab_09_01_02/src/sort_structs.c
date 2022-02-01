#include "../inc/sort_structs.h"

int bubble_sort_structs(item_t *items_arr, int num_of_items)
{
    int rc = SUCCESSFUL;

    for (int i = 0; i < num_of_items; i++)
        for (int j = 0; j < num_of_items - i - 1; j++)
        {
            double density_1 = items_arr[j].mass / items_arr[j].volume;
            double density_2 = items_arr[j + 1].mass / items_arr[j + 1].volume;
            if (density_1 > density_2)
                swap(&items_arr[j], &items_arr[j + 1]);
        }

    return rc;
}

void swap(item_t *item_1, item_t *item_2)
{
    item_t temp = *item_1;
    *item_1 = *item_2;
    *item_2 = temp;
}