#ifndef LAB_10_01_01_IO_H
#define LAB_10_01_01_IO_H

#include <stdio.h>
#include <string.h>

#include "../inc/errors.h"
#include "../inc/data_structures.h"

#define CMD_LEN 4

int read_cmd(char *cmd);

int read_number(int *num);

void print_list(node_t *head);

#endif //LAB_10_01_01_IO_H
