#include "sort.h"

void insertion_sort(int *arr, size_t n) {
    for (size_t i = 1; i < n; i++) {
        int key = arr[i];
        long j = (long)i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
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
