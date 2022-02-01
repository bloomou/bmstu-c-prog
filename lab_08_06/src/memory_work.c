#include "../inc/memory_work.h"

int alloc_matrix_mem(matrix_t *matrix)
{
    int rc = SUCCESSFUL;
    matrix->data = (int **) calloc(matrix->rows, sizeof(int *));
    if (!matrix->data)
        rc = FAIL_ALLOC;

    for (int i = 0; i < matrix->rows && rc == SUCCESSFUL; i++)
    {
        matrix->data[i] = (int *) calloc(matrix->columns, sizeof(int));
        if (!matrix->data[i])
        {
            rc = FAIL_ALLOC;
            free_matrix_mem(matrix);
        }
    }

    return rc;
}

void free_matrix_mem(matrix_t *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        free(matrix->data[i]);
        matrix->data[i] = NULL;
    }
    free(matrix->data);
    matrix->data = NULL;
}
