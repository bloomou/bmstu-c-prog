#include "sort_file.h"
#include "main.h"

void command_sort_file(FILE *f, int *rc)
{
    if (f != NULL)
    {
        size_t size;
        file_size(f, &size);
        if (size % sizeof(int) == 0 && size > 0)
            *rc = bubble_sort(f);
        else
            *rc = EMPTY_FILE;
    }
    else
        *rc = NO_FILE;
}

int bubble_sort(FILE *f)
{
    size_t size;

    int rc = file_size(f, &size);
    if (rc == SUCCESSFUL && size > 0 && size % sizeof(int) == 0)
    {
        for (size_t i = 0; i < size / sizeof(int); i++)
            for (size_t j = 0; j < size / sizeof(int) - i - 1; j++)
            {
                int result_1;
                int result_2;
                get_number_by_pos(f, j, size, &result_1);
                get_number_by_pos(f, j + 1, size, &result_2);
                if (result_1 > result_2)
                    swap(f, j, j + 1, size);
            }
    }
    else
        rc = FAIL_SORT;
    return rc;
}

int get_number_by_pos(FILE *f, size_t pos, size_t size, int *result)
{
    int rc = SUCCESSFUL;
    if (pos < size)
    {
        fseek(f, pos * sizeof(int), SEEK_SET);
        if (fread(result, sizeof(int), 1, f) != 1)
            rc = NO_INTEGER;
    }
    else
        rc = WRONG_ACCESS;
    return rc;
}

int put_number_by_pos(FILE *f, size_t pos, size_t size, int number)
{
    int rc = SUCCESSFUL;
    if (pos < size)
    {
        fseek(f, pos * sizeof(int), SEEK_SET);
        fwrite(&number, sizeof(int), 1, f);
        fseek(f, pos * sizeof(int), SEEK_SET);
    }
    else
        rc = WRONG_ACCESS;
    return rc;
}

void swap(FILE *f, int pos_1, int pos_2, size_t size)
{
    int tmp1;
    int tmp2;
    get_number_by_pos(f, pos_1, size, &tmp1);
    get_number_by_pos(f, pos_2, size, &tmp2);
    put_number_by_pos(f, pos_1, size, tmp2);
    put_number_by_pos(f, pos_2, size, tmp1);
}
