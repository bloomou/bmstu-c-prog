#include "../inc/list_work.h"

void free_list(node_t **head)
{
    node_t *new_head = NULL;
    while (*head)
    {
        new_head = (*head)->next;
        free_node(*head);
        *head = new_head;
    }
}

void free_node(node_t *node)
{
    free(node);
    node = NULL;
}

node_t *create_node(node_t *next, int data)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node)
    {
        new_node->next = next;
        new_node->data = data;
    }

    return new_node;
}

int push_front(node_t **head, int data)
{
    int rc = SUCCESSFUL;

    node_t *new = create_node(*head, data);
    if (!new)
        rc = FAIL_ALLOC;
    else
        *head = new;

    return rc;
}

int pop_front(node_t **head, int *data)
{
    if (head == NULL || *head == NULL)
        return STACK_UNDERFLOW;

    int old_data = (*head)->data;
    node_t *new_head = (*head)->next;
    free_node(*head);
    *head = new_head;
    *data = old_data;

    return SUCCESSFUL;
}

int count_nodes(node_t *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }

    return count;
}

node_t *reverse(node_t *head)
{
    if (!head)
        return NULL;

    int rc = SUCCESSFUL;

    int data = 0;
    node_t *new_head = NULL;
    while (head && rc == SUCCESSFUL)
    {
        rc = pop_front(&head, &data);
        if (rc == SUCCESSFUL)
            rc = push_front(&new_head, data);
    }
    if (rc != SUCCESSFUL)
        new_head = NULL;

    return new_head;
}