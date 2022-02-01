#include "../inc/io_file.h"

int allocate_mem_array(int num_of_elements, int **pb)
{
    int rc = SUCCESSFUL;
    *pb = (int *) calloc(num_of_elements, sizeof(int));
    if (!(*pb))
        rc = FAIL_MEM_ALLOC;
    
    return rc;
}

void free_mem_array(int **pb, int **pe)
{
    free(*pb);
    *pb = NULL;
    *pe = NULL;
}

int count_numbers_in_file(char *file_name, int *count_nums)
{
    int rc = SUCCESSFUL;
    FILE *f;

    f = fopen(file_name, "r");
    if (f == NULL)
        rc = NO_FILE;
    else
    {
        while (!feof(f) && rc == SUCCESSFUL)
        {
            int current;
            if (fscanf(f, "%d", &current) != 1)
                rc = FAIL_READ;
            (*count_nums)++;
        }
        fclose(f);
    }
    
    return rc;
}

int read_elements_from_file(char *file_name, int *pb, int *pe)
{
    int rc = SUCCESSFUL;
    FILE *f;

    f = fopen(file_name, "r");
    if (f == NULL)
        rc = NO_FILE;
    else
    {
        int *begin = pb;
        int *end = pe;
        while (begin < end && rc == SUCCESSFUL)
        {
            if (fscanf(f, "%d", begin++) != 1)
                rc = FAIL_READ;
        }
        fclose(f);
    }
    
    return rc;
}

int write_elements_into_file(char *file_name, int *pb, int *pe)
{
    int rc = SUCCESSFUL;
    FILE *f;
    f = fopen(file_name, "w");
    if (f == NULL)
        rc = NO_FILE;
    else
    {
        int *begin = pb;
        int *end = pe;
        while (begin < end)
            fprintf(f, "%d ", *(begin++));
        fclose(f);
    }
    
    return rc;
}