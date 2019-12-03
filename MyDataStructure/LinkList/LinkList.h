#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>   
#include "../common.h"

typedef int ElemType;

typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, *LinkList;

Status InitList(LinkList L);

Status CreateList(LinkList L, int n);

Status DestroyList(LinkList L);

Status ClearList(LinkList L);

Status ListEmpty(LinkList L);

int ListLength(LinkList L);

Status GetElem(LinkList L, int i, ElemType *e);

int LocateElem(LinkList L, ElemType e, Status (Compare)(ElemType, ElemType));

Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e);

Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e);

Status ListInsert(LinkList L, int i, ElemType e);

Status ListDelete(LinkList L, int  i, ElemType *e);

void ListTraverse(LinkList L, void (Visit)(ElemType));

void Visit(ElemType data);

#endif



