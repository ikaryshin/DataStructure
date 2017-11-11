#include <stdio.h>
#include "Queue_Array.h"

Queue QueueSort(Queue* Q) {
    Queue tmp;
    Elem front;
    Elem next;
    InitQueue(&tmp);
    int length = QueueLength(Q);
    for (int i = 0; i < length - 1; i++) {
        front = DeQueue(Q);
        for (int j = 0; j < length - 1; j++) {
            next = DeQueue(Q);
            if (front > next) {
                EnQueue(Q, front);
                front = next;
            } else {
                EnQueue(Q, next);
            }
        }
        EnQueue(&tmp, front);
    }
    front = DeQueue(Q);
    EnQueue(&tmp, front);
    return tmp;
}

int main() {
    Queue Q;
    InitQueue(&Q);
    int nums[10] = {1, 3, 3, 4, 9999997, 2, 9, 0, -34, -56};
    for (int i = 0; i < 10; i++) {
        EnQueue(&Q, nums[i]);
    }
    Queue tmp = QueueSort(&Q);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", DeQueue(&tmp));
    }
    return 0;
}