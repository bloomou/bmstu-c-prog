#include "lib_arr.h"
#include <stdlib.h>

void arr_prime_numbers(int *arr, int n)
{
    int prime_num = 2;
    for (int i = 0; i < n; i++)
    {
        int is_prime = 0;
        for (int j = 2; j < prime_num; j++)
        {
            if (prime_num % j == 0)
                is_prime = 1;
        }
        if (!is_prime)
            arr[i] = prime_num;
        else
            i--;
        prime_num++;
    }
}

int add_num_after_even(int *src, int src_size, int *dst, int dst_size, int num)
{
    int index = 0;
    for (int i = 0; i < src_size; i++)
    {
        if (index < dst_size)
            dst[index] = src[i];
        if (src[i] % 2 == 0)
        {
            index++;
            if (index < dst_size)
                dst[index] = num;
        }
        index++;
    }

    return index;
}