#include <stdio.h>
#include <stdlib.h>
#include "Stack_List.h"

Status InitStack(Stack S) {
    S->next = NULL;
    return OK;
}

Status DeleteStack(Stack S) {
    ClearStack(S);
    free(S);
    return OK;
}

Status StackEmpty(Stack S) {
    return ((S->next == NULL) ? TRUE : FALSE);
}

int StackLength(Stack S) {
    int count = 0;
    for (StackNode tmp = S->next; tmp != NULL; tmp = tmp->next) {
        count++;
    }
    return count;
}

Status ClearStack(Stack S) {
    StackNode tmp = S;
    StackNode node = S;
    while (node->next != NULL) {
        node = node->next;
        free(tmp);
    }
    return OK;
}

Status Push(Stack S, Elem e) {
    StackNode node = (StackNode) malloc(sizeof(StackNode));
    if (!node) {
        return ERROR;
    }
    node->e = e;
    node->next = S->next;
    S->next = node;
    return OK;
}

StackNode Pop(Stack S) {
    StackNode tmp = S->next;
    if (!StackEmpty(S)) {
        S->next = tmp->next;
    }
    return tmp;
}

int main() {
    return 0;
}
