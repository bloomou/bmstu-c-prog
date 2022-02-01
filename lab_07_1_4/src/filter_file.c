#include "../inc/filter_file.h"

int command_filter(int *pb, int *pe, char *out_file_name)
{
    int *pb_new = NULL;
    int *pe_new = NULL;
    int rc = key(pb, pe, &pb_new, &pe_new);
    if (rc == SUCCESSFUL)
    {
        mysort(pb_new, pe_new - pb_new, sizeof(int), func_cmp);
        rc = write_elements_into_file(out_file_name, pb_new, pe_new);
        free_mem_array(&pb_new, &pe_new);
    }
    
    return rc;
}

double find_avg_value(const int *pb, const int *pe)
{
    const int *begin = pb;
    int sum = 0;
    int num_of_all = 0;
    while (begin < pe)
    {
        sum += *begin;
        begin++;
        num_of_all++;
    }
    double avg = (double) sum / num_of_all;
    
    return avg;
}

int find_required_nums(const int *pb, const int *pe, double avg, int *count)
{
    int rc = SUCCESSFUL;
    const int *begin = pb;
    while (begin < pe)
    {
        if (*begin > avg)
            (*count)++;
        begin++;
    }
    if (*count == 0)
        rc = EMPTY_ARRAY;
    
    return rc;
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int rc = SUCCESSFUL;
    if (pb_src == NULL || pe_src == NULL || pb_src >= pe_src)
        rc = INVALID_POINTERS;

    if (rc == SUCCESSFUL)
    {
        double avg = find_avg_value(pb_src, pe_src);
        int count = 0;
        rc = find_required_nums(pb_src, pe_src, avg, &count);
        if (rc == SUCCESSFUL)
        {
            rc = allocate_mem_array(count, pb_dst);
            if (rc == SUCCESSFUL)
            {
                *pe_dst = *pb_dst + count;
                const int *begin = pb_src;
                int *cur = *pb_dst;
                while (begin < pe_src)
                {
                    if (*begin > avg)
                    {
                        *cur = *begin;
                        cur++;
                    }
                    begin++;
                }
            }
        }
    }
    
    return rc;
}