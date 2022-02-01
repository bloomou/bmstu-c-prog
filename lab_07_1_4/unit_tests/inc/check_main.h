#ifndef LAB_07_1_4_CHECK_MAIN_H
#define LAB_07_1_4_CHECK_MAIN_H

#include <check.h>
#include <stdlib.h>

#include "../../inc/io_file.h"
#include "../../inc/filter_file.h"
#include "../../inc/sort_file.h"

#define SUCCESSFUL 0
#define EMPTY_ARRAY -1
#define FAIL_CMP -2

int cmp_arrays(int *arr_1, int len_1, int *arr_2, int len_2);

#endif //LAB_07_1_4_CHECK_MAIN_H
