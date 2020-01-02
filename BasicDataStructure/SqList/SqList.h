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

/*
 *  清空线性表 
 */
Status ClearList(SqList *L);

/*
 *  线性表是否为空 
 */ 
Status ListEmpty(SqList L);

/*
 *  线性表的长度 
 */ 
int ListLength(SqList L);

/*
 *  返回线性表的值 
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
 *  遍历打印线性表中的元素 
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

/*
 *  取 A = A和B的并集 
 */
void Union(SqList *La, SqList Lb);

/*
 * 已知线性表LA和LB中的数据按值非递减有序排列
 * 将LA和LB合并为一个新的线性表LC，且LC中的数据元素仍按值非递减有序排列 
 */
void MergeList(SqList La, SqList Lb, SqList *Lc); 

#endif




