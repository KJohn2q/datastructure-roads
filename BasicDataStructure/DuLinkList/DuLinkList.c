#include <stdio.h>
#include <stdlib.h>
#include "DuLinkList.h"

/*
 *  初始化 
 */
Status InitList(DuLinkList *D)
{
	*D = (DuLinkList) malloc(sizeof(DuLNode));
	
	if ((*D) == NULL) {
		exit(OVERFLOW);
	}
	
	(*D)->prior = *D;
	(*D)->next = *D;
	
	return OK;
}


/*
 *  销毁 
 */ 
Status DestroyList(DuLinkList *D)
{
	DuLinkList p;
	
	if ((*D) == NULL || D == NULL) {
		return ERROR;
	}
	
	ClearList(*D);
	
	free(*D);
	
	*D = NULL;
	
	return OK;
}

/*
 *  清空 
 */ 
Status ClearList(DuLinkList D)
{
	DuLinkList p, q;
	
	if (D == NULL) {
		return ERROR;
	}
	
	p = D->next;
	
	while (p != D) {
		q = p->next;
		free(p);
		p = q;
	}
	
	D->next = D->prior = D;
	
	return OK;
}

/*
 *  判断是否为空 
 */
Status ListEmpty(DuLinkList D) 
{
	return (D == NULL || D->next == D || D->prior == D) ? TRUE:FALSE;
}

/*
 *  双向循环链表的长度 
 */ 
int ListLength(DuLinkList D)
{
	DuLinkList p;
	int i = 0;
	
	if (D == NULL || D->next == D || D->prior == D) {
		return ERROR;
	}
	
	p = D->next;
	
	while (p != D) {
		p = p->next;
		++i;
	}
	
	return i;
}

/*
 *  取值 
 */ 
Status GetElem(DuLinkList D, int i, ElemType *e)
{
	DuLinkList p;
	int j = 1;
	
	if (D == NULL || D->next == D || D->prior == D) {
		return ERROR;
	}
	
	p = D->next;
	
	while (p != D && j < i) {
		p = p->next;
		++j; 
	}
	
	if (p == D || j > i) {
		return ERROR;
	}
	
	*e = p->data;
	
	return OK;
}

/*
 *  位置 
 */ 
int LocateElem(DuLinkList D, ElemType e, Status (Compare)(ElemType, ElemType))
{
	DuLinkList p;
	int i = 1;
	
	if (D == NULL || D->next == D || D->prior == D) {
		return ERROR;
	}
	
	p = D->next;
	
	while (p != D && !Compare(p->data, e)) {
		p = p->next;
		++i;
	}
	
	if (p != D) {
		return i;
	} else {
		return 0;
	}
}

/*
 *  前驱 
 */
Status PriorElem(DuLinkList D, ElemType cur_e, ElemType *e)
{
	DuLinkList p;
	
	if (D == NULL || D->next == D || D->prior == D) {
		return ERROR;
	}
	
	p = D->next;
	
	// 第一个元素没有前驱 
	if (p->data == cur_e) {
		return ERROR;
	}
	
	p = p->next;
	
	while (p != D && p->data != cur_e) {
		p = p->next;
	}
	
	if (p == D) {
		return ERROR;
	}
	
	*e = p->prior->data;
	
	return OK;
}

/*
 *  后继 
 */
Status NextElem(DuLinkList D, ElemType cur_e, ElemType *e)
{
	DuLinkList p;
	
	if (D == NULL || D->next == D || D->prior == D) {
		return ERROR;
	}
	
	p = D;
	
	while (p->next != D && p->data != cur_e) {
		p = p->next;
	}
	
	// 最后一个元素没有后继 
	if (p->next == D) {
		return ERROR;
	}
	
	*e = p->next->data;
	
	return OK;
}

/*
 *  元素插入 
 */ 
Status ListInsert(DuLinkList D, int i, ElemType e)
{
	DuLinkList p,node;
	
	if (D == NULL) {
		return ERROR;
	}
	
	if ((p = GetElemP(D, i)) == NULL) {
		return ERROR;
	}
	
	node = (DuLinkList) malloc(sizeof(DuLNode));
	
	if (node == NULL) {
		exit(OVERFLOW);
	}
	
	node->data = e;
	node->next = p;
	node->prior = p->prior;
	p->prior->next = node;
	p->prior = node;
	
	return OK;
}

/*
 *  删除元素 
 */ 
Status ListDelete(DuLinkList D, int i, ElemType *e)
{
	DuLinkList p,node;
	int j = 1;
	
	if (D == NULL || D->next == D || D->prior == D) {
		return ERROR;
	}
	
	if ((p = GetElemP(D, i)) == NULL) {
		return ERROR;
	} 
	
	if (p == D) {
		return ERROR;
	}
	
	*e = p->data;
	
	p->prior->next = p->next;
	p->next->prior = p->prior;
	
	free(p);
	
	return OK;
}

/*
 *  遍历链表 
 */ 
Status ListTraverse(DuLinkList D, void (Visit)(ElemType))
{
	DuLinkList p;
	
	if (D == NULL || D->next == D || D->prior == D) {
		return ERROR;
	}
	
	p = D->next;
	
	while (p != D) {
		Visit(p->data);
		p = p->next;
	}
	
	printf("\n");
	
	return OK;
}

/*
 *  获取循环链表中第i个元素的引用
 *  
 *  注意
 *  1. 加static的含义是当前函数只在DuLinkList中使用，不会被别的文件引用
 *  2. 假设链表长度为len,且需要获取第len+1个元素的引用时，由于这里是循环链表，所以返回的是头结点 
 */
static DuLinkList GetElemP(DuLinkList D, int i) 
{
	DuLinkList p;
	int count;
	
	if (D == NULL) {
		return ERROR;
	}
	
	p = D;
	count = 0;
	
	while (p->next != D && count < i) {
		p = p->next;
		++count;
	}
	
	if (count = i) {
		return p;
	}
	
	// 至此，说明p->next == L,此时需要判断i是否过大 
	if (count + 1 < i) {
		return NULL;
	}
	
	return D; 
}
 
Status Compare(ElemType data, ElemType e)
{
	return data == e ? TRUE:FALSE; 
}

void Visit(ElemType data)
{
	printf("%d ", data);
}
