#include "../inc/my_snprintf.h"

int my_snprintf(char *buf, size_t buf_size, const char *format, ...)
{
    va_list args;
    va_start(args, format);

    const char *cur = format;

    int index = 0;
    while (*cur != '\0')
    {
        if (*cur == '%' && *(cur + 1))
        {
            cur++;
            if (*cur == 's')
            {
                char *str = va_arg(args, char *);
                add_string_to_buffer(buf, &index, buf_size, str);
            }
            if (*cur == 'c')
            {
                char symbol = va_arg(args, int);
                if (buf && index < buf_size)
                    buf[index] = symbol;
                index++;
            }
            if (*cur == 'd')
            {
                int number = va_arg(args, int);
                int sign = (number < 0) ? -1 : 1;
                if (sign == -1 && buf)
                    buf[index++] = '-';

                add_number_to_buffer(buf, &index, buf_size, number, DECIMAL, sign);
            }
            if (*cur == 'x')
            {
                uint32_t number = va_arg(args, uint32_t);
                add_number_to_buffer(buf, &index, buf_size, number, HEXADECIMAL, 1);
            }
        }
        else
        {
            if (buf && index < buf_size)
                buf[index] = *cur;
            index++;
        }
        cur++;
    }
    va_end(args);

    if (buf)
    {
        if (index < buf_size)
            buf[index] = '\0';
        else
            buf[buf_size - 1] = '\0';
    }

    return index;
}

char *number_to_string(uint32_t number, int radix)
{
    char *num_string = (char *) malloc(sizeof(char) * MAX_NUM_LEN);
    if (!num_string)
        return NULL;

    char *alphabet = NULL;
    if (radix == DECIMAL)
    {
        alphabet = DECIMAL_ALPHABET;
        number = (int) number;
    }
    if (radix == HEXADECIMAL)
        alphabet = HEXADECIMAL_ALPHABET;

    int num_len = 0;
    if (number == 0)
    {
        num_string[num_len++] = alphabet[0];
        num_string[num_len] = '\0';
    }

    while (number > 0)
    {
        num_string[num_len++] = alphabet[number % radix];
        number /= radix;
    }
    num_string[num_len] = '\0';

    for (int i = 0; i < num_len / 2; i++)
    {
        char tmp = num_string[i];
        num_string[i] = num_string[num_len - 1 - i];
        num_string[num_len - 1 - i] = tmp;
    }

    return num_string;
}

void add_string_to_buffer(char *buf, int *index, size_t buf_size, char *str)
{
    while (*str)
    {
        if (buf && *index < buf_size)
            buf[*index] = *str;
        str++;
        (*index)++;
    }
}

void add_number_to_buffer(char *buf, int *index, size_t buf_size, uint32_t number, int radix, int sign)
{
    char *num_string = number_to_string(number * sign, radix);
    add_string_to_buffer(buf, index, buf_size, num_string);
    free(num_string);
    num_string = NULL;
}
