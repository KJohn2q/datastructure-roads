#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>   
#include "../common.h"

typedef int ElemType;

/* 
 * LNode 表示链表节点
 * LinkList 表示指向链表的指针 
 */
typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, * LinkList;   

/*
 *  初始化链表 
 */ 
Status InitList(LinkList *L);

/*
 *  创建链表 
 */ 
Status CreateList(LinkList L, int n);

/*
 *  销毁链表 
 */ 
Status DestroyList(LinkList *L);

/*
 *  清空链表 
 */
Status ClearList(LinkList L);

/*
 *  链表是否为空 
 */ 
Status ListEmpty(LinkList L);

/*
 *  链表的长度 
 */ 
int ListLength(LinkList L);

/*
 *  获得链表中i位置元素的值，赋值给e 
 */ 
Status GetElem(LinkList L, int i, ElemType *e);

/*
 *  获得链表中与给定值相等的元素的位置 
 */ 
int LocateElem(LinkList L, ElemType e, Status (Compare)(ElemType, ElemType));

/*
 *  查看链表中给定元素的前驱 
 */ 
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e);

/*
 *  查看链表中给定元素的后缀 
 */ 
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e);

/*
 *  向链表中指定位置插入元素 
 */
Status ListInsert(LinkList L, int i, ElemType e);
/*
 *  删除链表中指定元素 
 */
Status ListDelete(LinkList L, int  i, ElemType *e);
/*
 *  遍历链表 
 */
void ListTraverse(LinkList L, void (Visit)(ElemType));

/*
 *  比较给定的两个值 是否相等 
 */
Status Compare(ElemType, ElemType);

/*
 *  打印元素的值 
 */ 
void Visit(ElemType data);

#endif



