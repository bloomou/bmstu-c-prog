#include <stdio.h>

#define N 10
#define SUCCESSFUL 0
#define NOT_NUMBER -1
#define OUT_OF_RANGE -2

int fibonacci(int k);

void proccessing(int number_of_elements, int *a, int *count);

int scan(int *number_of_elements, int *a);

void print_array(int number_of_elements, int *a);

int main(void)
{
    setbuf(stdout, NULL);
    int exit;
    int a[N * 2] = { 0 };
    int n = 0;
    exit = scan(&n, a);
    int count = 0;
    if (exit == SUCCESSFUL)
    {
        proccessing(n, a, &count);
        print_array(n + count, a);
    }
    return exit;
}

int fibonacci(int k)
{
    int fib_0 = 0;
    int fib_1 = 1;
    int fib_temp;
    int i = 1;
    while (i < k)
    {
        fib_temp = fib_1;
        fib_1 += fib_0;
        fib_0 = fib_temp;
        i++;
    }
    if (k == 0)
        fib_1 = 0;
    return fib_1;
}

int scan(int *number_of_elements, int *a)
{
    int exit;
    printf("Input number of elements in the array: ");
    int rc = scanf("%d", number_of_elements);
    if (rc == 1)
    {
        if ((*number_of_elements >= 0) && (*number_of_elements <= 10))
        {
            printf("Input elements: ");
            exit = SUCCESSFUL;
            for (int i = 0; i < *number_of_elements && exit != NOT_NUMBER; i++)
            {
                int rd = scanf("%d", (a + i));
                if (rd != 1)
                {
                    printf("Error: incorrect element");
                    exit = NOT_NUMBER;
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
        printf("Error: incorrect number of elements");
        exit = NOT_NUMBER;
    }
    return exit;
}

void proccessing(int number_of_elements, int *a, int *count)
{
    for (int i = 0; i < number_of_elements + *count; i++)
    {
        if (a[i] % 3 == 0)
        {
            for (int j = number_of_elements + *count; j > (i + 1); j--)
                a[j] = a[j - 1];
            a[i + 1] = fibonacci(*count);
            (*count)++;
            i++;
        }
    }
}

void print_array(int number_of_elements, int *a)
{
    for (int i = 0; i < number_of_elements; i++)
        printf("%d ", *(a + i));
}
