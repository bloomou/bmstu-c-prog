#include "../inc/check_main.h"
#include "../inc/check_io_file.h"
#include "../inc/check_filter_file.h"
#include "../inc/check_sort_file.h"

int main(void)
{
    int no_failed = 0;
    SRunner *runner;

    runner = srunner_create(mysort_suite());
    srunner_add_suite(runner, key_suite());

    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int cmp_arrays(int *arr_1, int len_1, int *arr_2, int len_2)
{
    if (len_1 != len_2)
        return FAIL_CMP;
    for (int i = 0; i < len_1; i++)
    {
        if (arr_1[i] != arr_2[i])
            return FAIL_CMP;
    }
    return SUCCESSFUL;
}