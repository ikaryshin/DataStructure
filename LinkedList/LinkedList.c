#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

Status InitList(LinkedList L) {
    L->next = NULL;
    return OK;
}

Status DeleteList(LinkedList L) {
    ClearList(L);
    free(L);
    return OK;
}

Status ListEmpty(LinkedList L) {
    return ((L->next == NULL) ? TRUE : FALSE);
}

int ListLength(LinkedList L) {
    ListNode tmp = L;
    int length = 0;
    for (; tmp->next != NULL; tmp = tmp->next) {
        length++;
    }
    return length;
}

Status ListTraverse(LinkedList L) {
    ListNode tmp = L;
    for (; tmp->next != NULL; tmp = tmp->next) {
        printf("%d\n", tmp->e);
    }
    return OK;
}

Status ClearList(LinkedList L) {
    ListNode node = L->next;
    ListNode tmp = node;
    while (node->next != NULL) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
    return OK;
}

ListNode LocateElem(LinkedList L, Elem e) {
    ListNode tmp = L;
    for (; tmp->next != NULL; tmp = tmp->next) {
        if (tmp->e == e) {
            break;
        }
    }
    return tmp;
}

Status ListInsert(LinkedList L, int i, Elem e) {
    ListNode node = L;
    ListNode previous = L;

    for (int j = 0; j < i; j++) {
        if (!node || !previous) {
            return ERROR;
        }
        previous = node;
        node = node->next;
    }
    ListNode tmp = (ListNode) malloc(sizeof(ListNode));
    if (!tmp) {
        return ERROR;
    }
    tmp->e = e; 

    previous->next = tmp;
    tmp->next = node;
    return OK;
}

Status ListDelete(LinkedList L, int i) {
    ListNode node = L;
    ListNode previous = L;

    for (int j = 0; j < i; j++) {
        if (!node || !previous) {
            return ERROR;
        }
        previous = node;
        node = node->next;
    }

    previous->next = node->next;
    free(node);
    return OK; 
}

int main() {
    return 0;
}