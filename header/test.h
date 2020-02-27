#ifndef test_h_
#define test_h_

#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void add_test(CU_pSuite , const char* , CU_TestFunc );
void vector_inititialize_test();
void vector_expand_test();
void vector_push_at_nth_position_test();
void vector_push_front_test();
void vector_push_back_test();
void vector_erase_from_nth_position_test();
void vector_erase_front_test();
void vector_erase_back_test();
void vector_at_test();
void vector_clear_test();
void vector_for_each_test();
void vector_struct_test();

#endif