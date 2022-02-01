#include <stdio.h>
#include <string.h>
#include "functions.h"

int main(void)
{
    int exit = SUCCESSFUL;
    char str[LEN_STR + 1] = { 0 };

    if (fgets(str, LEN_STR, stdin) == NULL)
        exit = NO_END;
    if (str[strlen(str) - 1] != '\n')
        exit = NO_END;
    str[strlen(str) - 1] = '\0';

    if (exit == SUCCESSFUL)
    {
        int len_string = strlen(str);
        int result = processing(str, len_string);
        print_result(result);
    }

    return exit;
}
