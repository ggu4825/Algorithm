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

void run_benchmark_ctx(const char *algo_name, void (*sort_fn)(SortContext*), size_t size, DataType type) {
    SortContext ctx = {0};
    ctx.arr = (int *)malloc(size * sizeof(int));
    ctx.size = size;

    fill_data(ctx.arr, size, type);

    clock_t start = clock();
    sort_fn(&ctx); 
    clock_t end = clock();

    ctx.elapsed_ms = ((double)(end - start) / CLOCKS_PER_SEC) * 1000.0;

    const char *type_str = (type == DATA_RANDOM) ? "Random" : (type == DATA_SORTED) ? "Sorted" : "Reverse";

    printf("[%s] %s (N=%zu)\n", type_str, algo_name, size);
    printf("  > 시간: %.3f ms | 비교: %ld 회 | 이동: %ld 회\n\n",
           ctx.elapsed_ms, ctx.comparisons, ctx.moves);

    free(ctx.arr);
}
