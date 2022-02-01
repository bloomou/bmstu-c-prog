#include <stdio.h>

#define N 10
#define M 10

#define SUCCESSFUL 0
#define NOT_NUMBER -1
#define OUT_OF_RANGE -2
#define NO_NUMBERS -3

#define FALSE 0
#define TRUE 1

#define SHIFT 3

void return_values(int **matr, int *array, int n, int m);

void rotate(int *array, int *len_of_arr);

int filling_array(int **matr, int *array, int *k, int n, int m);

int check_sum_of_digits(int number);

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
    int array[N * M] = { 0 };
    int len_of_array = 0;

    transform(*a, matr, N, M);
    exit = scan_matrix(matr, &n, &m);

    if (exit == SUCCESSFUL)
    {
        exit = filling_array(matr, array, &len_of_array, n, m);
        if (exit == SUCCESSFUL)
        {
            rotate(array, &len_of_array);
            return_values(matr, array, n, m);
            print_matrix(matr, n, m);
        }
        else
            printf("Error: not found certain elements");
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

int check_sum_of_digits(int number)
{
    int flag = FALSE;
    int sum = 0;
    if (number < 0)
        number *= -1;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    if (sum > 10)
        flag = TRUE;
    return flag;
}

int filling_array(int **matr, int *array, int *k, int n, int m)
{
    int is_found = NO_NUMBERS;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check_sum_of_digits(matr[i][j]))
            {
                array[*k] = matr[i][j];
                (*k)++;
                is_found = SUCCESSFUL;
            }
        }
    }
    return is_found;
}

void rotate(int *array, int *len_of_arr)
{
    for (int i = 0; i < SHIFT; i++)
    {
        int first_element = array[0];
        for (int j = 0; j < (*len_of_arr - 1); j++)
            array[j] = array[j + 1];
        array[*len_of_arr - 1] = first_element;
    }
}

void return_values(int **matr, int *array, int n, int m)
{
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (check_sum_of_digits(matr[i][j]))
            {
                matr[i][j] = array[index];
                index++;
            }
        }
    }
}
