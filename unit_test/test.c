#include "../header/header.h"
#include "../header/vector.h"
#include "../header/test.h"

void vector_inititialize_test() {
    vector(int) vector_int;
    vector_inititialize(&vector_int);

    CU_ASSERT( vector_int.data == NULL );
    CU_ASSERT( vector_int.length == 0 );
    CU_ASSERT( vector_int.capacity == 0 );
    CU_ASSERT( vector_int.data_size == sizeof(int) );

    vector_clear(&vector_int);
}

void vector_expand_test() {
    vector(int) vector_int;
    vector_inititialize(&vector_int);
    int expand;

    vector_expand(&vector_int,expand);

    CU_ASSERT( expand == SUCCESS );
    CU_ASSERT( vector_int.capacity == 4 );
    CU_ASSERT( vector_int.length == 0 );
    CU_ASSERT( vector_int.data_size == 4 );

    vector_clear(&vector_int);
}