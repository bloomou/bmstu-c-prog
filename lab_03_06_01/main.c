#include <stdio.h>

#define N 10
#define M 10

#define SUCCESSFUL 0
#define NOT_NUMBER -1
#define OUT_OF_RANGE -2
#define NOT_SQUARE_MATRIX -3

int even_or_odd(int number);

void spiral_filling(int **matr, int n);

void transform(int *buf, int **matr, int n, int m);

int scan_size(int *n, int *m);

void print_matrix(int **matr, int n);

int main(void)
{
    setbuf(stdout, NULL);
    int exit = 0;
    int n = 0;
    int m = 0;
    int a[N][M] = { 0 };
    int *matr[N] = { 0 };

    transform(*a, matr, N, M);
    exit = scan_size(&n, &m);

    if (exit == SUCCESSFUL)
    {
        spiral_filling(matr, n);
        print_matrix(matr, n);
    }
    return exit;
}

void transform(int *buf, int **matr, int n, int m)
{
    for (int i = 0; i < n; i++)
        matr[i] = buf + i * m;
}

int scan_size(int *n, int *m)
{
    int exit = SUCCESSFUL;
    printf("Input size of matrix: ");
    int rc = scanf("%d%d", n, m);
    if (rc == 2)
    {
        if (*n > 0 && *n <= N && *m > 0 && *m <= M)
        {
            if ((*n) != (*m))
            {
                printf("Error: not square matrix");
                exit = NOT_SQUARE_MATRIX;
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

int even_or_odd(int number)
{
    int half;
    if (number % 2 == 0)
        half = number / 2;
    else
        half = number / 2 + 1;
    return half;;
}

void spiral_filling(int **matr, int n)
{
    int number = 1;
    int half = even_or_odd(n);
    for (int k = 0; k < half; k++)
    {
        for (int j = k; j < n - 1 - k; j++)
        {
            matr[k][j] = number;
            number++;
        }
        for (int i = k; i < n - 1 - k; i++)
        {
            matr[i][n - 1 - k] = number;
            number++;
        }
        for (int j = n - 1 - k; j >= k; j--)
        {
            matr[n - 1 - k][j] = number;
            number++;
        }
        for (int i = n - 2 - k; i > k; i--)
        {
            matr[i][k] = number;
            number++;
        }
    }
}

void print_matrix(int **matr, int n)
{
    printf("\n");
    printf("Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", matr[i][j]);
        printf("\n");
    }
}
