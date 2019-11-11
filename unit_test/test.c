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

void vector_push_at_nth_position_test() {
    vector(int) vector_int;
    vector_inititialize(&vector_int);
    
    // push 100 elements
    for ( int i = 0; i < 100; i++ )
        vector_push_at_nth_position(&vector_int, i, i+1);
    // check pushed elements
    for ( int i = 0; i < 100; i++ )
        CU_ASSERT( vector_int.data[i] == i );

    vector_clear(&vector_int);
}

void vector_push_front_test() {
    vector(int) vector_int;
    vector_inititialize(&vector_int);
    
    // push 100 elements
    for ( int i = 0; i < 100; i++ )
        vector_push_front(&vector_int, i);
    // check pushed elements [99,98,..,0]
    for ( int i = 0; i < 100; i++ )
        CU_ASSERT( vector_int.data[i] == 99-i );

    vector_clear(&vector_int);
}

void vector_push_back_test() {
    vector(int) vector_int;
    vector_inititialize(&vector_int);
    
    // push 100 elements
    for ( int i = 0; i < 100; i++ )
        vector_push_back(&vector_int, i);
    // check pushed elements
    for ( int i = 0; i < 100; i++ )
        CU_ASSERT( vector_int.data[i] == i );

    vector_clear(&vector_int);
}

void vector_erase_from_nth_position_test() {
    vector(int) vector_int;
    vector_inititialize(&vector_int);
    
    // push 100 elements
    for ( int i = 0; i < 100; i++ )
        vector_push_back(&vector_int, i);

    vector_erase_from_nth_position(&vector_int,100);
    CU_ASSERT( vector_int.length == 99 );

    vector_erase_from_nth_position(&vector_int,1);
    CU_ASSERT( vector_int.length == 98 );
    CU_ASSERT( vector_int.data[0] == 1 );

    vector_clear(&vector_int);
}

void vector_erase_front_test() {
    vector(int) vector_int;
    vector_inititialize(&vector_int);
    
    // push 100 elements
    for ( int i = 0; i < 100; i++ )
        vector_push_back(&vector_int, i);
        
    vector_erase_front(&vector_int);
    CU_ASSERT( vector_int.length == 99 );
    CU_ASSERT( vector_int.data[0] == 1 );

    vector_erase_front(&vector_int);
    CU_ASSERT( vector_int.length == 98 );
    CU_ASSERT( vector_int.data[0] == 2 );

    vector_erase_front(&vector_int);
    CU_ASSERT( vector_int.length == 97 );
    CU_ASSERT( vector_int.data[0] == 3 );

    vector_clear(&vector_int);
}