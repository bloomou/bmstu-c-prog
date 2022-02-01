#include "my_functions.h"

const char *my_strpbrk(const char *str_1, const char *str_2)
{
    int len_str_1 = 0;
    int len_str_2 = 0;
    while (*(str_1 + len_str_1++));
    while (*(str_2 + len_str_2++));

    int flag = 0;
    const char *index_of_first_entry = NULL;
    for (int i = 0; i < len_str_1 - 1 && !flag; i++)
    {
        for (int j = 0; j < len_str_2 - 1 && !flag; j++)
        {
            if (str_1[i] == str_2[j])
            {
                flag = 1;
                index_of_first_entry = str_1 + i;
            }
        }
    }
    return index_of_first_entry;
}

size_t my_strspn(const char *str_1, const char *str_2)
{
    int len_str_1 = 0;
    int len_str_2 = 0;
    while (*(str_1 + len_str_1++));
    while (*(str_2 + len_str_2++));

    int flag = 0;
    size_t len = 0;
    for (int i = 0; i < len_str_1 - 1 && !flag; i++)
    {
        int symbol_flag = 0;
        for (int j = 0; j < len_str_2 - 1 && !symbol_flag; j++)
            if (str_1[i] == str_2[j])
                symbol_flag = 1;

        if (symbol_flag)
            len = i + 1;
        else
            flag = 1;
    }
    return len;
}

size_t my_strcspn(const char *str_1, const char *str_2)
{
    int len_str_1 = 0;
    int len_str_2 = 0;
    while (*(str_1 + len_str_1++));
    while (*(str_2 + len_str_2++));

    int flag = 0;
    size_t len = len_str_1 - 1;
    for (int i = 0; i < len_str_1 - 1 && !flag; i++)
    {
        int symbol_flag = 0;
        for (int j = 0; j < len_str_2 - 1 && !symbol_flag; j++)
            if (str_1[i] == str_2[j])
                symbol_flag = 1;

        if (symbol_flag)
        {
            len = i;
            flag = 1;
        }
    }
    return len;
}

const char *my_strchr(const char *str, int ch)
{
    int len_str = 0;
    while (*(str + len_str++));

    int flag = 0;
    const char *index = NULL;
    for (int i = 0; i < len_str && !flag; i++)
        if (str[i] == ch)
        {
            flag = 1;
            index = str + i;
        }
    return index;
}

const char *my_strrchr(const char *str, int ch)
{
    int len_str = 0;
    while (*(str + len_str++));

    int flag = 0;
    const char *index = NULL;
    for (int i = len_str - 1; i >= 0 && !flag; i--)
        if (str[i] == ch)
        {
            flag = 1;
            index = str + i;
        }
    return index;
}
