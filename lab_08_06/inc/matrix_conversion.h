#ifndef LAB_08_06_MATRIX_CONVERT_H
#define LAB_08_06_MATRIX_CONVERT_H

#include <math.h>

#include "../inc/main.h"

void find_min_element_of_matrix(matrix_t *matrix, int *row_index, int *column_index);

int delete_row(matrix_t *matrix);

int delete_column(matrix_t *matrix);

int add_row(matrix_t *matrix);

int add_column(matrix_t *matrix);

int find_geometric_mean_of_column(matrix_t *matrix, int column_ind);

int find_min_element_of_row(matrix_t *matrix, int row_ind);

int to_square(matrix_t *matrix);

int to_one_size(matrix_t *matrix_1, matrix_t *matrix_2);

#endif //LAB_08_06_MATRIX_CONVERT_H
