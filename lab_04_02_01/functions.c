#include <stdio.h>
#include <string.h>
#include "functions.h"

void transform(char *buf, char **matr, int n, int m)
{
    for (int i = 0; i < n; i++)
        matr[i] = buf + i * m;
}

int check_if_unique(char **words, int index)
{
    int flag = 1;
    for (int i = 0; i < index && flag; i++)
        if (strcmp(words[index], words[i]) == 0)
            flag = 0;  
    return flag;
}

int check_word_len(char **words, int n)
{
    int result = SUCCESSFUL;
    for (int i = 0; i < n; i++)
        if (strlen(words[i]) > LEN_WORD)
            result = TOO_LONG_WORD;
    return result;
}

int split_into_words(char *string, char **words, int *flag)
{
    int i = 0;
    int j = 0;
    *flag = NO_WORDS;
    char ch[2] = "!";
    string = strcat(string, ch);
    if (strchr(SEPARATORS, string[0]) == NULL)
    {
        words[i][j++] = string[0];
        *flag = SUCCESSFUL;
    }
    for (int k = 1; k < LEN_STR; k++)
    {
        if (strchr(SEPARATORS, string[k]) != NULL)
        {
            if (strchr(SEPARATORS, string[k - 1]) == NULL)
            {
                words[i][j] = '\0';
                i += check_if_unique(words, i);
                j = 0;
            }
        }
        else
        {
            words[i][j++] = string[k];
            *flag = SUCCESSFUL;
        }
    }
    return i;
}

void print_words(char **matr, int n)
{
    printf("Result: ");
    for (int i = 0; i < n; i++)
        printf("%s ", matr[i]);
}

void sort_words(char **matr, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (strcmp(matr[j], matr[j + 1]) >= 0)
                swap(matr + j, matr + j + 1);
}

void swap(char **str_1, char **str_2)
{
    char *temp = *str_1;
    *str_1 = *str_2;
    *str_2 = temp;
}
