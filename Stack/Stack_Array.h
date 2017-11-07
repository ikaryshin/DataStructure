#ifndef __STACK_ARRAY_H
#define __STACK_ARRAY_H

#include "../PRE_DEFINED.h"

#define MAX_LENGTH 256

typedef struct {
    Elem* stack_array;
    int top;
    int bottom;
} Stack;

Status InitStack(Stack*);

Status DeleteStack(Stack*);

Status StackEmpty(Stack*);

int StackLength(Stack*);

Status ClearStack(Stack*);

Status Push(Stack*, Elem);

Elem Pop(Stack*);

#endif
