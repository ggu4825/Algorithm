#include "sort.h"
#include "sortctx.h"

void insertion_sort_ctx(SortContext *ctx) {
    int *arr = ctx->arr;
    size_t n = ctx->size;

    for (size_t i = 1; i < n; i++) {
        int key = arr[i];
        ctx->moves++;

        long j = (long)i - 1;
        while (j >= 0) {
            ctx->comparisons++;
            if (arr[j] > key) {
                arr[j + 1] = arr[j];
                ctx->moves++;
                j--;
            } else {
                break;
            }
        }
        arr[j + 1] = key;
        ctx->moves++;
    }
}

void insertion_sort(int *arr, size_t n) {
    SortContext ctx = { .arr = arr, .size = n, .comparisons = 0, .moves = 0 };
    insertion_sort_ctx(&ctx);
}
