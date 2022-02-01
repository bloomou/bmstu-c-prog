#include <stdio.h>

#define N 10
#define SUCCESSFUL 0
#define NO_NUMBERS -1
#define OVERFLOW 100

int input_array(int *a);

void print_array(int number_of_elements, int *a);

void bubble_sort(int number_of_elements, int *a);

void swap(int *first_num, int *second_num);

int main(void)
{
    setbuf(stdout, NULL);
    int exit = SUCCESSFUL;
    int n = 0;
    int a[N];

    printf("Input elements of the array: ");
    n = input_array(a);

    if (n == N + 1)
    {
        exit = OVERFLOW;
        n = N;
    }
    if (n != 0)
    {
        bubble_sort(n, a);
        print_array(n, a);
    }
    else
    {
        printf("Error: input error");
        exit = NO_NUMBERS;
    }
    return exit;
}

int input_array(int *a)
{
    int num;
    int i = 0;

    while (scanf("%d", &num) == 1 && i < N + 1)
    {
        a[i] = num;
        i++;
    }
    return i;
}

void print_array(int number_of_elements, int *a)
{
    for (int i = 0; i < number_of_elements; i++)
    {
        printf("%d ", *(a + i));
    }
}

void bubble_sort(int number_of_elements, int *a)
{
    for (int i = 0; i < number_of_elements - 1; i++)
    {
        for (int j = 0; j < number_of_elements - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a + j, a + j + 1);
            }
        }
    }
}

void swap(int *first_num, int *second_num)
{
    int temp = *first_num;
    *first_num = *second_num;
    *second_num = temp;	
}
