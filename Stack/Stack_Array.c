#include <stdio.h>
#include <stdlib.h>
#include "Stack_Array.h"

Status InitStack(Stack S) {
    S.stack_array = (Elem*) malloc(MAX_LENGTH * sizeof(Elem));
    if (!S.stack_array) {
        return ERROR;
    }
    S.top = S.bottom = 0;
    return OK;
}

Status DeleteStack(Stack S) {
    ClearStack(S);
    free(S.stack_array);
    return OK;
}

Status StackEmpty(Stack S) {
    return ((S.bottom == S.top) ? TRUE : FALSE);
}

int StackLength(Stack S) {
    return S.top - S.bottom;
}

Status ClearStack(Stack S) {
    S.bottom = S.top;
    return OK;
}

Status Push(Stack S, Elem e) {
    if (S.top > MAX_LENGTH) {
        S.stack_array = (Elem*) realloc(S.stack_array, (S.top + 10) * sizeof(Elem));
        // return ERROR when no more new space 
    }
    S.stack_array[S.top++] = e;
    return OK;
}

Elem Pop(Stack S) {
    if (StackEmpty(S)) {
        return S.stack_array[--S.top];
    }
    exit(ERROR);
}

int main() {
    return 0;
}