#include <inttypes.h>
#include <stdio.h>
#include <unistd.h>

#include "wmalloc.h"

#define CTEST_MAIN

#define CTEST_SEGFAULT
//#define CTEST_NO_COLORS
#define CTEST_COLOR_OK

#include "ctest.h"

/*****************************************************************************/

CTEST(wmalloc, malloc_zero_bytes) {
    void *ptr = wmalloc(0);
    ASSERT_NULL(ptr);
}

CTEST(wmalloc, free_null) {
    wfree(NULL);
}

CTEST(wmalloc, malloc_1_byte) {
    void *ptr = wmalloc(1);
    ASSERT_NOT_NULL(ptr);
    ASSERT_TRUE(vmalloc_is_aligned(ptr));
    wfree(ptr);
}

CTEST(wmalloc, malloc_4K) {
    void *ptr = wmalloc(4 * 1024);
    ASSERT_NOT_NULL(ptr);
    ASSERT_TRUE(vmalloc_is_aligned(ptr));
    wfree(ptr);
}

CTEST(wmalloc, malloc_256K) {
    void *ptr = wmalloc(256 * 1024);
    ASSERT_NOT_NULL(ptr);
    ASSERT_TRUE(vmalloc_is_aligned(ptr));
    wfree(ptr);
}

CTEST(wmalloc, malloc_128M) {
    void *ptr = wmalloc(128 * 1024 * 1024);
    ASSERT_NOT_NULL(ptr);
    ASSERT_TRUE(vmalloc_is_aligned(ptr));
    wfree(ptr);
}

/*****************************************************************************/

CTEST(utility, page_size) {
    int actual_page_size = wmalloc_page_size();
    int expected_page_size = getpagesize();
    ASSERT_EQUAL(expected_page_size, actual_page_size);
}

/*****************************************************************************/

int main(int argc, const char *argv[]) {
    int result = ctest_main(argc, argv);
    return result;
}
