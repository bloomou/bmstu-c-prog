#include <stdio.h>
#include <inttypes.h>
#include <sys/time.h>
#include <limits.h>

#define N 1000
#define M 1000

#define ZERO 0
#define ONE 1
#define TWO 2

#define SUCCESSFUL 0
#define NOT_NUMBER -1
#define OUT_OF_RANGE -2
#define NO_POSITIVE -3
#define NO_NEGATIVE -4

#define FALSE 0
#define TRUE 1

int process_0(int *p_0, int *p_after_last);

void find_positive_0(int *end, int **position);

void find_negative_0(int *start, int **position);


int process_1(int *a, int number_of_elements);

void find_positive_1(int *a, int *position);

void find_negative_1(int *a, int number_of_elements, int *position);


int process_2(int *a, int number_of_elements);

void find_positive_2(int *a, int *position);

void find_negative_2(int *a, int number_of_elements, int *position);


int input_array(int *pa, int **p_after_last);

double get_time(int number_of_elements, int *a, int choice);

int main(void)
{
    setbuf(stdout, NULL);
    int a[N] = { 0 };
    int *p_start = a;
    int *p_end = p_start;

    int exit = input_array(p_start, &p_end);

    if (exit == SUCCESSFUL)
    {
        int summ_0 = process_0(p_start, p_end);
        int n = p_end - p_start;
        int summ_1 = process_1(a, n);
        int summ_2 = process_2(a, n);

        double time_1 = get_time(n, a, ONE);
        double time_2 = get_time(n, a, TWO);
        double time_0 = get_time(n, a, ZERO);

        printf("Time:\n%f ", time_1);
        printf("%f ", time_2);
        printf("%f\n", time_0);

        printf("Summ:\n%d ", summ_1);
        printf("%d ", summ_2);
        printf("%d ", summ_0);
    }
    return exit;
}



double get_time(int number_of_elements, int *a, int choice)
{
    struct timeval tval_before, tval_after;
    int64_t elapsed_time = 0;
    int64_t maximum = INT64_MIN;
    int64_t minimum = INT64_MAX;

    for (int i = 1; i <= M; i++)
    {
        gettimeofday (&tval_before, NULL);

        switch(choice)
        {
        case ZERO:
            process_0(a, a + number_of_elements);
        case ONE:
            process_1(a, number_of_elements);
        case TWO:
            process_2(a, number_of_elements);
        }

        gettimeofday (&tval_after, NULL);
        int64_t time = (tval_after.tv_sec - tval_before.tv_sec) * 1000000LL
                + (tval_after.tv_usec - tval_before.tv_usec);

        maximum = (time > maximum) ? time : maximum;
        minimum = (time < minimum) ? time : minimum;

        elapsed_time += time;
    }
    return (double) (elapsed_time - maximum - minimum) / (M - 2);
}

int input_array(int *pa, int **p_after_last)
{
    int result = SUCCESSFUL;
    printf("Input number of elements of the array: ");
    int n;
    if (scanf("%d", &n) == 1)
    {
        if (n >= 0 && n <= N)
        {
            int has_positive = FALSE;
            int has_negative = FALSE;

            printf("Input elements:\n");
            *p_after_last = pa + n;
            int *begin = pa;
            while (begin < *p_after_last)
            {
                if (scanf("%d", begin) != 1)
                {
                    printf("Error: incorrect element");
                    result = NOT_NUMBER;
                }
                if (*begin > 0)
                    has_positive = TRUE;
                else if (*begin < 0)
                    has_negative = TRUE;
                begin++;
            }
            if (has_positive == FALSE)
            {
                printf("Error: no positive elements");
                result = NO_POSITIVE;
            }
            if (has_negative == FALSE)
            {
                printf("Error: no negative elements");
                result = NO_NEGATIVE;
            }
        }
        else
        {
            printf("Error: number of elements <0 or >10");
            result = OUT_OF_RANGE;
        }
    }
    else
    {
        printf("Error: incorrect number of elements");
        result = NOT_NUMBER;
    }
    return result;
}

int process_0(int *p_0, int *p_n)
{
    int summ = 0;

    int *left = p_0 - 1;
    int *right = p_n;

    find_negative_0(p_n, &left);
    find_positive_0(p_0, &right);

    while (left != p_n && right != (p_0 - 1))
    {
        summ += (*left) * (*right);
        find_negative_0(p_n, &left);
        find_positive_0(p_0, &right);
    }
    return summ;
}

void find_positive_0(int *start, int **position)
{
    *position -= 1;
    while (*position != (start - 1) && **position <= 0)
        *position -= 1;
}

void find_negative_0(int *end, int **position)
{
    *position += 1;
    while (*position != end && **position >= 0)
        *position += 1;
}

int process_1(int *a, int number_of_elements)
{
    int sum = 0;

    int left = -1;
    int right = number_of_elements;

    find_negative_1(a, number_of_elements, &left);
    find_positive_1(a, &right);

    while (left != number_of_elements && right != -1)
    {
        sum += a[left] * a[right];
        find_negative_1(a, number_of_elements, &left);
        find_positive_1(a, &right);
    }
    return sum;
}

void find_positive_1(int *a, int *position)
{
    *position -= 1;
    while (*position != -1 && a[*position] <= 0)
    {
        *position -= 1;
    }
}

void find_negative_1(int *a, int number_of_elements, int *position)
{
    *position += 1;
    while (*position != number_of_elements && a[*position] >= 0)
    {
        *position += 1;
    }
}

int process_2(int *a, int number_of_elements)
{
    int sum = 0;

    int left = -1;
    int right = number_of_elements;

    find_negative_2(a, number_of_elements, &left);
    find_positive_2(a, &right);

    while (left != number_of_elements && right != -1)
    {
        sum += *(a + left) * *(a + right);
        find_negative_2(a, number_of_elements, &left);
        find_positive_2(a, &right);
    }
    return sum;
}

void find_positive_2(int *a, int *position)
{
    *position -= 1;
    while (*position != -1 && *(a + *position) <= 0)
    {
        *position -= 1;
    }
}

void find_negative_2(int *a, int number_of_elements, int *position)
{
    *position += 1;
    while (*position != number_of_elements && *(a + *position) >= 0)
    {
        *position += 1;
    }
}
