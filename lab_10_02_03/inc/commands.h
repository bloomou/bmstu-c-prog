#ifndef LAB_10_01_01_COMMANDS_H
#define LAB_10_01_01_COMMANDS_H

#include "../inc/data_structures.h"
#include "../inc/errors.h"
#include "../inc/list_work.h"
#include "../inc/io.h"

int factorize(int num, node_t **head);

int find_prime_numbers(int num, int *prime_nums);

int is_prime(int num);

void squaring(node_t **head);

int multiplication_of_two_lists(node_t *head_1, node_t *head_2, node_t **head_result);

int multiplication(node_t *head_1, node_t *head_2, node_t **head_result);

int division_without_remainder(node_t *head_1, node_t *head_2, node_t **head_result);

#endif //LAB_10_01_01_COMMANDS_H
