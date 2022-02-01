#ifndef LAB_10_01_01_IO_H
#define LAB_10_01_01_IO_H

#include <stdio.h>
#include <stdlib.h>

#include "../inc/data_structures.h"
#include "../inc/errors.h"
#include "../inc/list_work.h"

int read_from_file(FILE *f, array_t *array);

int fill_list(node_t **head, array_t *array);

int write_to_file(FILE *f, node_t *head);

#endif //LAB_10_01_01_IO_H
