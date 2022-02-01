#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <limits.h>

#define SUCCESSFUL 0
#define FAIL_READ -1
#define COULD_NOT_OPEN_FILE -2
#define ONE_ELEMENT -3
#define NO_ARGS -4

int find_max_and_min(FILE *f, double *max, double *min);

void check_if_max_or_min(double *max, double *min, double number);

int count_nums_more_avg_min_max(FILE *f, double max, double min);

#endif // FUNCTIONS_H
