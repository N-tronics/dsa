#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "utils.h"

Heap *heap_create(size_t size) {
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    heap->arr = (int*)calloc(size, sizeof(int));
    heap->size = size;
    heap->count = 0;
    return heap;
}

void heap_insert(Heap *heap, int value) {
    if (heap_satiety(heap) == 1) return;
    heap->arr[heap->count++] = value;
    for (int i = heap->count / 2 - 1; i >= 0; i--)
        heapify(heap, i);
}

void heapify(Heap *heap, int i) {
    if (heap->count == 1) return;
    int largest = i,
        l = 2 * i + 1,
        r = 2 * i + 2;
    if (l < heap->count && heap->arr[l] > heap->arr[largest])
        largest = l;
    if (r < heap->count && heap->arr[r] > heap->arr[largest])
        largest = r;
    if (largest != i) {
        intSwap(heap->arr + i, heap->arr + largest);
        heapify(heap, largest);
    }
}

void heap_destroy(Heap *heap) {
    free(heap->arr);
    free(heap);
}

void heap_print(Heap *heap) {
    for (size_t i = 0; i < heap->count; i++) {
        printf("%d ", heap->arr[i]);
    }
    printf("\n");
}

int heap_satiety(Heap *heap) {
    if (heap->count == 0) return -1;
    if (heap->count == heap->size) return 1;
    return 0;
}

int *heap_remove(Heap *heap, int value) {
    int i;
    for (i = 0; i < heap->count; i++) {
        if (heap->arr[i] == value) break;
    }
    intSwap(heap->arr + i, heap->arr + heap->count - 1);
    heap->count--;
    for (i = heap->count / 2 - 1; i >= 0; i--)
        heapify(heap, i);
}