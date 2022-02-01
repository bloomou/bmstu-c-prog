#include "../inc/io.h"

int read_matrix(matrix_t *matrix)
{
    int rc = SUCCESSFUL;
    if (fscanf(stdin, "%d%d", &matrix->rows, &matrix->columns) != 2)
        rc = FAIL_INPUT_SIZE;
    if (rc == SUCCESSFUL)
    {
        if (matrix->rows < 1 || matrix->columns < 1)
        {
            rc = FAIL_INPUT_SIZE;
        }
        if (rc == SUCCESSFUL)
        {
            rc = alloc_matrix_mem(matrix);
            if (rc == SUCCESSFUL)
            {
                for (int i = 0; i < matrix->rows && rc == SUCCESSFUL; i++)
                {
                    for (int j = 0; j < matrix->columns && rc == SUCCESSFUL; j++)
                    {
                        if (fscanf(stdin, "%d", matrix->data[i] + j) != 1)
                        {
                            rc = FAIL_INPUT_ELEMENT;
                        }
                    }
                    if (rc == FAIL_INPUT_ELEMENT)
                        free_matrix_mem(matrix);
                }
            }
        }
    }

    return rc;
}

void print_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            printf("%20d", matrix->data[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}