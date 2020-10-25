
#include "global.h"

#ifndef STACK
    #define STACK

    #include <stdlib.h>
    #include <stdio.h>


    typedef struct node {
        StackEntry entry;
        struct node *next;
    }StackNode;

    typedef struct {
        StackNode* top;
        int size;
    }Stack;


    void CreateStack(Stack*);

    void push(StackEntry,Stack*);
    void pop(StackEntry*,Stack*);

    int StackEmpty(Stack*);
    int StackFull(Stack*);

    void TreverseStack( Stack *, void (*)(StackEntry) );

    void ClearStack(Stack*);

    int StackSize(Stack*);


#endif
