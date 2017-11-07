#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

LinkedList InitList(LinkedList L) {
    L = (ListNode) malloc(sizeof(ListNode));
    if (L) {
        L->next = NULL;
    }
    return L;
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
    printf("YES\n");
    for (; tmp->next != NULL; tmp = tmp->next) {
        length++;
    }
    // while (tmp->next) {
    //     length++;
    //     tmp = tmp->next;
    // }
    return length;
}

Status ListTraverse(LinkedList L) {
    ListNode tmp = L->next;
    for (; tmp != NULL; tmp = tmp->next) {
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
    LinkedList L;
    L = InitList(L);
    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++) {
        ListInsert(L, i+1, nums[i]);
    }
    ListDelete(L, 4);
    ListTraverse(L);
    return 0;
}