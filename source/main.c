#include "../header/header.h"
#include "../header/vector.h"

int main(void) {

    vector(int) vector_int;

    int value_int, choice, position;

    vector_inititialize(&vector_int);

    while(1) {
        printf("Choose a number between 1 and 7\n");
        printf("1.vector_push_front\n");
        printf("2.vector_push_back\n");
        printf("3.vector_push_at_nth_position\n");
        printf("4.vector_erase_front\n");
        printf("5.vector_erase_back\n");
        printf("6.vector_erase_from_nth_position\n");
        printf("7.vector_print\n");
        printf("8.exit\n");

        scanf("%d",&choice);

        if( choice == 1 ) {
            printf("value: ");
            scanf("%d",&value_int);
            vector_push_front(&vector_int,value_int);
        }
        else if( choice == 2 ) {
            printf("value: ");
            scanf("%d",&value_int);
            vector_push_back(&vector_int,value_int);
        }
        else if( choice == 3 ) {
            printf("value: ");
            scanf("%d",&value_int);
            printf("position: ");
            scanf("%d",&position);
            vector_push_at_nth_position(&vector_int, value_int, position);
        }
        else if( choice == 4 )
            vector_erase_front(&vector_int);
        else if( choice == 5 )
            vector_erase_back(&vector_int);
        else if( choice == 6 ) {
            printf("position: ");
            scanf("%d",&position);
            vector_erase_from_nth_position(&vector_int,position);
        }
        else if( choice == 7 ) {
            vector_for_each(&vector_int, value_int)
                printf("%d ", value_int);
            printf("\n");
        }
        else if( choice == 8 ) {
            vector_clear(&vector_int);
            break;
        }
        else
            printf("Wrong number please choose again\n");
    }

    return SUCCESS;
}