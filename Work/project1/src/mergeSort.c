#include "sort.h"
#include <stdlib.h>

static void merge(int *arr, size_t left, size_t mid, size_t right) {
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (size_t i = 0; i < n1; i++) L[i] = arr[left + i];
    for (size_t j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    size_t i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

static void merge_sort_rec(int *arr, size_t left, size_t right) {
    if (left < right) {
        size_t mid = left + (right - left) / 2;
        merge_sort_rec(arr, left, mid);
        merge_sort_rec(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge_sort(int *arr, size_t n) {
    if (n > 1) {
        merge_sort_rec(arr, 0, n - 1);
    }
}
