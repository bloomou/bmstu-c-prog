#include "print_file.h"
#include "main.h"

void command_print_file(FILE *f, int *rc)
{
    if (f != NULL)
    {
        size_t size;
        file_size(f, &size);
        if (size % sizeof(int) == 0 && size > 0)
            *rc = print_int_file(f);
        else
            *rc = EMPTY_FILE;
    }
    else
        *rc = NO_FILE;
}

int print_int_file(FILE *f)
{
    size_t size;
    int num;
    int read;

    int rc = file_size(f, &size);
    if (rc == SUCCESSFUL && size > 0 && size % sizeof(int) == 0)
    {
        for (size_t i = 0; !rc && i < size / sizeof(int); i++)
        {
            read = fread(&num, sizeof(int), 1, f);
            if (read == SUCCESS_READ)
                printf("%d ", num);
            else
                rc = FAIL_READ;
        }
    }
    else
        rc = FAIL_READ;
    return rc;
}

int file_size(FILE *f, size_t *size)
{
    int rc = SUCCESSFUL;
    int sz;
    if (fseek(f, 0, SEEK_END))
        rc = FAIL_SEEK;
    sz = ftell(f);
    if (sz < 0 && rc == SUCCESSFUL)
        rc = FAIL_SEEK;
    else
    {
        *size = sz;
        rc = fseek(f, 0, SEEK_SET);
    }
    return rc;
}
