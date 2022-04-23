#ifndef _HEAP_H
#define _HEAP_H

    #include <stddef.h>
    
    typedef struct _Heap {
        int *arr;
        size_t size, count;
    } Heap;

    Heap *heap_create(size_t size);
    void heap_insert(Heap *heap, int value);
    void heapify(Heap *heap, int i);
    void heap_destroy(Heap *heap);
    void heap_print(Heap *heap);
    int heap_satiety(Heap *heap);
    int *heap_remove(Heap *heap, int value);

#endif // _HEAP_H