#include <stdio.h>

#define N 10
#define M 10

#define SUCCESSFUL 0
#define NOT_NUMBER -1
#define OUT_OF_RANGE -2

#define FALSE 0
#define TRUE 1

int check_symmetric(int *matr, int m);

void lines(int **matr, int *new_a, int n, int m);

void transform(int *buf, int **matr, int n, int m);

int scan(int **matr, int *n, int *m);

void print_array(int number_of_elements, int *a);

int main(void)
{
    setbuf(stdout, NULL);
    int exit;
    int n = 0;
    int m = 0;
    int a[N][M] = { 0 };
    int result_array[N] = { 0 };
    int *matr[N] = { 0 };

    transform(*a, matr, N, M);
    exit = scan(matr, &n, &m);

    if (exit == SUCCESSFUL)
    {
        lines(matr, result_array, n, m);
        print_array(n, result_array);
    }

    return exit;
}

void transform(int *buf, int **matr, int n, int m)
{
    for (int i = 0; i < n; i++)
        matr[i] = buf + i * m;
}

int scan(int **matr, int *n, int *m)
{
    int exit;
    printf("Input size of matrix: ");
    int rc = scanf("%d%d", n, m);
    if (rc == 2)
    {
        if (*n > 0 && *n <= N && *m > 0 && *m <= M)
        {
            printf("Input elements:\n");
            exit = SUCCESSFUL;
            for (int i = 0; i < *n && exit != NOT_NUMBER; i++)
            {
                for (int j = 0; j < *m && exit != NOT_NUMBER; j++)
                {
                    rc = scanf("%d", matr[i] + j);
                    if (rc != 1)
                    {
                        printf("Error: incorrect element");
                        exit = NOT_NUMBER;
                    }
                }
            }
        }
        else
        {
            printf("Error: number of elements <0 or >10");
            exit = OUT_OF_RANGE;
        }
    }
    else
    {
        printf("Error: incorrect element");
        exit = NOT_NUMBER;
    }
    return exit;
}

void print_array(int number_of_elements, int *a)
{
    printf("\nResult:\n");
    for (int i = 0; i < number_of_elements; i++)
        printf("%d ", *(a + i));
}

void lines(int **matr, int *new_a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        int res = check_symmetric(matr[i], m);
        new_a[i] = res;
    }
}

int check_symmetric(int *matr, int m)
{
    int if_symmetric = TRUE;
    for (int j = 0; j < (m / 2 + 1); j++)
    {
        if (matr[j] != matr[m - 1 - j])
            if_symmetric = FALSE;
    }
    return if_symmetric;
}
