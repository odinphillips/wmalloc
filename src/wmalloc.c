/**
 * @file wmalloc.c
 * wmalloc implementation file.
 */

#include <unistd.h>
#include "wmalloc.h"

static int wmalloc_page_size_;

/**
 * Allocates memory.
 * 
 * @param  size Memory buffer size to allocate in bytes.
 * @return      A pointer to the newly allocated memory.
 */
void *wmalloc(size_t size) {
    if (!wmalloc_page_size_) {
        wmalloc_page_size_ = getpagesize();
    }

    if (size == 0) {
        return NULL;
    }
    return malloc(size);
}

/**
 * Frees memory.
 * 
 * @param ptr Pointer to a previously allocated memory buffer to be freed.
 */
void wfree(void *ptr) {
    free(ptr);
}

int wmalloc_page_size(void) {
    return wmalloc_page_size_;
}