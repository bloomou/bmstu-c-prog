#include "../inc/check_commands.h"

START_TEST(mul_ok)
{
    int num_1 = 30;
    int num_2 = 26;

    node_t *head_1 = NULL;
    node_t *head_2 = NULL;
    node_t *head_result = NULL;

    factorize(num_1, &head_1);
    factorize(num_2, &head_2);
    int rc = multiplication_of_two_lists(head_1, head_2, &head_result);

    free_list(&head_1);
    free_list(&head_2);
    free_list(&head_result);

    ck_assert_int_eq(rc, SUCCESSFUL);
}
END_TEST

Suite* mul_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("mul");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, mul_ok);
    suite_add_tcase(s, tc_pos);

    return s;
}