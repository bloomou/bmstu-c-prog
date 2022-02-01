#include <stdio.h>

#define N 10
#define M 10

#define SUCCESSFUL 0
#define NOT_NUMBER -1
#define OUT_OF_RANGE -2
#define NOT_SQUARE_MATRIX -3

void change_rows(int **matr, int n);

void transform(int *buf, int **matr, int n, int m);

int scan_matrix(int **matr, int *n, int *m);

void print_matrix(int **matr, int n);

void swap(int *first_num, int *second_num);

int main(void)
{
    setbuf(stdout, NULL);
    int exit = 0;
    int n = 0;
    int m = 0;
    int a[N][M] = { 0 };
    int *matr[N] = { 0 };

    transform(*a, matr, N, M);
    exit = scan_matrix(matr, &n, &m);

    if (exit == SUCCESSFUL)
    {
        change_rows(matr, n);
        print_matrix(matr, n);
    }
    return exit;
}

void transform(int *buf, int **matr, int n, int m)
{
    for (int i = 0; i < n; i++)
        matr[i] = buf + i * m;
}

int scan_matrix(int **matr, int *n, int *m)
{
    int exit;
    printf("Input size of matrix: ");
    int rc = scanf("%d%d", n, m);
    if (rc == 2)
    {
        if (*n > 0 && *n <= N && *m > 0 && *m <= M)
        {
            if ((*n) == (*m))
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

void change_rows(int **matr, int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = i; j < n / 2; j++)
            swap(matr[i] + j, matr[n - 1 - i] + j);
        for (int j = n - 1 - i; j >= n / 2; j--)
            swap(matr[i] + j, matr[n - 1 - i] + j);
    }
}

void swap(int *first_num, int *second_num)
{
    int temp = *first_num;
    *first_num = *second_num;
    *second_num = temp;	
}
