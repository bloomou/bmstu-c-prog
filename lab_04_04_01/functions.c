#include <stdio.h>
#include <string.h>
#include "functions.h"

void print_result(int res)
{
    if (!res)
        printf("NO");
    else
        printf("YES");
}

int processing(char *string, int n)
{
    int result = FALSE;
    int index = skip_spaces_at_beginning(string, n);
    n = skip_spaces_at_end(string, n);

    if (strchr(SIGNS, string[index]) != NULL)
        index++;
    int index_copy = index;

    if (string[index] == '.' && index < n - 1)
    {
        index++;
        if (strchr(NUMBERS, string[index]) != NULL)
            result = end_of_number(string, n, index);
    }
    else if (strchr(NUMBERS, string[index]) != NULL && index < n)
    {
        index++;
        result = is_end(n, index);
        if (index < n)
        {
            index = nums_check(string, n, index);
            result = is_end(n, index);
            if (index < n)
            {
                if (string[index] == '.' && index < n)
                    result = end_of_number(string, n, index);
                else
                    result = exp_part_check(string, n, index);
            }
        }
    }
    if (string[index_copy] == '0' && index_copy < n - 1)
        if (string[index_copy + 1] == '0')
            result = FALSE;
    return result;
}

int exp_part_check(char *string, int n, int index)
{
    int result = FALSE;
    if ((strchr(EXPS, string[index]) != NULL) && index < n)
    {
        if ((index + 1) < n)
        {
            if (strchr(SIGNS, string[index + 1]) != NULL)
                index += 2;
            else
                index++;

            if (index < n)
            {
                int flag = 0;
                for (int i = index; i < n; i++)
                    if (strchr(NUMBERS, string[i]) != NULL)
                        flag += 1;
                if (flag == n - index)
                    result = TRUE;
            }
        }
    }
    return result;
}

int end_of_number(char *string, int n, int index)
{
    int result = FALSE;
    index++;
    if (index == n)
        result = TRUE;
    else if (index < n)
    {
        index = nums_check(string, n, index);
        if (index == n)
            result = TRUE;
        else if (index < n)
            result = exp_part_check(string, n, index);
    }
    return result;
}

int nums_check(char *string, int n, int index)
{
    while (strchr(NUMBERS, string[index]) != NULL && index < n)
        index++;
    return index;
}

int is_end(int n, int index)
{
    int result;
    if (index == n)
        result = TRUE;
    return result;
}

int skip_spaces_at_beginning(char *string, int n)
{
    int index = 0;
    while ((string[index] == ' ' || string[index] == '\t') && index < n)
        index++;
    return index;
}

int skip_spaces_at_end(char *string, int n)
{
    while ((string[n - 1] == ' ' || string[n - 1] == '\t') && n > 0)
        n--;
    return n;
}
