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

#define vector_expand(vector,expand)                                                                                        \
    void *temp_pointer;                                                                                                     \
    int new_capacity = (vector)->capacity + (vector)->data_size;                                                            \
    /* check if there is enought space, if it does return 0 */                                                              \
    if ((vector)->length+1 < (vector)->capacity)                                                                            \
        expand = SUCCESS;                                                                                                   \
    /* otherwise expand fix data structure and return 0 on success or -1 on failure */                                      \
    else {                                                                                                                  \
        temp_pointer = realloc((vector)->data,new_capacity*(vector)->data_size);                                            \
        if ( temp_pointer == NULL )                                                                                         \
            expand = FAILURE;                                                                                               \
        (vector)->data = temp_pointer;                                                                                      \
        (vector)->capacity = new_capacity;                                                                                  \
        expand = SUCCESS;                                                                                                   \
    }

#endif