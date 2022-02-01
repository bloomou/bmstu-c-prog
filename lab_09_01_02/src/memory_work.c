#include "../inc/memory_work.h"

int alloc_array(item_t **items_array, int *items_len, FILE *f)
{
    int rc = SUCCESSFUL;

    int read;
    char *line = NULL;
    size_t len = 0;
    while ((read = getline(&line, &len, f)) != -1)
        (*items_len)++;

    free(line);
    line = NULL;

    if (*items_len % 3 == 0 && *items_len > 0)
        (*items_len) /= 3;
    else
        rc = INVALID_FILE;

    if (rc == SUCCESSFUL)
    {
        *items_array = (item_t *) calloc(*items_len, sizeof(item_t));
        if (!*items_array)
            rc = FAIL_ALLOC;
    }

    rewind(f);

    return rc;
}

int alloc_str(char **str, FILE *file)
{
    int rc = SUCCESSFUL;

    char ch;
    int i = 0;
    int step_malloc = 2;
    int max_len = step_malloc;
    *str = calloc(max_len, sizeof(char));
    if (*str != NULL)
    {
        while ((ch = fgetc(file)) != '\n' && ch != EOF && ch != ' ' && rc == SUCCESSFUL)
        {
            if (i == max_len)
            {
                max_len *= step_malloc;
                *str = realloc(*str, sizeof(char) * max_len);
                if (!*str)
                    rc = FAIL_ALLOC;
            }
            if (rc == SUCCESSFUL)
            {
                (*str)[i] = ch;
                i++;
            }
        }
        if (ch == ' ')
            rc = FAIL_READ;
        if (i == max_len && rc != FAIL_ALLOC)
        {
            max_len *= step_malloc;
            *str = realloc(*str, sizeof(char) * max_len);
            if (!*str)
                rc = FAIL_ALLOC;
        }
        if (*str)
            (*str)[i] = '\0';
        if (!i)
        {
            *str = NULL;
            rc = FAIL_READ;
        }
    }
    else
        rc = FAIL_ALLOC;

    return rc;
}

void free_array(item_t **items_array, int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((*items_array)[i].title != NULL)
        {
            free((*items_array)[i].title);
            (*items_array)[i].title = NULL;
        }
    }
    free(*items_array);
    *items_array = NULL;
}