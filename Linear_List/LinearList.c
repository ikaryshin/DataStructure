// unchecked

#include <stdio.h>
#include <stdlib.h>
#include "LinearList.h"

Status InitList(List *L) {
    L->array_list = (Elem*)malloc(sizeof(Elem*) * MAX_LENGTH);
    if (L->array_list) {
        L->length = 0;
        return OK;
    }
    return ERROR;
}

Status DestroyList(List *L) {
    ClearList(L);
    free(L->array_list);
    return OK;
}

Status ListEmpty(List L) {
    return ((L.length == 0) ? TRUE : FALSE);
}

int ListLength(List L) {
    return L.length;
}

int LocateElem(List L, Elem* e) {
    int length = L.length;
    int i = 0;
    for (; i < length; i++) {
        if (L.array_list[i] == *e) {
            break;
        }
    }
    return i;
}

Status ListTraverse(List *L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d\n", L->array_list[i]);
    }
    return OK;
}

Status ClearList(List *L) {
    L->length = 0;
    return OK;
}

Status ListInsert(List *L, int i, Elem inserted) {
    if (i < 1 || i > L->length + 1) {
        return ERROR;
    } else if (L->length >= MAX_LENGTH) {
        L->array_list = (Elem*) realloc(L->array_list, (L->length+10)*sizeof(Elem));
    }
    int length = L->length;
    if (length > 0) {
        for (int j = length - 1; j >= i - 1; j--) {
            L->array_list[j+1] = L->array_list[j];
        }
    }
    L->array_list[--i] = inserted;
    L->length++;
    return OK;
}

Status ListDelete(List *L, int i, Elem *tmp) {
    // int length = L->length;
    // if (i <= L->length && i > 0) {
    //     *tmp = L->array_list[i];
    //     for (int j = i; j < L->length; i++) {
    //         L->array_list[j] = L->array_list[j+1];
    //         L->length--;
    //     }
    //     return OK;
    // }
    // return ERROR;
    int length = L->length;
    if (i <= length && i > 0) {
        *tmp = L->array_list[i-1];
        for (int j = i - 1; j < length - 1; j++) {
            L->array_list[j] = L->array_list[j+1];
        }
        L->length--;
        return OK;
    }
    return ERROR;
}

int main() {
    List L;
    InitList(&L);
    Elem p;
    int nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++) {
        ListInsert(&L, i+1, nums[i]);
    }
    ListInsert(&L, 11, 11);
    ListInsert(&L, 12, 12);
    printf("%d\n", ListLength(L));
    ListDelete(&L, 2, &p);
    ListTraverse(&L);
}