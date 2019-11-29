#ifndef SQLIST_H
#define SQLIST_H

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#include "../common.h"

typedef int ElemType;

typedef struct{
	ElemType * elem; // Ԫ�ػ�ַ 
	int    length;  // ���Ա�ĳ��� 
	int    listsize;  // ���Ա��ַ 
}SqList;

/*
 *  ����һ���յ����Ա� 
 */
Status InitList(SqList *L);

/*
 *  �������Ա� 
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




