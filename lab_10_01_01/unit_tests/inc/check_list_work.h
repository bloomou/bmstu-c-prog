#ifndef LAB_10_01_01_CHECK_LIST_WORK_H
#define LAB_10_01_01_CHECK_LIST_WORK_H

#include <check.h>
#include <stdlib.h>

#include "../../inc/data_structures.h"
#include "../../inc/list_work.h"
#include "../../inc/io.h"

#define SUCCESSFUL 0
#define FAIL -1

Suite* find_suite(void);

Suite* pop_front_suite(void);

Suite* reverse_suite(void);

Suite* sort_suite(void);

int compare_list_to_array(node_t *head, int *array, int size);

#endif //LAB_10_01_01_CHECK_LIST_WORK_H
