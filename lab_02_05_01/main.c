#include <stdio.h>

#define N 10

#define SUCCESSFUL 0
#define NOT_NUMBER -1
#define OUT_OF_RANGE -2
#define NO_POSITIVE -3
#define NO_NEGATIVE -4

#define FALSE 0
#define TRUE 1

void find_positive(int *end, int **position);

void find_negative(int *start, int **position);

int processing(int *p_0, int *p_after_last);

int input_array(int *pa, int **p_after_last);

int main(void)
{
    setbuf(stdout, NULL);
    int a[N] = { 0 };
    int *p_start = a;
    int *p_end = p_start;

    int exit = input_array(p_start, &p_end);

    if (exit == SUCCESSFUL)
    {
        int summ = processing(p_start, p_end);
        printf("Summ: ");
        printf("%d", summ);
    }
    return exit;
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

int processing(int *p_0, int *p_n)
{
    int summ = 0;

    int *left = p_0 - 1;
    int *right = p_n;

    find_negative(p_n, &left);
    find_positive(p_0, &right);

    while (left != p_n && right != (p_0 - 1))
    {
        summ += (*left) * (*right);
        find_negative(p_n, &left);
        find_positive(p_0, &right);
    }
    return summ;
}

void find_positive(int *start, int **position)
{
    *position -= 1;
    while (*position != (start - 1) && **position <= 0)
        *position -= 1;
}

void find_negative(int *end, int **position)
{
    *position += 1;
    while (*position != end && **position >= 0)
        *position += 1;
}
