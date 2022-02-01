#include "new_file.h"
#include "main.h"

void command_create_file(FILE *f, int *rc, int number)
{
    if (f != NULL)
        *rc = create_file_from_rand_nums(f, number);
    else
        *rc = COULD_NOT_CREATE_FILE;
}

int create_file_from_rand_nums(FILE *f, int num)
{
    int rc = SUCCESSFUL;
    int wrote;
    for (int i = 0; i < num; i++)
    {
        int random_number = get_rand_from_range(MIN, MAX);
        wrote = fwrite(&random_number, sizeof(int), 1, f);
        if (wrote != SUCCESS_WRITE)
            rc = FAIL_WRITE;
    }
    return rc;
}

int get_rand_from_range(const int min, const int max)
{
    return rand() % (max - min + 1) + min;
}
