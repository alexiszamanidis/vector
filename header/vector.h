#ifndef vector_H
#define vector_H

#include "./header.h"

#define vector(datatype)       \
    struct {                   \
        datatype *data;        \
        int length;            \
        int capacity;          \
        int data_size;         \
    }

#define vector_inititialize(vector)                         \
    do {                                                    \
        (vector)->data = NULL;                              \
        (vector)->length = 0;                               \
        (vector)->capacity = 0;                             \
        (vector)->data_size = sizeof(*((vector)->data));    \
    } while (0)

#endif