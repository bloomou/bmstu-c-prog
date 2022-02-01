#include <stdio.h>

#define N 10
#define M 10
#define MIN_SIZE 1

#define INDEX 2

#define SUCCESSFUL 0
#define NOT_NUMBER -1
#define OUT_OF_RANGE -2

void deleting_row(int **matr, int n, int m, int row);

void deleting_column(int **matr, int n, int m, int column);

void num_with_min_sum(int **matr, int n, int m, int *row, int *column);

int sum_of_digits(int number);

void transform(int *buf, int **matr, int n, int m);

int scan(int **matr, int *n, int *m);

void print(int **matr, int n, int m);

int main(void)
{
    setbuf(stdout, NULL);
    int exit = 0;
    int n = 0;
    int m = 0;
    int a[N][M] = { 0 };
    int *matr[N] = { 0 };

    int num_of_row = 0;
    int num_of_column = 0;

    transform(*a, matr, N, M);
    exit = scan(matr, &n, &m);

    if (exit == SUCCESSFUL)
    {
        num_with_min_sum(matr, n, m, &num_of_row, &num_of_column);
        deleting_row(matr, n, m, num_of_row);
        deleting_column(matr, n, m, num_of_column);
        print(matr, n - 1, m - 1);
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
        if (*n > MIN_SIZE && *n <= N && *m > MIN_SIZE && *m <= M)
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

void print(int **matr, int n, int m)
{
    printf("\n");
    printf("Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", matr[i][j]);
        }
        printf("\n");
    }
}

int sum_of_digits(int number)
{
    int sum = 0;
    if (number < 0)
        number *= -1;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

void num_with_min_sum(int **matr, int n, int m, int *row, int *column)
{
    int min_sum = sum_of_digits(matr[0][0]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (sum_of_digits(matr[i][j]) < min_sum)
            {
                min_sum = sum_of_digits(matr[i][j]);
                *row = i;
                *column = j;
            }
        }
    }
}

void deleting_row(int **matr, int n, int m, int row)
{
    for (int i = row; i < n - 1; i++)
    {
        for (int j = 0; j < m; j++)
            matr[i][j] = matr[i + 1][j];
    }
}

void deleting_column(int **matr, int n, int m, int column)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = column; j < m - 1; j++)
            matr[i][j] = matr[i][j + 1];
    }
}
