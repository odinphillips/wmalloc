/**
 * @file wmalloc.h 
 * wmalloc header file.
 */

#include <stdlib.h>

/* Memory allocation functions. */
void *wmalloc(size_t size);
void wfree(void *ptr);

/* Utility functions */
int wmalloc_page_size(void);