#ifndef SQLIST_H
#define SQLIST_H

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#include "../common.h"

typedef int ElemType;

typedef struct{
	ElemType *elem; // 元素基址 
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

/*
 *  输入n个数，创建线性表 
 */
Status CreateList(SqList *L, int n);

Status ClearList(SqList *L);

Status ListEmpty(SqList L);

int ListLength(SqList L);

Status GetElem(SqList L, int i, ElemType *e);

/*
 *  返回第一个与给定值相等的元素 
 */
int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType));

Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e);

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e);

Status ListInsert(SqList *L, int i, ElemType e);

Status ListDelete(SqList *L, int i, ElemType *e);

void ListTraverse(SqList L, void (Visit)(ElemType));

/*
 *  比较函数 
 */ 
Status Compare(ElemType, ElemType);

/*
 *  打印给定元素的值 
 */ 
void Visit(ElemType);

#endif




