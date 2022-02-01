#include "../inc/check_my_snprintf.h"

START_TEST(snprintf_s_1)
{
    int res = FAIL_CMP;

    char buf_1[50] = { 0 };
    char buf_2[50] = { 0 };
    size_t n = 48;
    char str[50] = "my new str!";

    int res_1 = snprintf(buf_1, n, "this is %s", str);
    int res_2 = my_snprintf(buf_2, n, "this is %s", str);

    if (strcmp(buf_1, buf_2) == 0 && res_1 == res_2)
        res = SUCCESSFUL;
    else
        res = FAIL_CMP;

    ck_assert_int_eq(res, SUCCESSFUL);
}
END_TEST

START_TEST(snprintf_s_2)
{
    int res = FAIL_CMP;

    char buf_1[50] = { 0 };
    char buf_2[50] = { 0 };
    size_t n = 48;
    char str[50] = "my new long long long str!";

    int res_1 = snprintf(buf_1, n, "this is %s and %s", str, str);
    int res_2 = my_snprintf(buf_2, n, "this is %s and %s", str, str);

    if (strcmp(buf_1, buf_2) == 0 && res_1 == res_2)
        res = SUCCESSFUL;
    else
        res = FAIL_CMP;

    ck_assert_int_eq(res, SUCCESSFUL);
}
END_TEST

START_TEST(snprintf_s_3)
{
    int res = FAIL_CMP;

    char buf_1[50] = { 0 };
    char buf_2[50] = { 0 };
    size_t n = 0;
    char str[50] = "my new str!";

    int res_1 = snprintf(buf_1, n, "this is %s and %s", str, str);
    int res_2 = my_snprintf(buf_2, n, "this is %s and %s", str, str);

    if (strcmp(buf_1, buf_2) == 0 && res_1 == res_2)
        res = SUCCESSFUL;
    else
        res = FAIL_CMP;

    ck_assert_int_eq(res, SUCCESSFUL);
}
END_TEST

Suite* s_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("snprintf_s");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, snprintf_s_1);
    tcase_add_test(tc_pos, snprintf_s_2);
    tcase_add_test(tc_pos, snprintf_s_3);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(snprintf_c)
{
    int res = FAIL_CMP;

    char buf_1[50] = { 0 };
    char buf_2[50] = { 0 };
    size_t n = 30;

    int res_1 = snprintf(buf_1, n, "hi it's m%c%c%c", 'e', '!', '\n');
    int res_2 = my_snprintf(buf_2, n, "hi it's m%c%c%c", 'e', '!', '\n');

    if (strcmp(buf_1, buf_2) == 0 && res_1 == res_2)
        res = SUCCESSFUL;
    else
        res = FAIL_CMP;

    ck_assert_int_eq(res, SUCCESSFUL);
}
END_TEST

Suite* c_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("snprintf_c");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, snprintf_c);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(snprintf_d_1)
{
    int res = FAIL_CMP;

    char buf_1[50] = { 0 };
    char buf_2[50] = { 0 };
    size_t n = 30;

    int res_1 = snprintf(buf_1, n, "%d + %d, %d", 5, 5, -99999);
    int res_2 = my_snprintf(buf_2, n, "%d + %d, %d", 5, 5, -99999);

    if (strcmp(buf_1, buf_2) == 0 && res_1 == res_2)
        res = SUCCESSFUL;
    else
        res = FAIL_CMP;

    ck_assert_int_eq(res, SUCCESSFUL);
}
END_TEST

START_TEST(snprintf_d_2)
{
    int res = FAIL_CMP;

    char buf_1[50] = { 0 };
    char buf_2[50] = { 0 };
    size_t n = 30;

    int res_1 = snprintf(buf_1, n, "%d - %d - %d = %d", -15, 15, 10, -15 - 15 - 10);
    int res_2 = my_snprintf(buf_2, n, "%d - %d - %d = %d", -15, 15, 10, -15 - 15 - 10);

    if (strcmp(buf_1, buf_2) == 0 && res_1 == res_2)
        res = SUCCESSFUL;
    else
        res = FAIL_CMP;

    ck_assert_int_eq(res, SUCCESSFUL);
}
END_TEST

START_TEST(snprintf_d_3)
{
    int res = FAIL_CMP;

    char buf_1[35] = { 0 };
    char buf_2[35] = { 0 };
    size_t n = 30;

    int res_1 = snprintf(buf_1, n, "some numbers: %d, %d, %d, %d", INT_MIN, -1, 0, -INT_MAX);
    int res_2 = my_snprintf(buf_2, n, "some numbers: %d, %d, %d, %d", INT_MIN, -1, 0, -INT_MAX);

    if (strcmp(buf_1, buf_2) == 0 && res_1 == res_2)
        res = SUCCESSFUL;
    else
        res = FAIL_CMP;

    ck_assert_int_eq(res, SUCCESSFUL);
}
END_TEST

Suite* d_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("snprintf_d");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, snprintf_d_1);
    tcase_add_test(tc_pos, snprintf_d_2);
    tcase_add_test(tc_pos, snprintf_d_3);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(snprintf_x)
{
    int res = FAIL_CMP;

    char buf_1[50] = { 0 };
    char buf_2[50] = { 0 };
    size_t n = 30;

    int res_1 = snprintf(buf_1, n, "some numbers: %x, %x, %x, %x", -19999, -1, 0, 123456789);
    int res_2 = my_snprintf(buf_2, n, "some numbers: %x, %x, %x, %x", -19999, -1, 0, 123456789);

    if (strcmp(buf_1, buf_2) == 0 && res_1 == res_2)
        res = SUCCESSFUL;
    else
        res = FAIL_CMP;

    ck_assert_int_eq(res, SUCCESSFUL);
}
END_TEST

Suite* x_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("snprintf_x");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, snprintf_x);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(snprintf_all)
{
    int res = FAIL_CMP;

    char buf_1[50] = { 0 };
    char buf_2[50] = { 0 };
    size_t n = 30;
    char str[50] = "my str!";

    int res_1 = snprintf(buf_1, n, "[%x] [%d] [%s] [%c]", -19999, -1, str, '?');
    int res_2 = my_snprintf(buf_2, n, "[%x] [%d] [%s] [%c]", -19999, -1, str, '?');

    if (strcmp(buf_1, buf_2) == 0 && res_1 == res_2)
        res = SUCCESSFUL;
    else
        res = FAIL_CMP;

    ck_assert_int_eq(res, SUCCESSFUL);
}
END_TEST

Suite* all_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("snprintf_all");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, snprintf_all);
    suite_add_tcase(s, tc_pos);

    return s;
}