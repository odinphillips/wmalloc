#include <stdio.h>
#include <unistd.h>

#include "CuTest.h"

#include "wmalloc.h"

/*****************************************************************************/

void TestWMallocZero(CuTest *tc) {
    void *ptr = wmalloc(0);
    CuAssertPtrEquals(tc, NULL, ptr);
}

void TestWFreeNull(CuTest *tc) {
    wfree(NULL);
}

void TestWMalloc4K(CuTest *tc) {
    void *ptr = wmalloc(4096);
    CuAssertPtrNotNull(tc, ptr);
    wfree(ptr);
}

CuSuite* WMallocGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestWMallocZero);
    SUITE_ADD_TEST(suite, TestWFreeNull);
    SUITE_ADD_TEST(suite, TestWMalloc4K);
    return suite;
}

/*****************************************************************************/

void TestWMallocPageSize(CuTest *tc) {
    // Need to call wmalloc() at least once for internal page size to be initialised.
    wmalloc(0);
    int actual_page_size = wmalloc_page_size();
    int expected_page_size = getpagesize();
    CuAssertIntEquals(tc, expected_page_size, actual_page_size);
}

CuSuite* WMallocUtilityGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestWMallocPageSize);
    return suite;
}

/*****************************************************************************/

void RunAllTests(void) {
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();
        
    CuSuiteAddSuite(suite, WMallocGetSuite());
    CuSuiteAddSuite(suite, WMallocUtilityGetSuite());

    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}
    
int main(void) {
    RunAllTests();
}
