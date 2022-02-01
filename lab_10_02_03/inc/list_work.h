#ifndef LAB_10_01_01_LIST_WORK_H
#define LAB_10_01_01_LIST_WORK_H

#include <stdio.h>
#include <stdlib.h>

#include "../inc/data_structures.h"
#include "../inc/errors.h"

#define TRUE 1
#define FALSE 0

void free_list(node_t **head);

void free_node(node_t *node);

node_t *create_node(node_t *next, int data);

int push_front(node_t **head, int data);

int count_nodes(node_t *head);

int pop_front(node_t **head, int *data);

node_t *reverse(node_t *head);

#endif //LAB_10_01_01_LIST_WORK_H
