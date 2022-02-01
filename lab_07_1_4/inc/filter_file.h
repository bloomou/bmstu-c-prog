#ifndef LAB_07_1_4_FILTER_FILE_H
#define LAB_07_1_4_FILTER_FILE_H

#include "io_file.h"
#include "sort_file.h"

#define SUCCESSFUL 0
#define EMPTY_ARRAY -1
#define INVALID_POINTERS -2

int command_filter(int *pb, int *pe, char *out_file_name);

double find_avg_value(const int *pb, const int *pe);

int find_required_nums(const int *pb, const int *pe, double avg, int *count);

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif //LAB_07_1_4_FILTER_FILE_H
