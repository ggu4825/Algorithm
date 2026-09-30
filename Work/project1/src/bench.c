#include "bench.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static void fill_data(int *arr, size_t size, DataType type) {
    for (size_t i = 0; i < size; i++) {
        if (type == DATA_RANDOM) arr[i] = rand() % 1000000;
        else if (type == DATA_SORTED) arr[i] = (int)i;
        else if (type == DATA_REVERSE) arr[i] = (int)(size - i);
    }
}

void run_benchmark(const char *algo_name, void (*sort_fn)(int*, size_t), size_t size, DataType type) {
    int *arr = (int *)malloc(size * sizeof(int));
    fill_data(arr, size, type);

    clock_t start = clock();
    sort_fn(arr, size);
    clock_t end = clock();

    double elapsed_ms = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

    const char *type_str = (type == DATA_RANDOM) ? "Random" : (type == DATA_SORTED) ? "Sorted" : "Reverse";
    printf("[%s] %s (N=%zu): %.3f ms\n", type_str, algo_name, size, elapsed_ms);

    free(arr);
}
