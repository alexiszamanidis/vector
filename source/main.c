#include "../header/header.h"
#include "../header/vector.h"

int main(void) {

    /* int */

    vector(int) vector_int;
    
    vector_inititialize(&vector_int);

    for ( int i = 0; i < 15; i++ )
        vector_push_at_nth_position(&vector_int, 10+i, i+1);

    vector_clear(&vector_int);

    return SUCCESS;
}