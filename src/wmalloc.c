/**
 * @file wmalloc.c
 * wmalloc implementation file.
 */

#include "wmalloc.h"

/**
 * Allocates memory.
 * 
 * @param  size Memory buffer size to allocate in bytes.
 * @return      A pointer to the newly allocated memory.
 */
void *wmalloc(size_t size) {
    (void)size;
    return NULL;
}

/**
 * Frees memory.
 * 
 * @param ptr Pointer to a previously allocated memory buffer to be freed.
 */
void wfree(void *ptr) {
    (void)ptr;
}
