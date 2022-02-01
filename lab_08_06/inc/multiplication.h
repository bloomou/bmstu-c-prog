#ifndef LAB_08_06_MULTIPLICATION_H
#define LAB_08_06_MULTIPLICATION_H

#include <stdio.h>

#include "../inc/main.h"

int multiplication(matrix_t *matrix_1, matrix_t *matrix_2, matrix_t *result);

void fill_unit_matrix(matrix_t *matrix);

int read_exponents(int *ro, int *gamma);

int multiplication_of_two_matrices(matrix_t *matrix_1, matrix_t *matrix_2, matrix_t *result);

void copy_matrix(matrix_t *src, matrix_t *dst);

#endif //LAB_08_06_MULTIPLICATION_H
