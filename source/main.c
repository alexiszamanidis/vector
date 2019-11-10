#include "../header/header.h"
#include "../header/vector.h"

int main(void) {

    /* int */

    vector(int) vector_int;

    int value_int;

    vector_inititialize(&vector_int);

    for ( int i = 0; i < 10; i++ )
        vector_push_at_nth_position(&vector_int, 10+i, i+1);

    for ( int i = 0; i < vector_int.length ; i++ ) {
      value_int = vector_at(&vector_int, i);
      printf("%d ", value_int);
    }
    printf("\n");

    vector_erase_from_nth_position(&vector_int,0);
    vector_erase_from_nth_position(&vector_int,12);
    vector_erase_from_nth_position(&vector_int,5);

    for ( int i = 0; i < vector_int.length ; i++ ) {
      value_int = vector_at(&vector_int, i);
      printf("%d ", value_int);
    }
    printf("\n");

    vector_clear(&vector_int);

    return SUCCESS;
}