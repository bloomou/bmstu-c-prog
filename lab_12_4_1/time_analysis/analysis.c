#include "analysis.h"

int main(void)
{
    int rc = SUCCESSFUL;
    FILE *mysort_1, *mysort_2, *mysort_3, *qsort_1, *qsort_2, *qsort_3;

    mysort_1 = fopen("time_analysis\\time_mysort_1.txt", "w");
    if (mysort_1 == NULL)
        return NO_FILE;

    mysort_2 = fopen("time_analysis\\time_mysort_2.txt", "w");
    if (mysort_2 == NULL)
        return NO_FILE;

    mysort_3 = fopen("time_analysis\\time_mysort_3.txt", "w");
    if (mysort_3 == NULL)
        return NO_FILE;

    qsort_1 = fopen("time_analysis\\time_qsort_1.txt", "w");
    if (qsort_1 == NULL)
        return NO_FILE;

    qsort_2 = fopen("time_analysis\\time_qsort_2.txt", "w");
    if (qsort_2 == NULL)
        return NO_FILE;

    qsort_3 = fopen("time_analysis\\time_qsort_3.txt", "w");
    if (qsort_3 == NULL)
        return NO_FILE;

    int array_rand[MAX_LEN] = { 0 };
    arr_of_rand_nums(array_rand, MAX_LEN);

    int array_sorted[MAX_LEN] = { 0 };
    arr_of_rand_nums(array_sorted, MAX_LEN);

    int array_reversed[MAX_LEN] = { 0 };
    arr_of_rand_nums(array_reversed, MAX_LEN);

    write_measurements_to_files(mysort_1, qsort_1, array_rand);
    write_measurements_to_files(mysort_2, qsort_2, array_sorted);
    write_measurements_to_files(mysort_3, qsort_3, array_reversed);

    return rc;
}

void arr_of_rand_nums(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = -50 + rand();
}

void arr_of_sorted_nums(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = i;
}

void arr_of_reversed_nums(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = n - 1 - i;
}

void write_measurements_to_files(FILE *f, FILE *g, int *array)
{
    int64_t time_1, time_2;
    for (int i = 100; i < MAX_LEN; i += 100)
    {
        time_2 = get_time(array, i, qsort);
        fprintf(g, "%f\n", (double) time_2);
    }

    for (int i = 100; i < MAX_LEN; i += 100)
    {
        time_1 = get_time(array, i, mysort);
        fprintf(f, "%f\n", (double) time_1);
    }
}

int64_t get_time(int *arr, int n, \
void func_sort(void *, size_t, size_t, int (*comparator)(const void *, const void *)))
{
    int64_t result = 0;
    struct timeval tval_before, tval_after;
    int64_t elapsed_time = 0;
    int64_t maximum = INT64_MIN;
    int64_t minimum = INT64_MAX;

    for (int i = 0; i < N_REPEAT; i++)
    {
        gettimeofday(&tval_before, NULL);
        func_sort(arr, n, sizeof(int), func_cmp);
        gettimeofday(&tval_after, NULL);

        int64_t time = (tval_after.tv_sec - tval_before.tv_sec) * 1000000LL \
            + (tval_after.tv_usec - tval_before.tv_usec);

        maximum = (time > maximum) ? time : maximum;
        minimum = (time < minimum) ? time : minimum;
        elapsed_time += time;
    }
    result = (elapsed_time - maximum - minimum) / (N_REPEAT - 2);
    return result;
}
