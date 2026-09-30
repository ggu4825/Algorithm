#ifndef BENCH_H
#define BENCH_H

#include <stddef.h>
#include "sortctx.h"

typedef enum {
    DATA_RANDOM,
    DATA_SORTED,
    DATA_REVERSE
} DataType;

void run_benchmark_ctx(const char *algo_name, void (*sort_fn)(SortContext*), size_t size, DataType type);

#endif
