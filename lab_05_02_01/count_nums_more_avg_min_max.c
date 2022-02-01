#include "count_nums_more_avg_min_max.h"

int find_max_and_min(FILE *f, double *max, double *min)
{
    int rc = ONE_ELEMENT;
    double num;
    if (fscanf(f, "%lf", &num) == 1)
    {
        check_if_max_or_min(max, min, num);
        while (fscanf(f, "%lf", &num) == 1)
        {
            rc = SUCCESSFUL;
            check_if_max_or_min(max, min, num);
        }
    }
    else
        rc = FAIL_READ;
    return rc;
}

void check_if_max_or_min(double *max, double *min, double number)
{
    if (number > *max)
        *max = number;
    if (number < *min)
        *min = number;
}

int count_nums_more_avg_min_max(FILE *f, double max, double min)
{
    fseek(f, 0, SEEK_SET);
    double avg = (max + min) / 2;
    double num;
    int count = 0;
    while (fscanf(f, "%lf", &num) == 1)
        if (num > avg)
            count++;
    return count;
}
