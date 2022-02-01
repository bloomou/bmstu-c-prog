#include "../inc/main.h"

int main(void)
{
    setbuf(stdout, NULL);
    int rc = SUCCESSFUL;

    char cmd[CMD_LEN] = { 0 };
    rc = read_cmd(cmd);
    if (rc == SUCCESSFUL)
    {
        int num_1 = 0, num_2 = 0;
        rc = read_number(&num_1);
        if (rc == SUCCESSFUL)
        {
            if (!strcmp(cmd, "mul") || !strcmp(cmd, "div"))
            {
                rc = read_number(&num_2);
                if (rc == SUCCESSFUL)
                {
                    node_t *head_1 = NULL;
                    node_t *head_2 = NULL;
                    node_t *head_result = NULL;

                    factorize(num_1, &head_1);
                    factorize(num_2, &head_2);
                    if (!strcmp(cmd, "mul"))
                        rc = multiplication_of_two_lists(head_1, head_2, &head_result);
                    if (!strcmp(cmd, "div"))
                        rc = division_without_remainder(head_1, head_2, &head_result);

                    free_list(&head_1);
                    free_list(&head_2);
                    free_list(&head_result);
                }
            }
            else
            {
                node_t *head = NULL;
                factorize(num_1, &head);
                if (!strcmp(cmd, "sqr"))
                    squaring(&head);
                print_list(head);
                free_list(&head);
            }
        }
    }

    return rc;
}
