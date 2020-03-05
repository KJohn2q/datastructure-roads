#ifndef DULINKLIST_H
#define DULINKLIST_H 

#include "../common.h"

typedef struct DuLNode {
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
} DuLNode, * DuLinkList;

Status InitList(DuLinkList *D);

Status DestroyList(DuLinkList *D);

Status ClearList(DuLinkList D);

int ListLength(DuLinkList D);

Status GetElem(DuLinkList D, int i, ElemType *e);

int LocateElem(DuLinkList D, ElemType e, Status (Compare)(ElemType, ElemType));

Status PriorElem(DuLinkList D, ElemType cur_e, ElemType *e);

Status NextElem(DuLinkList D, ElemType cur_e, ElemType *e);

Status ListInsert(DuLinkList D, int i, ElemType e);

Status ListDelete(DuLinkList D, int i, ElemType *e);

Status ListTraverse(DuLinkList D, void (Visit)(ElemType));

/*
 *  获取循环链表中第i个元素的引用
 *  
 *  注意
 *  1. 加static的含义是当前函数只在DuLinkList中使用，不会被别的文件引用
 *  2. 假设链表长度为len,且需要获取第len+1个元素的引用时，由于这里是循环链表，所以返回的是头结点 
 */
static DuLinkList GetElemP(DuLinkList D, int i);

Status Compare(ElemType, ElemType);

void Visit(ElemType);

#endif
