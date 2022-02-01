#include "../inc/list_work.h"

int delete_max_element_of_list(node_t **head)
{
    int rc = SUCCESSFUL;
    if (!*head)
        rc = NO_LIST;

    if (rc == SUCCESSFUL)
    {
        *head = sort(*head, comparator);
        *head = reverse(*head);
        pop_front(head);
    }

    return rc;
}

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

node_t *create_node(node_t *next, void *data)
{
    node_t *new_node = malloc(sizeof(node_t));
    if (new_node)
    {
        new_node->next = next;
        new_node->data = data;
    }

    return new_node;
}

int push_front(node_t **head, void *data)
{
    int rc = SUCCESSFUL;

    node_t *new = create_node(*head, data);
    if (!new)
        rc = FAIL_ALLOC;
    else
        *head = new;

    return rc;
}

void *pop_front(node_t **head)
{
    if (head == NULL || *head == NULL)
        return NULL;

    void *old_data = (*head)->data;
    node_t *new_head = (*head)->next;
    free_node(*head);
    *head = new_head;

    return old_data;
}

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    if (!head || !data || !comparator)
        return NULL;

    int if_found = FALSE;
    node_t *current = head;
    while (current && current->data && !if_found)
    {
        if (!comparator(current->data, data))
            if_found = TRUE;
        if (!if_found)
            current = current->next;
    }

    return current;
}

int comparator(const void *value_1, const void *value_2)
{
    return *((int *) value_1) - *((int *) value_2);
}

node_t *reverse(node_t *head)
{
    if (!head)
        return NULL;

    int rc = SUCCESSFUL;

    void *data = NULL;
    node_t *new_head = NULL;
    while (head && head->data && rc == SUCCESSFUL)
    {
        data = pop_front(&head);
        rc = push_front(&new_head, data);
    }
    if (rc != SUCCESSFUL)
        new_head = NULL;

    return new_head;
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (!head || !comparator)
        return NULL;

    int rc = SUCCESSFUL;

    node_t *new_head = head;
    if (new_head->data)
    {
        node_t *current = new_head->next;
        int count_sorted = 1;
        int count = 0;
        while (current && current->data && rc == SUCCESSFUL)
        {
            count = count_sorted;
            current = new_head;
            while (count > 0)
            {
                current = current->next;
                count--;
            }
            if (current)
            {
                node_t *next = current->next;
                sorted_insert(&new_head, current, comparator);

                count_sorted++;
                count = count_sorted;
                current = new_head;
                while (count > 1)
                {
                    current = current->next;
                    count--;
                }
                current->next = next;

                if (!next)
                    rc = STOP_SORT;
            }
            else
                rc = STOP_SORT;
        }
    }

    return new_head;
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    int if_found = FALSE;
    node_t *current = *head;
    node_t *prev = NULL;

    while (current && current->data && current != element && !if_found)
    {
        if (comparator(element->data, current->data) <= 0)
        {
            insert_element(prev, element, current, head);
            if_found = TRUE;
        }
        if (!if_found)
        {
            prev = current;
            current = current->next;
        }
    }
    if (!if_found)
        insert_element(prev, element, NULL, head);
}

void insert_element(node_t *prev, node_t *elem, node_t *next, node_t **head)
{
    if (!prev)
    {
        elem->next = next;
        *head = elem;
    }
    else
    {
        prev->next = elem;
        elem->next = next;
    }
}
