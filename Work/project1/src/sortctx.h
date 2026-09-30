#ifndef SORTCTX_H
#define SORTCTX_H

#include <stddef.h>

typedef struct {
    int *arr;
    size_t size;
    double elapsed_ms;
    long comparisons; 
    long moves;
} SortContext;

#endif
