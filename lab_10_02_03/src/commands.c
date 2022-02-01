#include "../inc/commands.h"

int factorize(int num, node_t **head)
{
    int rc = SUCCESSFUL;

    int *prime_nums = (int *) calloc(num - 1, sizeof(int));
    if (prime_nums)
    {
        int count = find_prime_numbers(num, prime_nums);
        int flag = FALSE;
        for (int i = count - 1; i >= 0 && rc == SUCCESSFUL; i--)
        {
            if (num % prime_nums[i] != 0 && flag == TRUE)
                rc = push_front(head, 0);
            else if (num % prime_nums[i] == 0)
            {
                if (flag == FALSE)
                    flag = TRUE;
                int num_copy = num;
                int k = 0;
                while (num_copy % prime_nums[i] == 0)
                {
                    k++;
                    num_copy /= prime_nums[i];
                }
                rc = push_front(head, k);
            }
        }
        free(prime_nums);
        prime_nums = NULL;
    }
    else
        rc = FAIL_ALLOC;

    return rc;
}

int find_prime_numbers(int num, int *prime_nums)
{
    int n = num - 1;
    for (int i = 0; i < n; i++)
        prime_nums[i] = i + 2;

    for (int i = 0; i < n; i++)
    {
        if (is_prime(prime_nums[i]) == FALSE)
        {
            for (int j = i; j < n - 1; j++)
                prime_nums[j] = prime_nums[j + 1];
            n--;
            i--;
        }
    }

    return n;
}

int is_prime(int num)
{
    int flag = TRUE;
    for (int i = 2; i < num && flag == TRUE; i++)
    {
        if (num % i == 0)
            flag = FALSE;
    }

    return flag;
}

void squaring(node_t **head)
{
    node_t *current = *head;
    while (current)
    {
        current->data *= 2;
        current = current->next;
    }
}

int multiplication_of_two_lists(node_t *head_1, node_t *head_2, node_t **head_result)
{
    int rc = SUCCESSFUL;

    int count_1 = count_nodes(head_1);
    int count_2 = count_nodes(head_2);

    if (count_1 < count_2)
        rc = multiplication(head_1, head_2, head_result);
    else
        rc = multiplication(head_2, head_1, head_result);

    if (rc == SUCCESSFUL)
    {
        *head_result = reverse(*head_result);
        print_list(*head_result);
    }

    return rc;
}

int multiplication(node_t *head_1, node_t *head_2, node_t **head_result)
{
    int rc = SUCCESSFUL;

    node_t *current_1 = head_1;
    node_t *current_2 = head_2;
    while (current_1 && rc == SUCCESSFUL)
    {
        int sum = current_1->data + current_2->data;
        rc = push_front(head_result, sum);
        current_1 = current_1->next;
        current_2 = current_2->next;
    }
    while (current_2 && rc == SUCCESSFUL)
    {
        rc = push_front(head_result, current_2->data);
        current_2 = current_2->next;
    }

    return rc;
}

int division_without_remainder(node_t *head_1, node_t *head_2, node_t **head_result)
{
    int rc = SUCCESSFUL;

    int count_1 = count_nodes(head_1);
    int count_2 = count_nodes(head_2);

    if (count_1 >= count_2)
    {
        node_t *current_1 = head_1;
        node_t *current_2 = head_2;
        while (current_1 && rc == SUCCESSFUL)
        {
            int sum = current_1->data - current_2->data;
            if (sum < 0)
                rc = FAIL_DIVISION;
            else
            {
                rc = push_front(head_result, sum);
                current_1 = current_1->next;
                current_2 = current_2->next;
            }
        }
        while (current_2 && rc == SUCCESSFUL)
        {
            rc = push_front(head_result, current_2->data);
            current_2 = current_2->next;
        }
        node_t *current_result = *head_result;
        int popped = 0;
        while (current_result && current_result->data == 0)
        {
            pop_front(head_result, &popped);
            current_result = *head_result;
        }
    }
    else
        rc = FAIL_DIVISION;

    if (rc == SUCCESSFUL)
    {
        *head_result = reverse(*head_result);
        print_list(*head_result);
    }

    return rc;
}