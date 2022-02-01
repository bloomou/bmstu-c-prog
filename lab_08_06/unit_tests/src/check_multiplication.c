#include "../inc/check_multiplication.h"

START_TEST(multiplication_of_matrices)
{
    matrix_t matr_1 = {.rows = 3, .columns = 3};
    matrix_t matr_2 = {.rows = 3, .columns = 3};
    matrix_t matr_res = {.rows = 3, .columns = 3};
    alloc_matrix_mem(&matr_1);
    alloc_matrix_mem(&matr_2);
    alloc_matrix_mem(&matr_res);
    int count = 1;
    for (int i = 0; i < matr_1.rows; i++)
    {
        for (int j = 0; j < matr_1.columns; j++)
        {
            matr_1.data[i][j] = count;
            count++;
        }
    }
    matr_2.data[0][0] = 30;
    matr_2.data[0][1] = 36;
    matr_2.data[0][2] = 42;
    matr_2.data[1][0] = 66;
    matr_2.data[1][1] = 81;
    matr_2.data[1][2] = 96;
    matr_2.data[2][0] = 102;
    matr_2.data[2][1] = 126;
    matr_2.data[2][2] = 150;

    multiplication_of_two_matrices(&matr_1, &matr_1, &matr_res);
    int res = cmp_matrices(&matr_2, &matr_res);

    ck_assert_int_eq(res, SUCCESSFUL);
    free_matrix_mem(&matr_1);
    free_matrix_mem(&matr_2);
    free_matrix_mem(&matr_res);
}
END_TEST

Suite* multiplication_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("multiplication");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, multiplication_of_matrices);
    suite_add_tcase(s, tc_pos);

    return s;
}