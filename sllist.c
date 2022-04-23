#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "sllist.h"
#include "utils.h"

SLL *sll_create(size_t size) {
    SLL *sll = (SLL*)malloc(sizeof(SLL));
    sll->size = size;
    sll->count = 0;
    sll->head = NULL;
    sll->tail = NULL;
    return sll;
}

SLL *sll_toSLL(int *arr, size_t size) {
    SLL *sll = sll_create(size);
    for (size_t i = 0; i < size; i++) {
        sll_append(sll, arr[i]);
    }
    return sll;
}

SLL_N *sll_getNode(SLL *sll, int pos) {
    if (sll_size(sll) == -1) return NULL;
    pos = toPosIdx(sll->count + 1, pos);
    SLL_N *node = sll->head;
    while (node != NULL && pos > 1) {
        node = sll_next(node);
        pos--;
    }
    return node;
}

SLL_N *sll_next(SLL_N *node) {
    if (node == NULL) return NULL;
    return node->next;
}

SLL_N *sll_createNode(int value) {
    SLL_N *slln = (SLL_N*)malloc(sizeof(SLL_N));
    slln->value = value;
    slln->next = NULL;
    return slln;
}

void sll_append(SLL *sll, int value) {
    if (sll_size(sll) == 1) return;
    SLL_N *newNode = sll_createNode(value);
    sll->count++;
    if (sll->head == NULL) {
        sll->head = newNode;
        sll->tail = newNode;
        return;
    } else {
        sll->tail->next = newNode;
        sll->tail = newNode;
    }
}

void sll_insert(SLL *sll, int value, int pos) {
    if (sll_size(sll) == 1) return;
    pos = toPosIdx(sll->count + 1, pos);
    SLL_N *node = sll->head, *newNode = sll_createNode(value);
    sll->count++;
    if (pos == 0 || node == NULL) {
        newNode->next = node;
        sll->head = newNode;
        return;
    }
    while (sll_next(node) != NULL && pos > 1) {
        node = sll_next(node);
        pos--;
    }
    newNode->next = sll_next(node);
    node->next = newNode;
    if (sll_next(newNode) == NULL) {
        sll->tail = newNode;
    }
}

void sll_print(SLL *sll) {
    SLL_N *node = sll->head;
    while (node != NULL) {
        printf("%d ", node->value);
        node = sll_next(node);
    }
}

void sll_destroy(SLL *sll) {
    SLL_N *node = sll->head, *next;
    while (node != NULL) {
        next = sll_next(node);
        free(node);
        node = next;
    }
    free(sll);
}

void sll_remove(SLL *sll, int pos) {
    if (sll_size(sll) == -1) return;
    pos = toPosIdx(sll->count - 1, pos);
    sll->count--;
    SLL_N *node = sll->head, *next = sll_next(node);
    if (pos == 0) {
        sll->head = next;
        free(node);
        return;
    }
    while (sll_next(node) != NULL && pos > 1) {
        node = next;
        next = sll_next(node);
        pos--;
    }
    node->next = next->next;
    free(next);
    if (node->next == NULL) {
        sll->tail = node;
    }
}

int sll_has(SLL *sll, int value) {
    if (sll_size(sll) == -1) return 0;
    SLL_N *node = sll->head;
    while (node != NULL) {
        if (node->value == value) return 1;
        node = sll_next(node);
    }
    return 0;
}

int sll_size(SLL *sll) {
    if (sll->count == 0) return -1;
    if (sll->count == sll->size) return 1;
    return 0;
}

int *sll_toArray(SLL *sll) {
    int *arr = (int*)calloc(sll->count, sizeof(int));
    SLL_N *node = sll->head;
    for (size_t i = 0; i < sll->count && node != NULL; i++) {
        arr[i] = node->value;
        node = sll_next(node);
    }
    return arr;
}