#include "../inc/matrix_conversion.h"
#include "../inc/memory_work.h"
#include "../inc/io.h"

void find_min_element_of_matrix(matrix_t *matrix, int *row_index, int *column_index)
{
    int min = matrix->data[0][0];
    *row_index = 0;
    *column_index = 0;

    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            if (matrix->data[i][j] <= min)
            {
                min = matrix->data[i][j];
                *row_index = i;
                *column_index = j;
            }
        }
    }
}

int delete_row(matrix_t *matrix)
{
    int rc = SUCCESSFUL;

    int row, column;
    find_min_element_of_matrix(matrix, &row, &column);
    free(matrix->data[row]);
    for (int i = row; i < matrix->rows - 1; i++)
    {
        matrix->data[i] = matrix->data[i + 1];
    }

    int **new_data = (int **) realloc(matrix->data, sizeof(int *) * (matrix->rows - 1));
    if (!new_data)
    {
        rc = FAIL_ALLOC;
        free_matrix_mem(matrix);
    }

    if (rc == SUCCESSFUL)
    {
        matrix->data = new_data;
        matrix->rows--;
    }

    return rc;
}

int delete_column(matrix_t *matrix)
{
    int rc = SUCCESSFUL;

    int row, column;
    find_min_element_of_matrix(matrix, &row, &column);

    for (int i = 0; i < matrix->rows && rc == SUCCESSFUL; i++)
    {
        for (int j = column; j < matrix->columns - 1; j++)
        {
            matrix->data[i][j] = matrix->data[i][j + 1];
        }
        int *new_data_i = (int *) realloc(matrix->data[i], sizeof(int) * (matrix->columns - 1));
        if (!new_data_i)
        {
            rc = FAIL_ALLOC;
            free_matrix_mem(matrix);
        }

        if (rc == SUCCESSFUL)
            matrix->data[i] = new_data_i;
    }
    if (rc == SUCCESSFUL)
        matrix->columns--;

    return rc;
}

int find_geometric_mean_of_column(matrix_t *matrix, int column_ind)
{
    int product = 1;
    for (int i = 0; i < matrix->rows; i++)
    {
        if (matrix->data[i][column_ind] < 0)
            product *= matrix->data[i][column_ind] * (-1);
        else
            product *= matrix->data[i][column_ind];
    }

    return (int) pow((double) product, (double) 1 / (double) matrix->rows);
}

int find_min_element_of_row(matrix_t *matrix, int row_ind)
{
    int min = matrix->data[row_ind][0];
    for (int j = 1; j < matrix->columns; j++)
    {
        if (matrix->data[row_ind][j] < min)
            min = matrix->data[row_ind][j];
    }

    return min;
}

int add_row(matrix_t *matrix)
{
    int rc = SUCCESSFUL;

    int **new_data = (int **) realloc(matrix->data, sizeof(int *) * (matrix->rows + 1));
    if (!new_data)
    {
        rc = FAIL_ALLOC;
        free_matrix_mem(matrix);
    }

    if (rc == SUCCESSFUL)
    {
        matrix->data = new_data;

        int *new_data_i = calloc(sizeof(int), matrix->columns);
        if (!new_data_i)
        {
            rc = FAIL_ALLOC;
            free_matrix_mem(matrix);
        }

        if (rc == SUCCESSFUL)
        {
            matrix->data[matrix->rows] = new_data_i;
            for (int j = 0; j < matrix->columns; j++)
            {
                matrix->data[matrix->rows][j] = find_geometric_mean_of_column(matrix, j);
            }
            matrix->rows++;
        }
    }

    return rc;
}

int add_column(matrix_t *matrix)
{
    int rc = SUCCESSFUL;

    for (int i = 0; i < matrix->rows && rc == SUCCESSFUL; i++)
    {
        int *new_data_i = (int *) realloc(matrix->data[i], sizeof(int) * (matrix->columns + 1));
        if (!new_data_i)
        {
            rc = FAIL_ALLOC;
            free_matrix_mem(matrix);
        }

        if (rc == SUCCESSFUL)
        {
            matrix->data[i] = new_data_i;
            matrix->data[i][matrix->columns] = find_min_element_of_row(matrix, i);
        }
    }
    if (rc == SUCCESSFUL)
        matrix->columns++;

    return rc;
}

int to_square(matrix_t *matrix)
{
    int rc = SUCCESSFUL;
    int dif = abs(matrix->columns - matrix->rows);
    for (int i = 0; i < dif && rc == SUCCESSFUL; i++)
    {
        if (matrix->rows < matrix->columns)
            rc = delete_column(matrix);
        if (matrix->rows > matrix->columns)
            rc = delete_row(matrix);
    }

    return rc;
}

int to_one_size(matrix_t *matrix_1, matrix_t *matrix_2)
{
    int rc = SUCCESSFUL;
    if (matrix_1->rows < matrix_2->rows)
    {
        int dif = matrix_2->rows - matrix_1->rows;
        for (int i = 0; i < dif && rc == SUCCESSFUL; i++)
        {
            rc = add_row(matrix_1);
        }
        for (int i = 0; i < dif && rc == SUCCESSFUL; i++)
        {
            rc = add_column(matrix_1);
        }
    }
    if (matrix_1->rows > matrix_2->rows)
    {
        int dif = matrix_1->rows - matrix_2->rows;
        for (int i = 0; i < dif && rc == SUCCESSFUL; i++)
        {
            rc = add_row(matrix_2);
        }
        for (int i = 0; i < dif && rc == SUCCESSFUL; i++)
        {
            rc = add_column(matrix_2);
        }
    }

    return rc;
}