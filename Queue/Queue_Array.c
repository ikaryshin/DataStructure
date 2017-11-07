#include <stdio.h>
#include <stdlib.h>
#include "Queue_Array.h"

Status InitQueue(Queue *Q) {
    Q->front = Q->rear = 0;
    return OK;
}

Status DeleteQueue(Queue *Q) {
    ClearQueue(Q);
    free(Q->queue_array);
    return OK;
}

Status QueueEmpty(Queue *Q) {
    return ((Q->front == Q->rear) ? TRUE : FALSE);
}

int QueueLength(Queue *Q) {
    if (Q->rear < Q->front) {
        return (MAX_LENGTH - Q->front + Q->rear - 1);
    } else {
        return (Q->rear - Q->front);
    }
}

Status ClearQueue(Queue *Q) {
    Q->front = Q->rear = 0;
    return OK;
}

Status EnQueue(Queue *Q, Elem e) {
    if (QueueLength(Q) >= MAX_LENGTH) {
        return ERROR;
    }
    if (Q->rear >= MAX_LENGTH) {
        Q->rear = 0;
    }
    Q->queue_array[Q->rear++] = e;
    return OK;
}

Elem DeQueue(Queue *Q) {
    if (QueueEmpty(Q)) {
        exit(ERROR);
    }
    return Q->queue_array[Q->front++];
}

int main() {
    Queue Q;
    InitQueue(&Q);
    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++) {
        EnQueue(&Q, nums[i]);
    }
    printf("Length: %d\n", QueueLength(&Q));
    printf("%d\n\n", QueueLength(&Q)); 
    for (int i = 0; i < 5; i++) {
        printf("%d\n", DeQueue(&Q));
    }
    printf("Length: %d\n", QueueLength(&Q));
    printf("\n");
    for (int i = 0; i < 5; i++) {
        EnQueue(&Q, nums[i]);
    }
    printf("Length: %d\n", QueueLength(&Q));
    printf("\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", DeQueue(&Q));
    }
    printf("Length: %d\n", QueueLength(&Q));
}
