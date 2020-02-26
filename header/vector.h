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

#define vector_expand(vector,expand)                                                                        \
    do {                                                                                                    \
        void *temp_pointer;                                                                                 \
        int new_capacity = (vector)->capacity + (vector)->data_size;                                        \
        /* check if there is enought space, if it does return 0 */                                          \
        if ((vector)->length+1 < (vector)->capacity)                                                        \
            expand = SUCCESS;                                                                               \
        /* otherwise expand fix data structure and return 0 on success or -1 on failure */                  \
        else {                                                                                              \
            temp_pointer = realloc((vector)->data,new_capacity*(vector)->data_size);                        \
            if ( temp_pointer == NULL )                                                                     \
                expand = FAILURE;                                                                           \
            else {                                                                                          \
                (vector)->data = temp_pointer;                                                              \
                (vector)->capacity = new_capacity;                                                          \
                expand = SUCCESS;                                                                           \
            }                                                                                               \
        }                                                                                                   \
    } while (0)

#define vector_push_at_nth_position(vector, value, position)                                                \
    do {                                                                                                    \
        char *source, *dest;                                                                                \
        int expand, size;                                                                                   \
        /* if the position is valid */                                                                      \
        if( (position >= 0) && (position <= ((vector)->length)) ) {                                         \
            vector_expand(vector,expand);                                                                   \
            /* if the expand was successful, do the push */                                                 \
            if( expand == SUCCESS ) {                                                                       \
                dest = (char *)(vector)->data + (position + 1) * (vector)->data_size;                       \
                source = (char *)(vector)->data + position * (vector)->data_size;                           \
                size = ((vector)->length - position) * (vector)->data_size;                                 \
                memmove(dest,source,size);                                                                  \
                (vector)->data[position] = value;                                                           \
                (vector)->length++;                                                                         \
            }                                                                                               \
            else                                                                                            \
                printf("Could not expand. Push at < %d > position failed\n",position);                      \
        }                                                                                                   \
        else                                                                                                \
            printf("Wrong position < %d >.\n",position);                                                    \
    } while (0)

#define vector_push_front(vector, value)                                                                    \
    do {                                                                                                    \
        char *source, *dest;                                                                                \
        int expand, size;                                                                                   \
        vector_expand(vector,expand);                                                                       \
        /* if the expand was successful, do the push */                                                     \
        if( expand == SUCCESS ) {                                                                           \
            dest = (char *)(vector)->data + (vector)->data_size;                                            \
            source = (char *)(vector)->data;                                                                \
            size = ((vector)->length) * (vector)->data_size;                                                \
            memmove(dest,source,size);                                                                      \
            (vector)->data[0] = value;                                                                      \
            (vector)->length++;                                                                             \
        }                                                                                                   \
        else                                                                                                \
            printf("Could not expand. Push front failed\n");                                                \
    } while (0)

#define vector_push_back(vector, value)                                                                     \
    do {                                                                                                    \
        int expand;                                                                                         \
        vector_expand(vector,expand);                                                                       \
        /* if the expand was successful, do the push */                                                     \
        if( expand == SUCCESS ) {                                                                           \
            (vector)->data[(vector)->length] = value;                                                       \
            (vector)->length++;                                                                             \
        }                                                                                                   \
        else                                                                                                \
            printf("Could not expand. Push back failed\n");                                                 \
    } while (0)

#define vector_erase_from_nth_position(vector, position)                                                    \
    do {                                                                                                    \
        char *source, *dest;                                                                                \
        int size;                                                                                           \
        if( (position >= 0) && (position < (vector)->length) ) {                                            \
            dest = (char *)(vector)->data + position * (vector)->data_size;                                 \
            source = (char *)(vector)->data + (position+1) * (vector)->data_size;                           \
            size = ((vector)->length - (position+1)) * (vector)->data_size;                                 \
            memmove(dest,source,size);                                                                      \
            (vector)->length--;                                                                             \
        }                                                                                                   \
        else                                                                                                \
            printf("Wrong position < %d >.\n",position);                                                    \
    } while (0)

#define vector_erase_front(vector)                                                                          \
    do {                                                                                                    \
        char *source, *dest;                                                                                \
        int size;                                                                                           \
        if( (vector)->length > 0 ) {                                                                        \
            dest = (char *)(vector)->data;                                                                  \
            source = (char *)(vector)->data +  (vector)->data_size;                                         \
            size = ((vector)->length - 1) * (vector)->data_size;                                            \
            memmove(dest,source,size);                                                                      \
            (vector)->length--;                                                                             \
        }                                                                                                   \
        else                                                                                                \
            printf("There is nothing to be removed.\n");                                                    \
    } while (0)

#define vector_erase_back(vector)                                                                           \
    do {                                                                                                    \
        char *source, *dest;                                                                                \
        int size;                                                                                           \
        if( (vector)->length > 0 ) {                                                                        \
            dest = (char *)(vector)->data + ((vector)->length-1) * (vector)->data_size;                     \
            source = (char *)(vector)->data + (vector)->length * (vector)->data_size;                       \
            size = ((vector)->length - (vector)->length) * (vector)->data_size;                             \
            memmove(dest,source,size);                                                                      \
            (vector)->length--;                                                                             \
        }                                                                                                   \
        else                                                                                                \
            printf("There is nothing to be removed.\n");                                                    \
    } while (0)

#define vector_at(vector, index)   \
    (vector)->data[index]

#define vector_clear(vector)                                \
    do {                                                    \
        free((vector)->data);                               \
        (vector)->data = NULL;                              \
        (vector)->length = 0;                               \
        (vector)->capacity = 0;                             \
    } while (0)

#define vector_for_each(vector, value)                                              \
    for ( int i = 0 ; i < (vector)->length && (value = (vector)->data[i]) ; i++)    \

#endif