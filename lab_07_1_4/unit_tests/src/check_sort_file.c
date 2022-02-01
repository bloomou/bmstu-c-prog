#include "../inc/check_sort_file.h"

START_TEST(sort_normal)
{
    int arr_1[] = { -7, 9, 5, 0, 2 };
    int len_1 = 5;

    int arr_2[] = { -7, 0, 2, 5, 9 };
    int len_2 = 5;

    mysort(arr_1, len_1, sizeof(int), func_cmp);
    int res = cmp_arrays(arr_1, len_1, arr_2, len_2);


    ck_assert_int_eq(res, SUCCESSFUL);
}
END_TEST

START_TEST(sort_sorted)
{
    int arr_1[] = { 1, 2, 3, 4, 5 };
    int len_1 = 5;

    int arr_2[] = { 1, 2, 3, 4, 5 };
    int len_2 = 5;

    mysort(arr_1, len_1, sizeof(int), func_cmp);
    int res = cmp_arrays(arr_1, len_1, arr_2, len_2);

    ck_assert_int_eq(res, SUCCESSFUL);
}
END_TEST

START_TEST(sort_reversed)
{
    int arr_1[] = { 5, 4, 3, 2, 1 };
    int len_1 = 5;

    int arr_2[] = { 1, 2, 3, 4, 5 };
    int len_2 = 5;

    mysort(arr_1, len_1, sizeof(int), func_cmp);
    int res = cmp_arrays(arr_1, len_1, arr_2, len_2);

    ck_assert_int_eq(res, SUCCESSFUL);
}
END_TEST

START_TEST(sort_one_element)
{
    int arr_1[] = { 7 };
    int len_1 = 1;

    int arr_2[] = { 7 };
    int len_2 = 1;

    mysort(arr_1, len_1, sizeof(int), func_cmp);
    int res = cmp_arrays(arr_1, len_1, arr_2, len_2);

    ck_assert_int_eq(res, SUCCESSFUL);
}
END_TEST

START_TEST(sort_all_equal)
{
    int arr_1[] = { 7, 7, 7 };
    int len_1 = 3;

    int arr_2[] = { 7, 7, 7 };
    int len_2 = 3;

    mysort(arr_1, len_1, sizeof(int), func_cmp);
    int res = cmp_arrays(arr_1, len_1, arr_2, len_2);

    ck_assert_int_eq(res, SUCCESSFUL);
}
END_TEST

Suite* mysort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("mysort");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, sort_normal);
    tcase_add_test(tc_pos, sort_sorted);
    tcase_add_test(tc_pos, sort_reversed);
    tcase_add_test(tc_pos, sort_one_element);
    tcase_add_test(tc_pos, sort_all_equal);
    suite_add_tcase(s, tc_pos);

    return s;
}