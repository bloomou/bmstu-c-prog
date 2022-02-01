#include "../inc/multiplication.h"
#include "../inc/memory_work.h"
#include "../inc/io.h"

int read_exponents(int *ro, int *gamma)
{
    int rc = SUCCESSFUL;

    if (fscanf(stdin, "%d%d", ro, gamma) != 2)
        rc = FAIL_INPUT_EXP;
    if (rc == SUCCESSFUL)
    {
        if (*ro < 0 || *gamma < 0)
            rc = FAIL_INPUT_EXP;
    }

    return rc;
}

int multiplication(matrix_t *matrix_1, matrix_t *matrix_2, matrix_t *result)
{
    int rc = SUCCESSFUL;

    int ro, gamma;
    rc = read_exponents(&ro, &gamma);
    if (rc == SUCCESSFUL)
    {
        result->rows = matrix_1->rows;
        result->columns = matrix_1->columns;
        rc = alloc_matrix_mem(result);
        if (rc == SUCCESSFUL)
        {
            if (ro == 0 && gamma == 0)
            {
                fill_unit_matrix(result);
            }
            else if (ro == 0)
            {
                copy_matrix(matrix_2, result);
                for (int i = 0; i < gamma - 1; i++)
                {
                    multiplication_of_two_matrices(result, matrix_2, result);
                }
            }
            else
            {
                copy_matrix(matrix_1, result);
                for (int i = 0; i < ro - 1; i++)
                {
                    multiplication_of_two_matrices(result, matrix_1, result);
                }
                for (int i = 0; i < gamma; i++)
                {
                    multiplication_of_two_matrices(result, matrix_2, result);
                }
            }
        }
    }

    return rc;
}

void copy_matrix(matrix_t *src, matrix_t *dst)
{
    for (int i = 0; i < src->rows; i++)
    {
        for (int j = 0; j < src->columns; j++)
        {
            dst->data[i][j] = src->data[i][j];
        }
    }
}

void fill_unit_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            if (i == j)
                matrix->data[i][j] = 1;
            else
                matrix->data[i][j] = 0;
        }
    }
}

int multiplication_of_two_matrices(matrix_t *matrix_1, matrix_t *matrix_2, matrix_t *result)
{
    int rc = SUCCESSFUL;

    int *temp_row = (int *) calloc(matrix_1->columns, sizeof(int));
    if (!temp_row)
        rc = FAIL_ALLOC;

    if (rc == SUCCESSFUL)
    {
        for (int i = 0; i < result->rows; i++)
        {
            for (int j = 0; j < result->columns; j++)
            {
                int sum = 0;
                for (int k = 0; k < matrix_1->rows; k++)
                {
                    sum += matrix_1->data[i][k] * matrix_2->data[k][j];
                }
                temp_row[j] = sum;
            }
            for (int k = 0; k < result->rows; k++)
            {
                result->data[i][k] = temp_row[k];
            }
        }
        free(temp_row);
        temp_row = NULL;
    }

    return rc;
}