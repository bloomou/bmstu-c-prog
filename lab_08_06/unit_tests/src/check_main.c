#include "../inc/check_main.h"
#include "../inc/check_io.h"
#include "../inc/check_matrix_conversion.h"
#include "../inc/check_multiplication.h"

int main(void)
{
    int no_failed = 0;
    SRunner *runner;

    runner = srunner_create(multiplication_suite());
    srunner_add_suite(runner, to_one_size_suite());
    srunner_add_suite(runner, to_square_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int cmp_matrices(matrix_t *matrix_1, matrix_t *matrix_2)
{
    if (matrix_1->rows != matrix_2->rows || matrix_1->columns != matrix_2->columns)
        return FAIL_CMP;
    for (int i = 0; i < matrix_1->rows; i++)
    {
        for (int j = 0; j < matrix_1->columns; j++)
        {
            if (matrix_1->data[i][j] != matrix_2->data[i][j])
                return FAIL_CMP;
        }
    }
    return SUCCESSFUL;
}