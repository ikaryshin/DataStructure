#include <stdio.h>
#include <stdlib.h>
#include "Stack_List.h"

StackNode InitStack(Stack S) {
    S = (StackNode) malloc(sizeof(StackNode));
    if (!S) {
        exit(ERROR);
    }
    S->next = NULL;
    return S;
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
    Stack S;
    S = InitStack(S);
    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++) {
        Push(S, nums[i]);
    }
    printf("%d\n", StackLength(S));
    for (int i = 0; i < 10; i++) {
        printf("%d\n", Pop(S)->e);
    }
    return 0;
}
