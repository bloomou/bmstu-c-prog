#include "read_print_structs.h"

int read_structs(char *file_name, item *items_array, int *items_num)
{
    int rc = SUCCESSFUL;
    FILE *f = fopen(file_name, "r");
    if (f != NULL)
    {
        if (feof(f))
        {
            if (fclose(f) == EOF)
                rc = FAIL_CLOSE;
            rc = FAIL_READ;
        }
        for (int i = 0; !feof(f) && rc == SUCCESSFUL; i++, (*items_num)++)
        {
            char c;
            int count = 0;
            while ((c = fgetc(f)) != '\n' && c != EOF && count <= LEN_ITEM_TITLE)      
                items_array[i].title[count++] = c;				

            if (count == LEN_ITEM_TITLE || count == 0)
                rc = INVALID_LEN_TITLE;
            else
                items_array[i].title[count] = '\0';

            if (fscanf(f, "%lf\n", &items_array[i].mass) != 1)
                rc = FAIL_READ;
            else if (items_array[i].mass <= 0)
                rc = FAIL_READ;

            if (fscanf(f, "%lf\n", &items_array[i].volume) != 1)
                rc = FAIL_READ;
            else if (items_array[i].volume <= 0)
                rc = FAIL_READ;

            if (*items_num == MAX_NUM - 1)
                rc = INVALID_NUM;
        }
    }
    else
        rc = NO_FILE;
    return rc;
}

void print_structure(item *one_item)
{
    printf("%s\n", one_item->title);
    printf("%.6f\n", one_item->mass);
    printf("%.6f\n", one_item->volume);
}

void print_data(item *items_arr, int num_of_items)
{
    for (int i = 0; i < num_of_items; i++)
        print_structure(items_arr + i);
}
