#ifndef cunit_h_
#define cunit_h_

#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

#define FAILURE -1

static inline void add_test(CU_pSuite pSuite, const char* strName, CU_TestFunc pTestFunc) {
    if ( CU_add_test(pSuite, strName, pTestFunc) == NULL ) {
        CU_cleanup_registry();
        exit(FAILURE);
    }
}

#endif