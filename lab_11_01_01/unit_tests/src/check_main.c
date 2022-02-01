#include "../inc/check_main.h"

int main(void)
{
    int no_failed = 0;
    SRunner *runner;

    runner = srunner_create(s_suite());
    srunner_add_suite(runner, c_suite());
    srunner_add_suite(runner, d_suite());
    srunner_add_suite(runner, x_suite());
    srunner_add_suite(runner, all_suite());
    srunner_run_all(runner, CK_VERBOSE);
    no_failed = srunner_ntests_failed(runner);

    srunner_free(runner);

    return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
