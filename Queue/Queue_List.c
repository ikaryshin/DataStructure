#include <stdio.h>
#include <stdlib.h>
#include "Queue_List.h"

QueueNode InitQueue() {
    Queue Q = (QueueNode) malloc(sizeof(QueueNode));
    if (!Q) {
        exit(ERROR);
    }
    Q->next = NULL;
    return Q;
}

Status DeleteQueue(Queue Q) {
    ClearQueue(Q);
    free(Q);
    return OK;
}

Status QueueEmpty(Queue Q) {
    return (Q->next ? TRUE : FALSE);
}

int QueueLength(Queue Q) {
    int count = 0;
    for (QueueNode tmp = Q->next; tmp != NULL; tmp = tmp->next) {
        count++;
    }
    return count;
}

Status ClearQueue(Queue Q) {
    QueueNode tmp;
    QueueNode node = Q->next;
    while (node->next == NULL) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
    return OK;
}

Status EnQueue(Queue Q, Elem e) {
    QueueNode node = (QueueNode) malloc(sizeof(QueueNode));
    node->e = e;
    node->next = Q->next;
    Q->next = node;
    return OK;
}

QueueNode DeQueue(Queue Q) {
    QueueNode tmp = Q->next;
    QueueNode prev = Q;
    while (tmp->next != NULL) {
        tmp = tmp->next;
        prev = prev->next;
    }
    prev->next = NULL;
    return tmp;
}

int main() {
    QueueNode Q = InitQueue();
    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++) {
        EnQueue(Q, nums[i]);
    }
    printf("%d\n\n", QueueLength(Q)); 
    for (int i = 0; i < 10; i++) {
        printf("%d\n", DeQueue(Q)->e);
    }
}