#include "../inc/main.h"
#include "../inc/io.h"
#include "../inc/sort_structs.h"
#include "../inc/filter_structs.h"

int main(int argc, char **argv)
{
    int exit = SUCCESSFUL;

    item_t *items_array = NULL;
    int items_num = 0;
    if (argc == ARGS_AMOUNT_NO_PREFIX || argc == ARGS_AMOUNT_PREFIX)
    {
        FILE *f = fopen(argv[1], "r");
        if (f == NULL)
            exit = NO_FILE;
        else
        {
            exit = is_empty_file(f);
            if (exit == SUCCESSFUL)
            {
                exit = alloc_array(&items_array, &items_num, f);
                if (exit == SUCCESSFUL)
                {
                    exit = read_structs(f, items_array, &items_num);
                    if (exit == SUCCESSFUL)
                    {
                        if (argc == ARGS_AMOUNT_NO_PREFIX)
                        {
                            bubble_sort_structs(items_array, items_num);
                            print_data(items_array, items_num);
                        }
                        else
                        {
                            if (strcmp(argv[2], "ALL") == SUCCESSFUL)
                                print_data(items_array, items_num);
                            else
                            {
                                item_t *new_items_array;
                                int new_items_num = 0;
                                exit = find_items_with_prefix(items_array, items_num, &new_items_array, &new_items_num, argv[2]);
                                if (exit == SUCCESSFUL)
                                {
                                    print_data(new_items_array, new_items_num);
                                    free_array(&new_items_array, new_items_num);
                                }
                            }
                        }
                    }
                    free_array(&items_array, items_num);
                }
                else
                    free_array(&items_array, 0);
            }
            fclose(f);
        }
    }
    else
        exit = INVALID_ARGS;

    return exit;
}
