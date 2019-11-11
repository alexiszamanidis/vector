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