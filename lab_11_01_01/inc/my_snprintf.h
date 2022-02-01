#ifndef LAB_10_01_01_MY_SNPRINTF_H
#define LAB_10_01_01_MY_SNPRINTF_H

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUM_LEN 255

#define DECIMAL 10
#define HEXADECIMAL 16

#define DECIMAL_ALPHABET "0123456789"
#define HEXADECIMAL_ALPHABET "0123456789abcdef"

int my_snprintf(char *buf, size_t buf_size, const char *format, ...);

char *number_to_string(uint32_t number, int radix);

void add_string_to_buffer(char *buf, int *index, size_t buf_size, char *str);

void add_number_to_buffer(char *buf, int *index, size_t buf_size, uint32_t number, int radix, int sign);

#endif //LAB_10_01_01_MY_SNPRINTF_H
