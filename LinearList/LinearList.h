#ifndef __LINEARLIST_H
#define __LINEARLIST_H

#define MAX_LENGTH 128

#define FALSE 0 
#define TRUE 1
#define OVERFLOW 0
#define OK 0
#define ERROR 1 

typedef int Status;
typedef int Elem;

typedef struct {
    Elem* array_list;
    int length;
} List;

Status InitList(List*);

Status DestroyList(List*);

Status ListEmpty(List);

int ListLength(List);

int LocateElem(List, Elem*);

Status ListTraverse(List);

Status ClearList(List*);

Status ListInsert(List*, int, Elem);

Status ListDelete(List*, int, Elem*);
#endif