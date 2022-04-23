#include "queue.h"
#include <stdlib.h>
#include <stdio.h>

int *queue_next(Queue *que, int *ptr) {
    /*
     * Returns a pointer to the next element in the queue.
     * If the given pointer is the last, it loops back to the start
     */
    if (ptr == que->queEnd || queue_empty(que)) return que->que;
    return ptr + 1;
}

Queue *queue_create(size_t size) {
    if (size == 0) return NULL;

    // Create the que
    Queue *que = (Queue*)malloc(sizeof(Queue));
    if (que == NULL) return NULL;
    que->que = (int*)calloc(size, sizeof(int));
    if (que->que == NULL) {
        free(que);
        return NULL;
    }
    // Initialize
    que->queEnd = que->que + size - 1;
    que->front = NULL;
    que->rear = NULL;

    return que;
}

void queue_destroy(Queue *que) {
    free(que->que);
    free(que);
}

void queue_enqueue(Queue *que, int value) {
    if (queue_full(que)) return;
    que->rear = queue_next(que, que->rear);
    *que->rear = value;
    if (que->front == NULL) que->front = que->que;
}

void queue_print(Queue *que) {
    int *i = que->front;
    while (i != que->rear) {
        printf("%d ", *i);
        i = queue_next(que, i);
    }
    printf("%d", *i);
}

int *queue_dequeue(Queue *que) {
    if (queue_empty(que)) return NULL;
    int *value = que->front;
    if (que->front == que->rear) {
        que->front = NULL;
        que->rear = NULL;
    } else {
        que->front = queue_next(que, que->front);
    }
    return value;
}

int queue_empty(Queue *que) {
    return que->front == NULL;
}

int queue_full(Queue *que) {
    return queue_next(que, que->rear) == que->front;
}