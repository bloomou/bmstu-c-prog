#include "../inc/io.h"

int read_cmd(char *cmd)
{
    int rc = SUCCESSFUL;

    if (scanf("%s", cmd) != 1)
        rc = FAIL_READ;
    else
    {
        if (cmd[3] != '\0')
            rc = INVALID_CMD;
        if (strncmp(cmd, "out", CMD_LEN) && strncmp(cmd, "mul", CMD_LEN)
            && strncmp(cmd, "sqr", CMD_LEN) && strncmp(cmd, "div", CMD_LEN))
            rc = INVALID_CMD;
    }

    return rc;
}

int read_number(int *num)
{
    int rc = SUCCESSFUL;

    if (scanf("%d", num) != 1)
        rc = FAIL_READ;
    else if (*num <= 0)
        rc = INVALID_NUM;

    return rc;
}

void print_list(node_t *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("L\n");
}