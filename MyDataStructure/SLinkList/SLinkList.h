#ifndef SLINKLIST_H
#define SLINKLIST_H

#define MAXSIZE 100

#include "../common.h"

typedef int ElemType;

typedef struct{
	ElemType data;
	int cur; 
}SLinkList[MAXSIZE];

/*
 *  构造一个空的静态链表 
 */
Status InitList(SqList *L);

/*
 *  销毁静态链表 
 */
Status DestroyList(SqList *L);

/*
 *  输入n个数，创建静态链表 
 */
Status CreateList(SqList *L, int n);

/*
 *  清空静态链表 
 */
Status ClearList(SqList *L);

/*
 *  静态链表是否为空 
 */ 
Status ListEmpty(SqList L);

/*
 *  静态链表的长度 
 */ 
int ListLength(SqList L);

/*
 *  返回静态链表的值 
 */ 
Status GetElem(SqList L, int i, ElemType *e);

/*
 *  返回第一个与给定值相等的元素 
 */
int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType));

/*
 *  返回给定值的前驱 
 */ 
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e);

/*
 *  返回给定值的后继 
 */
Status NextElem(SqList L, ElemType cur_e, ElemType *next_e);


/*
 *  在i位置插入e 
 */ 
Status ListInsert(SqList *L, int i, ElemType e);

/*
 *  在i位置删除元素 
 */
Status ListDelete(SqList *L, int i, ElemType *e);

/*
 *  遍历打印静态链表中的元素 
 */ 
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
