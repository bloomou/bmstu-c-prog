#include <stdio.h>

#define N 10
#define SUCCESSFUL 0
#define NOT_NUMBER -1
#define OUT_OF_RANGE -2
#define NO_PRIME_ELEMENTS -3
#define FALSE 0
#define TRUE 1

int scan(int *number_of_elements, int *a);

void print(int number_of_elements, int *a);

int prime_check(int number);

int new_array_from_prime_elements(int number_of_elements, int *a, int *b);

int main(void)
{
    setbuf(stdout, NULL);
    int exit;

    int a[N];
    int b[N];
    int n = 0;

    exit = scan(&n, a);
    if (exit == SUCCESSFUL)
    {
        int len_b = new_array_from_prime_elements(n, a, b);
        if (len_b == 0)
        {
            printf("Error: no prime elements");
            exit = NO_PRIME_ELEMENTS;
        }
        else
            print(len_b, b);
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

void print(int number_of_elements, int *a)
{
    for (int i = 0; i < number_of_elements; i++)
    {
        printf("%d ", *(a + i));
    }
}

int prime_check(int number)
{
    int result = TRUE;
    if (number <= 1)
        result = FALSE;
    else
    {
        for (int i = 2; i * i <= number; i++)
        {
            if (number % i == 0)
                result = FALSE;
        }
    }
    return result;
}

int new_array_from_prime_elements(int number_of_elements, int *a, int *b)
{
    int j = 0;
    for (int i = 0; i < number_of_elements; i++)
    {
        if (prime_check(*(a + i)))
        {
            *(b + j) = *(a + i);
            j++;
        }
    }
    return j;
}
