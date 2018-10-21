#include <stdio.h>
#include <inttypes.h>
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

void TestWMalloc1Byte(CuTest *tc) {
    void *ptr = wmalloc(1);
    CuAssertPtrNotNull(tc, ptr);
    CuAssertTrue(tc, vmalloc_is_aligned(ptr));
    wfree(ptr);
}

void TestWMalloc4K(CuTest *tc) {
    void *ptr = wmalloc(4 * 1024);
    CuAssertPtrNotNull(tc, ptr);
    CuAssertTrue(tc, vmalloc_is_aligned(ptr));
    wfree(ptr);
}

void TestWMalloc256K(CuTest *tc) {
    void *ptr = wmalloc(256 * 1024);
    CuAssertPtrNotNull(tc, ptr);
    CuAssertTrue(tc, vmalloc_is_aligned(ptr));
    wfree(ptr);
}

void TestWMalloc128M(CuTest *tc) {
    void *ptr = wmalloc(128 * 1024 * 1024);
    CuAssertPtrNotNull(tc, ptr);
    CuAssertTrue(tc, vmalloc_is_aligned(ptr));
    wfree(ptr);
}

CuSuite* WMallocGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestWMallocZero);
    SUITE_ADD_TEST(suite, TestWFreeNull);
    SUITE_ADD_TEST(suite, TestWMalloc1Byte);
    SUITE_ADD_TEST(suite, TestWMalloc4K);
    SUITE_ADD_TEST(suite, TestWMalloc256K);
    SUITE_ADD_TEST(suite, TestWMalloc128M);
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
