#include <stdio.h>
#include <limits.h>

#define N 10
#define M 10

#define SUCCESSFUL 0
#define NOT_NUMBER -1
#define OUT_OF_RANGE -2

void sort_rows(int **matr, int n, int m);

int find_max_element_in_row(int **matr, int n, int m, int index);

void transform(int *buf, int **matr, int n, int m);

int scan_matrix(int **matr, int *n, int *m);

void print_matrix(int **matr, int n, int m);

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
        sort_rows(matr, n, m);
        print_matrix(matr, n, m);
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

void print_matrix(int **matr, int n, int m)
{
    printf("\n");
    printf("Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", matr[i][j]);
        printf("\n");
    }
}

int find_max_element_in_row(int **matr, int n, int m, int index)
{
    int max = INT_MIN;
    if (index < n && index >= 0)
    {
        max = matr[index][0];
        for (int j = 0; j < m; j++)
        {
            if (matr[index][j] > max)
                max = matr[index][j];
        }
    }
    return max;
}

void sort_rows(int **matr, int n, int m)
{
    for (int i = 0; i < n - 1; i++)
    {
        int jmax = i;
        for (int j = i + 1; j < n; j++)
            if (find_max_element_in_row(matr, n, m, j) > find_max_element_in_row(matr, n, m, jmax))
                jmax = j;
        int *buf = matr[jmax];
        for (int k = jmax; k > i; k--)
            matr[k] = matr[k - 1];
        matr[i] = buf;
    }
}
