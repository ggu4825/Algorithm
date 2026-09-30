#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "bench.h"

int main() {
    srand((unsigned int)time(NULL));

    size_t sizes[] = {1000, 10000, 100000};
    size_t num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    printf("==========================================\n");
    printf("     Sorting Algorithm Benchmark (C)      \n");
    printf("==========================================\n\n");

    for (size_t i = 0; i < num_sizes; i++) {
        size_t n = sizes[i];
        printf("--- Dataset Size: %zu ---\n", n);

        // 1. Random Data Benchmark
        run_benchmark_ctx("Insertion Sort", insertion_sort_ctx, n, DATA_RANDOM);
        run_benchmark_ctx("Merge Sort    ", merge_sort_ctx, n, DATA_RANDOM);
        run_benchmark_ctx("Timsort       ", tim_sort_ctx, n, DATA_RANDOM);
        printf("\n");

        // 2. Sorted Data Benchmark
        run_benchmark_ctx("Insertion Sort", insertion_sort_ctx, n, DATA_SORTED);
        run_benchmark_ctx("Merge Sort    ", merge_sort_ctx, n, DATA_SORTED);
        run_benchmark_ctx("Timsort       ", tim_sort_ctx, n, DATA_SORTED);
        printf("\n");

        // 3. Reversed Data Benchmark
        run_benchmark_ctx("Insertion Sort", insertion_sort_ctx, n, DATA_REVERSE);
        run_benchmark_ctx("Merge Sort    ", merge_sort_ctx, n, DATA_REVERSE);
        run_benchmark_ctx("Timsort       ", tim_sort_ctx, n, DATA_REVERSE);
        printf("\n------------------------------------------\n\n");
    }

    return 0;
}
