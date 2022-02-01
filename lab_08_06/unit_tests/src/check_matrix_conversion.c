#include "../inc/check_matrix_conversion.h"

START_TEST(more_rows)
{
    matrix_t matr = {.rows = 3, .columns = 2};
    matrix_t matr_res = {.rows = 2, .columns = 2};
    alloc_matrix_mem(&matr);
    alloc_matrix_mem(&matr_res);
    int count = 1;
    for (int i = 0; i < matr.rows; i++)
    {
        for (int j = 0; j < matr.columns; j++)
        {
            matr.data[i][j] = count;
            count++;
        }
    }
    matr_res.data[0][0] = 3;
    matr_res.data[0][1] = 4;
    matr_res.data[1][0] = 5;
    matr_res.data[1][1] = 6;

    to_square(&matr);
    int res = cmp_matrices(&matr, &matr_res);

    ck_assert_int_eq(res, SUCCESSFUL);
    free_matrix_mem(&matr);
    free_matrix_mem(&matr_res);
}
END_TEST

START_TEST(more_columns)
{
    matrix_t matr = {.rows = 2, .columns = 3};
    matrix_t matr_res = {.rows = 2, .columns = 2};
    alloc_matrix_mem(&matr);
    alloc_matrix_mem(&matr_res);
    int count = 1;
    for (int i = 0; i < matr.rows; i++)
    {
        for (int j = 0; j < matr.columns; j++)
        {
            matr.data[i][j] = count;
            count++;
        }
    }
    matr_res.data[0][0] = 2;
    matr_res.data[0][1] = 3;
    matr_res.data[1][0] = 5;
    matr_res.data[1][1] = 6;

    to_square(&matr);
    int res = cmp_matrices(&matr, &matr_res);

    ck_assert_int_eq(res, SUCCESSFUL);
    free_matrix_mem(&matr);
    free_matrix_mem(&matr_res);
}
END_TEST

Suite* to_square_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("to_square");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, more_rows);
    tcase_add_test(tc_pos, more_columns);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(matrices_to_one_size)
{
    matrix_t matr_1 = {.rows = 3, .columns = 3};
    matrix_t matr_2 = {.rows = 2, .columns = 2};
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
    count = 1;
    for (int i = 0; i < matr_2.rows; i++)
    {
        for (int j = 0; j < matr_2.columns; j++)
        {
            matr_2.data[i][j] = count;
            count++;
        }
    }
    matr_res.data[0][0] = 1;
    matr_res.data[0][1] = 2;
    matr_res.data[0][2] = 1;
    matr_res.data[1][0] = 3;
    matr_res.data[1][1] = 4;
    matr_res.data[1][2] = 3;
    matr_res.data[2][0] = 1;
    matr_res.data[2][1] = 2;
    matr_res.data[2][2] = 1;

    to_one_size(&matr_1, &matr_2);
    int res = cmp_matrices(&matr_2, &matr_res);

    ck_assert_int_eq(res, SUCCESSFUL);
    free_matrix_mem(&matr_1);
    free_matrix_mem(&matr_2);
    free_matrix_mem(&matr_res);
}
END_TEST

Suite* to_one_size_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("to_one_size");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, matrices_to_one_size);
    suite_add_tcase(s, tc_pos);

    return s;
}