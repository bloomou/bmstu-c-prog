#ifndef LAB_10_01_01_LIST_WORK_H
#define LAB_10_01_01_LIST_WORK_H

#include <stdio.h>
#include <stdlib.h>

#include "../inc/data_structures.h"
#include "../inc/errors.h"

#define TRUE 1
#define FALSE 0

int delete_max_element_of_list(node_t **head);

void free_list(node_t **head);

void free_node(node_t *node);

node_t *create_node(node_t *next, void *data);

int push_front(node_t **head, void *data);

void *pop_front(node_t **head);

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));

int comparator(const void *value_1, const void *value_2);

node_t *reverse(node_t *head);

node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

void insert_element(node_t *prev, node_t *elem, node_t *next, node_t **head);

#endif //LAB_10_01_01_LIST_WORK_H
