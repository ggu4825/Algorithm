#include "sort.h"
#include "sortctx.h"
#include <stdlib.h>

#define RUN 32

static size_t min_val(size_t a, size_t b) {
    return (a < b) ? a : b;
}

static void insertion_sort_slice_ctx(SortContext *ctx, size_t left, size_t right) {
    int *arr = ctx->arr;
    for (size_t i = left + 1; i <= right; i++) {
        int key = arr[i];
        ctx->moves++;
        long j = (long)i - 1;
        while (j >= (long)left) {
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

static void merge_slice_ctx(SortContext *ctx, size_t l, size_t m, size_t r) {
    int *arr = ctx->arr;
    size_t len1 = m - l + 1, len2 = r - m;
    int *left = (int *)malloc(len1 * sizeof(int));
    int *right = (int *)malloc(len2 * sizeof(int));

    for (size_t i = 0; i < len1; i++) { left[i] = arr[l + i]; ctx->moves++; }
    for (size_t i = 0; i < len2; i++) { right[i] = arr[m + 1 + i]; ctx->moves++; }

    size_t i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        ctx->comparisons++;
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
            ctx->moves++;
        } else {
            arr[k++] = right[j++];
            ctx->moves++;
        }
    }
    while (i < len1) { arr[k++] = left[i++]; ctx->moves++; }
    while (j < len2) { arr[k++] = right[j++]; ctx->moves++; }

    free(left);
    free(right);
}

void tim_sort_ctx(SortContext *ctx) {
    size_t n = ctx->size;
    for (size_t i = 0; i < n; i += RUN) {
        insertion_sort_slice_ctx(ctx, i, min_val(i + RUN - 1, n - 1));
    }

    for (size_t size = RUN; size < n; size = 2 * size) {
        for (size_t left = 0; left < n; left += 2 * size) {
            size_t mid = left + size - 1;
            size_t right = min_val((left + 2 * size - 1), (n - 1));

            if (mid < right) {
                merge_slice_ctx(ctx, left, mid, right);
            }
        }
    }
}

void tim_sort(int *arr, size_t n) {
    SortContext ctx = { .arr = arr, .size = n, .comparisons = 0, .moves = 0 };
    tim_sort_ctx(&ctx);
}
