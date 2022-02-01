#include "../inc/check_sort_structs.h"

START_TEST(sort_ok)
{
    int items_num = 5;
    item_t items_array[5] = { 0 };
    items_array[0].title = "pen";
    items_array[0].mass = 0.2;
    items_array[0].volume = 0.001;
    items_array[1].title = "pencil";
    items_array[1].mass = 0.1;
    items_array[1].volume = 0.001;
    items_array[2].title = "table";
    items_array[2].mass = 10;
    items_array[2].volume = 0.5;

    bubble_sort_structs(items_array, items_num);

    int res = FAIL;
    if (strcmp(items_array[0].title, "table") == 0 &&
    strcmp(items_array[1].title, "pencil") == 0 && strcmp(items_array[2].title, "pen") == 0 &&
    items_array[0].mass == 10 && items_array[0].volume == 0.5 &&
    items_array[1].mass == 0.1 && items_array[1].volume == 0.001 &&
    items_array[2].mass == 0.2 && items_array[2].volume == 0.001)
        res = SUCCESSFUL;

    ck_assert_int_eq(res, SUCCESSFUL);
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