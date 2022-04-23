#ifndef _STACK_H
#define _STACK_H

    #include <stddef.h>

    typedef struct sStack {
        int *stk, *stkPtr, *stkEnd;
    } Stack;

    Stack *stack_create(size_t size);
    void stack_push(Stack *stack, int value);
    void stack_destroy(Stack *stack);
    void stack_print(Stack *stack);
    int *stack_pop(Stack *stack);
    int *stack_peek(Stack *stack);
    int stack_empty(Stack *stack);
    int stack_full(Stack *stack);

#endif