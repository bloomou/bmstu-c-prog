#ifndef LAB_10_01_01_DATA_STRUCTURES_H
#define LAB_10_01_01_DATA_STRUCTURES_H

#define MAX_SIZE_OF_LIST 100

typedef struct node node_t;

struct node
{
    void *data;
    node_t *next;
};

typedef struct
{
    int count;
    int *array;
} array_t;

#endif //LAB_10_01_01_DATA_STRUCTURES_H
