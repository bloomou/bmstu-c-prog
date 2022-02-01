#include "../inc/main.h"
#include "../inc/io_file.h"
#include "../inc/sort_file.h"
#include "../inc/filter_file.h"

int main(int argc, char *argv[])
{
    int rc = SUCCESSFUL;
    if (argc != ARGS_AMOUNT_NO_FILTER && argc != ARGS_AMOUNT_FILTER)
        rc = INVALID_ARGC;
    else
    {
        int n = 0;
        rc = count_numbers_in_file(argv[1], &n);
        if (rc == SUCCESSFUL)
        {
            int *pb = NULL;
            rc = allocate_mem_array(n, &pb);
            if (rc == SUCCESSFUL)
            {
                int *pe = pb + n;
                rc = read_elements_from_file(argv[1], pb, pe);
                if (rc == SUCCESSFUL)
                {
                    if (argc == ARGS_AMOUNT_FILTER && strcmp(argv[3], FILTER) == 0)
                        rc = command_filter(pb, pe, argv[2]);
                    else if (argc == ARGS_AMOUNT_NO_FILTER)
                    {
                        mysort(pb, pe - pb, sizeof(int), func_cmp);
                        rc = write_elements_into_file(argv[2], pb, pe);
                    }
                    else
                        rc = INVALID_ARGS;
                }
                free_mem_array(&pb, &pe);
            }
        }
    }
    
    return rc;
}
