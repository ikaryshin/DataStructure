#ifndef __LINKEDLIST_H
#define __LINKEDLIST_H

#include "../PRE_DEFINED.h"

typedef struct LinkedListNode{
    Elem e;
    struct LinkedListNode* next;
} Node;

typedef Node* ListNode;
typedef Node* LinkedList;

LinkedList InitList(LinkedList);

Status DeleteList(LinkedList);

Status ListEmpty(LinkedList);

int ListLength(LinkedList);

Status ListTraverse(LinkedList);

Status ClearList(LinkedList);

ListNode LocateElem(LinkedList, Elem);

Status ListInsert(LinkedList, int, Elem);

Status ListDelete(LinkedList, int);

#endif