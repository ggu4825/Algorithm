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

        // Random Data Benchmark
        run_benchmark("Insertion Sort", insertion_sort, n, DATA_RANDOM);
        run_benchmark("Merge Sort    ", merge_sort, n, DATA_RANDOM);
        run_benchmark("Timsort       ", tim_sort, n, DATA_RANDOM);

        printf("\n");
    }

    return 0;
}
