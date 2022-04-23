#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

Stack *stack_create(size_t size) {
    if (size == 0) return NULL;
    Stack *stk = (Stack*)malloc(sizeof(Stack));
    if (stk == NULL) return NULL;
    stk->stk = (int*)calloc(size, sizeof(int));
    if (stk->stk == NULL) {
        free(stk);
        return NULL;
    }
    stk->stkPtr = stk->stk - 1;
    stk->stkEnd = stk->stk + size - 1;
    return stk;
}

void stack_push(Stack *stack, int value) {
    if (stack_full(stack)) return;
    *(++stack->stkPtr) = value;
}

void stack_destroy(Stack *stack) {
    free(stack->stk);
    free(stack);
}

void stack_print(Stack *stack) {
    for (int *i = stack->stk; i <= stack->stkPtr; i++) {
        printf("%d ", *i);
    }
}

int *stack_pop(Stack *stack) {
    if (stack_empty(stack)) return NULL;
    return stack->stkPtr--;
}

int *stack_peek(Stack *stack) {
    if (stack_empty(stack)) return NULL;
    return stack->stkPtr;
}

int stack_empty(Stack *stack) {
    return stack->stkPtr < stack->stk;
}

int stack_full(Stack *stack) {
    return stack->stkPtr == stack->stkEnd;
}
