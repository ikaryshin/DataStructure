#ifndef __STACK_LIST_H
#define __STACK_LIST_H

#include "../PRE_DEFINED.h"

#define MAX_LENGTH 256

struct Node{
    Elem e;
    struct Node* next;
};

typedef struct Node* StackNode;
typedef StackNode Stack;

Status InitStack(Stack);

Status DeleteStack(Stack);

Status StackEmpty(Stack);

int StackLength(Stack);

Status ClearStack(Stack);

Status Push(Stack, Elem);

StackNode Pop(Stack);

#endif