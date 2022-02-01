#include "io.h"

int read_structs(FILE *f, item_t *items_array, int *items_num)
{
    int rc = SUCCESSFUL;

    for (int i = 0; i < *items_num && rc == SUCCESSFUL; i++)
    {
        if (alloc_str(&(items_array[i].title), f) != SUCCESSFUL)
            rc = FAIL_READ;

        if (rc == SUCCESSFUL && fscanf(f, "%lf\n", &items_array[i].mass) != 1)
            rc = FAIL_READ;
        else if (rc == SUCCESSFUL && items_array[i].mass <= 0)
            rc = FAIL_READ;

        if (rc == SUCCESSFUL && fscanf(f, "%lf\n", &items_array[i].volume) != 1)
            rc = FAIL_READ;
        else if (rc == SUCCESSFUL && items_array[i].volume <= 0)
            rc = FAIL_READ;

        if (rc == SUCCESSFUL && *items_num == MAX_NUM - 1)
            rc = INVALID_NUM;
    }
    return rc;
}

int is_empty_file(FILE *f)
{
    int rc = SUCCESSFUL;
    if (feof(f))
    {
        if (fclose(f) == EOF)
            rc = FAIL_CLOSE;
        rc = FAIL_READ;
    }

    return rc;
}

void print_structure(item_t *one_item)
{
    printf("%s\n", one_item->title);
    printf("%.6f\n", one_item->mass);
    printf("%.6f\n", one_item->volume);
}

void print_data(item_t *items_arr, int num_of_items)
{
    for (int i = 0; i < num_of_items; i++)
        print_structure(items_arr + i);
}
