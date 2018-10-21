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
 * The linux set_memory_uc() function appears to work in page sizes of 4K.
 * So we'll need to allocate memory in mulitples of 4K, and aligned to 4K.
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

    void *ptr = NULL;
    int ret = posix_memalign(&ptr, (size_t)wmalloc_page_size_, size);
    
    return (ret ? NULL : ptr);
}

/**
 * Frees memory.
 * 
 * @param ptr Pointer to a previously allocated memory buffer to be freed.
 */
void wfree(void *ptr) {
    free(ptr);
}

/**
 * Get memory page size.
 * 
 * return Page size in bytes.
 */
int wmalloc_page_size(void) {
    if (!wmalloc_page_size_) {
        wmalloc_page_size_ = getpagesize();
    }
    return wmalloc_page_size_;
}

/**
 * Check memory buffer address is page aligned. Typically 4096.
 * 
 * @param  ptr Pointer to wmalloc'ed memory address.
 * @return     1 if memory is aligned, otherwise 0.
 */
int vmalloc_is_aligned(void *ptr) {
    if (!wmalloc_page_size_) {
        wmalloc_page_size_ = getpagesize();
    }
    return (((uint64_t)ptr % wmalloc_page_size_) ? 0 : 1);
}