#include "../inc/main.h"

int main(int argc, char *argv[])
{
    setbuf(stdout, NULL);
    int rc = SUCCESSFUL;
    if (argc != ARGS_AMOUNT)
        rc = INVALID_ARGS;
    else
    {
        FILE *f = fopen(argv[1], "r");
        if (!f)
            rc = FAIL_OPEN_FILE;
        else
        {
            array_t array;
            rc = read_from_file(f, &array);
            if (rc == SUCCESSFUL)
            {
                node_t *head = NULL;
                rc = fill_list(&head, &array);
                if (rc == SUCCESSFUL)
                {
                    rc = delete_max_element_of_list(&head);
                    if (rc == SUCCESSFUL)
                    {
                        FILE *g = fopen(argv[2], "w");
                        if (!g)
                            rc = FAIL_OPEN_FILE;
                        else
                            write_to_file(g, head);
                    }
                }
                free_list(&head);
                free(array.array);
                array.array = NULL;
            }
            fclose(f);
        }
    }

    return rc;
}
