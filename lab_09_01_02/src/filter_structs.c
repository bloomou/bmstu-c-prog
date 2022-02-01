#include "../inc/filter_structs.h"

int find_items_with_prefix(item_t *items_array, int items_num, item_t **new_items_array, int *new_items_num, char *prefix)
{
    int rc = SUCCESSFUL;

    *new_items_num = items_num;
    *new_items_array = (item_t *) malloc(sizeof(item_t) * (*new_items_num));
    if (!*new_items_array)
    {
        rc = FAIL_ALLOC;
        free_array(new_items_array, 0);
    }
    if (rc == SUCCESSFUL)
    {
        int count = 0;
        rc = filter_items(items_array, items_num, new_items_array, new_items_num, prefix, &count);
        if (rc == SUCCESSFUL && count == 0)
        {
            rc = FAIL_FIND;
            free_array(new_items_array, count);
        }
        else if (rc == SUCCESSFUL)
        {
            *new_items_num = count;
            item_t *new_data = (item_t *) realloc(*new_items_array, sizeof(item_t) * (*new_items_num));
            if (!new_data)
            {
                rc = FAIL_ALLOC;
                free_array(new_items_array, *new_items_num);
            }
            else
                *new_items_array = new_data;
        }
    }

    return rc;
}

int filter_items(item_t *items_array, int items_num, item_t **new_items_array, int *new_items_num, char *prefix, int *count)
{
    int rc = SUCCESSFUL;

    *count = 0;
    for (int i = 0; i < items_num && rc == SUCCESSFUL; i++)
    {
        if (strncmp(prefix, items_array[i].title, strlen(prefix)) == SUCCESSFUL)
        {
            char *new_str = (char *) calloc(strlen(items_array[i].title) + 1, sizeof(char));
            if (!new_str)
            {
                free_array(&items_array, *count);
                rc = FAIL_ALLOC;
            }
            else
            {
                (*new_items_array)[*count].title = new_str;
                copy_items(*new_items_array + *count, items_array + i);
                (*count)++;
            }
        }
    }

    return rc;
}

void copy_items(item_t *dest, item_t *src)
{
    for (int j = 0; j < strlen(src->title) + 1; j++)
    {
        dest->title[j] = src->title[j];
    }
    dest->mass = src->mass;
    dest->volume = src->volume;
}