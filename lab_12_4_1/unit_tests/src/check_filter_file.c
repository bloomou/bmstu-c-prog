#include "../inc/check_filter_file.h"

START_TEST(no_required_nums)
{
    int pb_src[] = { 9 };
    int *pe_src = pb_src + 1;

    int *pb_dst = NULL;
    int *pe_dst = NULL;

    int res = key(pb_src, pe_src, &pb_dst, &pe_dst);

    free_mem_array(&pb_dst, &pe_dst);

    ck_assert_int_eq(res, EMPTY_ARRAY);
}
END_TEST

Suite* key_suite(void)
{
    Suite *s;
    TCase *tc_neg;

    s = suite_create("key");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, no_required_nums);
    suite_add_tcase(s, tc_neg);

    return s;
}