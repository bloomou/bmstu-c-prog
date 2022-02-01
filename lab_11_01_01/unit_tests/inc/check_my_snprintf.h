#ifndef LAB_10_01_01_CHECK_MY_SNPRINTF_H
#define LAB_10_01_01_CHECK_MY_SNPRINTF_H

#include <check.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "../../inc/my_snprintf.h"

#define SUCCESSFUL 0
#define FAIL_CMP -1

Suite* s_suite(void);

Suite* c_suite(void);

Suite* d_suite(void);

Suite* x_suite(void);

Suite* all_suite(void);

#endif //LAB_10_01_01_CHECK_MY_SNPRINTF_H
