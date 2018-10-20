/**
 * @file wmalloc.h 
 * wmalloc header file.
 */

#include <stdlib.h>

/* Memory allocation functions. */
void *wmalloc(size_t size);
void wfree(void *ptr);
