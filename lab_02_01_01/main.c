#include <stdio.h>

#define N 10
#define SUCCESSFUL 0
#define NOT_NUMBER -1
#define OUT_OF_RANGE -2
#define NO_ODD_ELEMENTS -3
#define FALSE 0
#define TRUE 1

int scan(int *number_of_elements, int *a);

int product_of_odd(int number_of_elements, int *a);

int print_of_result(int result);

int main(void)
{
    setbuf(stdout, NULL);
    int exit;

    int a[N];
    int n = 0;

    exit = scan(&n, a);
    if (exit == SUCCESSFUL)
    {
        int res = product_of_odd(n, a);
        exit = print_of_result(res);
    }

    return exit;
}

int scan(int *number_of_elements, int *a)
{
    int exit;
    printf("Input number of elements in the array: ");
    int rc = scanf("%d", number_of_elements);
    if (rc == 1)
    {
        if ((*number_of_elements >= 0) && (*number_of_elements <= N))
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

int product_of_odd(int number_of_elements, int *a)
{
    int result = 1;
    int flag = FALSE;
    for (int i = 0; i < number_of_elements; i++)
    {
        if (*(a + i) % 2 != 0)
        {
            result *= *(a + i);
            flag = TRUE;
        }
    }
    if (flag == FALSE)
        result = FALSE;
    return result;
}

int print_of_result(int result)
{
    int exit;
    if (result == FALSE)
    {
        printf("Error: no odd elements");
        exit = NO_ODD_ELEMENTS;
    }
    else
    {
        printf("Result: %d ", result);
        exit = SUCCESSFUL;
    }
    return exit;
}
