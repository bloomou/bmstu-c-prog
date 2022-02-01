#include "../inc/io.h"

int read_from_file(FILE *f, array_t *array)
{
    int rc = SUCCESSFUL;

    int *ptr, num;
    array->count = 0;
    array->array = NULL;

    while (!ferror(f) && !feof(f) && rc == SUCCESSFUL)
    {
        if (fscanf(f, "%d", &num) != 1)
            rc = FAIL_READ;
        if (rc == SUCCESSFUL)
        {
            ptr = (int *) realloc(array->array, (array->count + 1) * sizeof(int));
            if (!ptr)
                rc = FAIL_ALLOC;
            else
            {
                array->array = ptr;
                array->array[array->count] = num;
                array->count++;
            }
        }
    }
    if (rc != SUCCESSFUL)
    {
        free(array->array);
        array->array = NULL;
    }
    if (array->count == 0)
        rc = EMPTY_FILE;

    return rc;
}

int fill_list(node_t **head, array_t *array)
{
    int rc = SUCCESSFUL;

    for (int i = 0; i < array->count && rc == SUCCESSFUL; i++)
        rc = push_front(head, (void *) (array->array + i));

    return rc;
}

int write_to_file(FILE *f, node_t *head)
{
    int rc = SUCCESSFUL;

    while (head)
    {
        fprintf(f, "%d\n", *((int *) head->data));
        head = head->next;
    }

    return rc;
}