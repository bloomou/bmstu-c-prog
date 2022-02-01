#include "../inc/check_list_work.h"

START_TEST(find_ok)
{
    array_t arr;

    arr.array = malloc(4 * sizeof(int));

    arr.count = 4;
    arr.array[0] = 7;
    arr.array[1] = 2;
    arr.array[2] = 6;
    arr.array[3] = 0;

    node_t *head = NULL;

    int rc = fill_list(&head, &arr);
    if (rc == SUCCESSFUL)
    {
        int test = 2;
        node_t *node = find(head, (const void *) &test, comparator);
        if (*((int *)node->data) == test)
            rc = SUCCESSFUL;
        free_list(&head);
        free(arr.array);
        arr.array = NULL;
    }

    ck_assert_int_eq(rc, SUCCESSFUL);
}
END_TEST

Suite* find_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("find");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, find_ok);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(pop_front_ok)
{
    array_t arr;

    arr.array = malloc(4 * sizeof(int));

    arr.count = 4;
    arr.array[0] = 7;
    arr.array[1] = 2;
    arr.array[2] = 6;
    arr.array[3] = 0;

    node_t *head = NULL;

    int rc = fill_list(&head, &arr);
    if (rc == SUCCESSFUL)
    {
        pop_front(&head);
        int popped_arr[3] = {6, 2, 7};
        rc = compare_list_to_array(head, popped_arr, arr.count - 1);

        free_list(&head);
        free(arr.array);
        arr.array = NULL;
    }

    ck_assert_int_eq(rc, SUCCESSFUL);
}
END_TEST

Suite* pop_front_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("pop_front");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, pop_front_ok);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(reverse_ok)
{
    array_t arr;

    arr.array = malloc(4 * sizeof(int));

    arr.count = 4;
    arr.array[0] = 7;
    arr.array[1] = 2;
    arr.array[2] = 6;
    arr.array[3] = 0;

    node_t *head = NULL;

    int rc = fill_list(&head, &arr);
    if (rc == SUCCESSFUL)
    {
        head = reverse(head);
        int sorted_arr[4] = {7, 2, 6, 0};
        rc = compare_list_to_array(head, sorted_arr, arr.count);

        free_list(&head);
        free(arr.array);
        arr.array = NULL;
    }

    ck_assert_int_eq(rc, SUCCESSFUL);
}
END_TEST

Suite* reverse_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("reverse");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, reverse_ok);
    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(sort_ok)
{
    array_t arr;

    arr.array = malloc(4 * sizeof(int));

    arr.count = 4;
    arr.array[0] = 7;
    arr.array[1] = 2;
    arr.array[2] = 6;
    arr.array[3] = 0;

    node_t *head = NULL;

    int rc = fill_list(&head, &arr);
    if (rc == SUCCESSFUL)
    {
        head = sort(head, comparator);
        int sorted_arr[4] = {0, 2, 6, 7};
        rc = compare_list_to_array(head, sorted_arr, arr.count);

        free_list(&head);
        free(arr.array);
        arr.array = NULL;
    }

    ck_assert_int_eq(rc, SUCCESSFUL);
}
END_TEST

Suite* sort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("sort");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, sort_ok);
    suite_add_tcase(s, tc_pos);

    return s;
}

int compare_list_to_array(node_t *head, int *array, int size)
{
    int i = 0;
    while (head)
    {
        if (size > 0 && *((int *) head->data) != array[i++])
            return FAIL;
        head = head->next;
        size--;
    }
    if (size)
        return FAIL;

    return SUCCESSFUL;
}
