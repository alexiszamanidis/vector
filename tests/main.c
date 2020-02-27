#include "../header/header.h"
#include "../header/vector.h"
#include "../header/test.h"

int main(void) {
    CU_pSuite pSuite = NULL;

    // initialize the CUnit test registry
    if( CU_initialize_registry() != CUE_SUCCESS )
      return CU_get_error();

    // add a suite to the registry
    pSuite = CU_add_suite("vector_test_suite", 0, 0);
    if( pSuite == NULL ) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // add the tests to the suite
    add_test(pSuite, "vector_inititialize_test", vector_inititialize_test);
    add_test(pSuite, "vector_expand_test", vector_expand_test);
    add_test(pSuite, "vector_push_at_nth_position_test", vector_push_at_nth_position_test);
    add_test(pSuite, "vector_push_front_test", vector_push_front_test);
    add_test(pSuite, "vector_push_back_test", vector_push_back_test);
    add_test(pSuite, "vector_erase_from_nth_position_test", vector_erase_from_nth_position_test);
    add_test(pSuite, "vector_erase_front_test", vector_erase_front_test);
    add_test(pSuite, "vector_erase_back_test", vector_erase_back_test);
    add_test(pSuite, "vector_at_test", vector_at_test);
    add_test(pSuite, "vector_clear_test", vector_clear_test);
    add_test(pSuite, "vector_for_each_test", vector_for_each_test);
    add_test(pSuite, "vector_struct_test", vector_struct_test);

    // run all tests using the CUnit Basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return CU_get_error();
}