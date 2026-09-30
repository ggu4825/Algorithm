#ifndef BENCH_H
#define BENCH_H

#include <stddef.h>

typedef enum {
    DATA_RANDOM,
    DATA_SORTED,
    DATA_REVERSE
} DataType;

void run_benchmark(const char *algo_name, void (*sort_fn)(int*, size_t), size_t size, DataType type);

#endif
