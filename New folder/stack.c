#include "global.h"

#include "stack.h"

void CreateStack(Stack* stack){
    stack->top = NULL;
    stack->size = 0;
}



void push (StackEntry e, Stack* stack){
    StackNode* ps = (StackNode*)malloc(sizeof(StackNode));
    //the casting isn't necessary in c but it must exist if it was used in c++ project
    ps->entry = e;
    ps->next = stack->top;
    stack->top = ps;
    stack->size++;
}





void pop(StackEntry *e,Stack* stack){
    *e = stack->top->entry;
    StackNode *tmp = stack->top;
    stack->top = stack->top->next;// stack->top = stack->top->next
    free(tmp);
    stack->size--;
}




int StackFull(Stack* stack){
    StackNode *p = malloc(sizeof(StackNode));
    if(p == NULL){
        return 1;
    }
    else{
        free(p);
        return 0;
    }
}



int StackEmpty(Stack* stack){
    return stack->top == NULL;
}



void TreverseStack( Stack * stack, void (*fun)(StackEntry) ){

    for(StackNode * i = stack->top; i != NULL; i = i->next){
        (*fun)(i->entry);
    }

}

void ClearStack(Stack* stack){

    StackNode* tmp = stack->top;

    while(stack->top != NULL){
        stack->top = tmp->next;
        free(tmp);
        tmp = stack->top;
    }
    stack->size = 0;

}


int StackSize(Stack* stack){
    return stack->size;
}
