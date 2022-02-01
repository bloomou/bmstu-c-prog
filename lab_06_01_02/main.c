#include "main.h"
#include "read_print_structs.h"
#include "sort_structs.h"
#include "filter_structs.h"

int main(int argc, char **argv)
{
    int exit = SUCCESSFUL;
    item items_array[MAX_NUM] = { 0 };
    int items_num = 0;
    if (argc == 2 || argc == 3)
    {
        exit = read_structs(argv[1], items_array, &items_num);
        if (exit == SUCCESSFUL)
        {
            if (argc == 2)
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
                    item new_items_array[MAX_NUM] = { 0 };
                    int new_items_num = 0;
                    filter_structs(items_array, items_num, new_items_array, &new_items_num, argv[2]);
                    print_data(new_items_array, new_items_num);
                }
            }
        }
    }
    else
        exit = INVALID_ARGS;
    return exit;
}
