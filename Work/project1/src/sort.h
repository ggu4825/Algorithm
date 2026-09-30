#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include "sortctx.h"

void insertion_sort(int *arr, size_t n);
void merge_sort(int *arr, size_t n);
void tim_sort(int *arr, size_t n);

void insertion_sort_ctx(SortContext *ctx);
void merge_sort_ctx(SortContext *ctx);
void tim_sort_ctx(SortContext *ctx);

#endif
