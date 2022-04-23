#ifndef _SLL_H
#define _SLL_H

    #include <stddef.h>

    // The individual nodes of the linked list
    typedef struct _SLL_N {
        int value;
        struct _SLL_N *next;
    } SLL_N;

    // A meta llist structure containing info about the size
    typedef struct _SLL {
        size_t size, count;
        SLL_N *head, *tail;
    } SLL;

    // Creates an SLL
    SLL *sll_create(size_t size);
    // Converts an array to an SLL
    SLL *sll_toSLL(int *arr, size_t size);
    // Returns a node at a specified position
    SLL_N *sll_getNode(SLL *sll, int pos);
    // Gets the next node of a given node
    SLL_N *sll_next(SLL_N *node);
    // Creates an SLL Node
    SLL_N *sll_createNode(int value);
    // Adds a value to the end
    void sll_append(SLL *sll, int value);
    // Inserts a value at a specified position
    void sll_insert(SLL *sll, int value, int pos);
    // Prints an SLL
    void sll_print(SLL *sll);
    // Frees an SLL
    void sll_destroy(SLL *sll);
    // Removes a value at the specified position
    void sll_remove(SLL *sll, int pos);
    // Returns a 1 if the given value exists
    int sll_has(SLL *sll, int value);
    // Returns a -1 if the llist is empty, 1 if it's full, and 0 if it's neither
    int sll_size(SLL *sll);
    // Converts an SLL to an array of length sll.count
    int *sll_toArray(SLL *sll);

#endif // _SLL_H