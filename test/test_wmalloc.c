#include <stdio.h>
#include "wmalloc.h"
#include "CuTest.h"

/*****************************************************************************/

void TestWMallocZero(CuTest *tc) {
    void *ptr = wmalloc(4096);
    CuAssertTrue(tc, ptr == NULL);
}

CuSuite* WMallocGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, TestWMallocZero);
    return suite;
}

/*****************************************************************************/

void RunAllTests(void) {
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();
        
    CuSuiteAddSuite(suite, WMallocGetSuite());
    
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}
    
int main(void) {
    RunAllTests();
}
