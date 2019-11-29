#ifndef SQLIST_H
#define SQLIST_H

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#include "../common.h"

typedef int ElemType;

typedef struct{
	ElemType * elem; // 元素基址 
	int    length;  // 线性表的长度 
	int    listsize;  // 线性表基址 
}SqList;

/*
 *  构造一个空的线性表 
 */
Status InitList(SqList *L);

/*
 *  销毁线性表 
 */
Status DestroyList(SqList *L);

Status ClearList(SqList *L);

Status ListEmpty(SqList L);

int ListLength(SqList L);

Status GetElem(SqList L, int i, ElemType *e);

int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType));

Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e);

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e);

Status ListInsert(SqList *L, int i, ElemType e);

Status ListDelete(SqList *L, int i, ElemType *e);

void ListTraverse(SqList L, void (Visit)(ElemType));

#endif




