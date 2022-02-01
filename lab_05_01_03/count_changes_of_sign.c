#include "count_changes_of_sign.h"

int create_int_file(FILE *f)
{
    int number;
    int rc = SUCCESSFUL;

    printf("Input integers:\n");
    while (!rc && scanf("%d", &number) == 1)
        fprintf(f, "%d ", number);
    fprintf(f, "\n");
    return rc;
}

int process(FILE *f, int *count)
{
    int rc = ONE_ELEMENT;
    int num;
    int prev;
    if (fscanf(f, "%d", &prev) == 1)
    {
        while (fscanf(f, "%d", &num) == 1)
        {
            rc = SUCCESSFUL;
            if ((prev * num < 0) || (prev == 0 && num < 0) || (prev < 0 && num == 0))
                (*count)++;
            prev = num;
        }
    }
    else
        rc = FAIL_READ;
    return rc;
}
