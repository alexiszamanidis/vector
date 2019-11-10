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

#endif