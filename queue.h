#ifndef _QUEUE_H
#define _QUEUE_H

    #include <stddef.h>

    typedef struct _Queue {
        int *que, *queEnd, *front, *rear;
    } Queue;

    Queue *queue_create(size_t size);
    void queue_destroy(Queue *que);
    void queue_enqueue(Queue *que, int value);
    void queue_print(Queue *que);
    int *queue_dequeue(Queue *que);
    int queue_empty(Queue *que);
    int queue_full(Queue *que);

#endif