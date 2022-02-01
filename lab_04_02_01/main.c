#include <stdio.h>
#include <string.h>
#include "functions.h"

int main(void)
{
    int exit = SUCCESSFUL;
    char str[LEN_STR + 1] = { 0 };

    char words_matr[NUM_WORDS][LEN_WORD] = { 0 };
    char *words_pointers[NUM_WORDS] = { 0 };
    transform(*words_matr, words_pointers, NUM_WORDS, LEN_WORD);

    if (fgets(str, LEN_STR, stdin) == NULL)
        exit = NO_END;
    if (str[strlen(str) - 1] != '\n')
        exit = NO_END;
    str[strlen(str) - 1] = '\0';

    if (strlen(str) == 0)
        exit = EMPTY_STRING;

    if (exit == SUCCESSFUL)
    {
        int *p_result = &exit;
        int num = split_into_words(str, words_pointers, p_result);
        if (exit == SUCCESSFUL)
        {
            exit = check_word_len(words_pointers, num);
            if (exit == SUCCESSFUL)
            {
                sort_words(words_pointers, num);
                print_words(words_pointers, num);
            }
        }
    }
    return exit;
}
