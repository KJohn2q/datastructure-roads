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

Status InitList(LinkList *L);

Status CreateList(LinkList *L, int n);

Status DestroyList(LinkList *L);

Status ClearList(LinkList L);

Status ListEmpty(LinkList L);

int ListLength(LinkList L);

Status GetElem(LinkList L, i, ElemType *e);

int LocateElem(L, e, (int *)(Compare)(ElemType, ElemType));

Status PriorElem(L, cur_e, *pre_e);

Status NextElem(L, cur_e, *next_e);

Status ListInser(*L, i, e);

Status ListDelete(*L, i, *e);

void ListTraverse(L, (void *)(Visit)(ElemType));



