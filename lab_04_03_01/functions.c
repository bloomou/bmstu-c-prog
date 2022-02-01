#include <stdio.h>
#include <string.h>
#include "functions.h"

void transform(char *buf, char **matr, int n, int m)
{
    for (int i = 0; i < n; i++)
        matr[i] = buf + i * m;
}

int scan_string(char *str, int size)
{
    int result = SUCCESSFUL;
    char ch;
    int i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF)
        if (i < size - 1)
            str[i++] = ch;
    if (i == 0)
        result = EMPTY_STRING;
    str[i] = '\0';
    if (i == size - 1)
    {
        ch = getchar();
        if (ch != '\n' && ch != EOF)
            result = TOO_LONG_STR;
    }
    return result;
}

char new_string(char **words, int n, char *string)
{
    char last_word[LEN_WORD];
    strcpy(last_word, words[n - 1]);

    int index = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (strcmp(words[i], last_word) != 0 && i != n - 1)
        {
            delete_duplicates(words[i]);
            int j;
            for (j = index; j < ((int)strlen(words[i]) + index); j++)
                string[j] = words[i][j - index];
            if (i != 0)
                string[j] = ' ';
            index = j + 1;
        }
    }
    return *string;
}

void delete_duplicates(char *word)
{
    int count_symbols[ALPHABET] = { 0 };
    int i = 0;
    while (word[i] != '\0')
    {
        if (count_symbols[(int)word[i]] > 0)
        {
            int index = i;
            while (word[index] != '\0')
            {
                word[index] = word[index + 1];
                index++;
            }
        }
        else
        {
            count_symbols[(int)word[i]]++;
            i++;
        }
    }
}
