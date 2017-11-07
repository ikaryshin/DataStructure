#ifndef __QUEUE_ARRAY_H
#define __QUEUE_ARRAY_H

#include "../PRE_DEFINED.h"

#define MAX_LENGTH 256

typedef struct {
    Elem queue_array[MAX_LENGTH];
    int front;
    int rear;
} Queue;

Status InitQueue(Queue);

Status DeleteQueue(Queue);

Status QueueEmpty(Queue);

int QueueLength(Queue);

Status ClearQueue(Queue);

Status EnQueue(Queue, Elem);

Elem DeQueue(Queue);

#endif