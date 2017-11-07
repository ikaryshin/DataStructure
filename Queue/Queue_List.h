#ifndef __QUEUE_LIST_H
#define __QUEUE_LIST_H

#include "../PRE_DEFINED.h"

struct Node { 
    Elem e;
    struct Node* next;
};

typedef struct Node* QueueNode;
typedef QueueNode Queue;

Status InitQueue(Queue);

Status DeleteQueue(Queue);

Status QueueEmpty(Queue);

int QueueLength(Queue);

Status ClearQueue(Queue);

Status EnQueue(Queue, Elem);

QueueNode DeQueue(Queue);

#endif