#include "sort.h"
#include "sortctx.h"
#include <stdlib.h>

static void merge_ctx(SortContext *ctx, size_t left, size_t mid, size_t right) {
    int *arr = ctx->arr;
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (size_t i = 0; i < n1; i++) { L[i] = arr[left + i]; ctx->moves++; }
    for (size_t j = 0; j < n2; j++) { R[j] = arr[mid + 1 + j]; ctx->moves++; }

    size_t i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        ctx->comparisons++;
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
            ctx->moves++;
        } else {
            arr[k++] = R[j++];
            ctx->moves++;
        }
    }
    while (i < n1) { arr[k++] = L[i++]; ctx->moves++; }
    while (j < n2) { arr[k++] = R[j++]; ctx->moves++; }

    free(L);
    free(R);
}

static void merge_sort_rec_ctx(SortContext *ctx, size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;
        merge_sort_rec_ctx(ctx, left, mid);
        merge_sort_rec_ctx(ctx, mid + 1, right);
        merge_ctx(ctx, left, mid, right);
    }
}

void merge_sort_ctx(SortContext *ctx) {
    if (ctx->size > 1) {
        merge_sort_rec_ctx(ctx, 0, ctx->size - 1);
    }
}

void merge_sort(int *arr, size_t n) {
    SortContext ctx = { .arr = arr, .size = n, .comparisons = 0, .moves = 0 };
    merge_sort_ctx(&ctx);
}
