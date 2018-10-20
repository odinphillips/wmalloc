#include <stdio.h>
#include "CuTest.h"

/*****************************************************************************/

void TestWMallocZero(CuTest *tc) {
    CuAssertTrue(tc, 1==1);
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
