#include <stdio.h>
#include <stdlib.h>
#include "DuLinkList.h"

/*
 *  ��ʼ�� 
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
 *  ���� 
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
 *  ��� 
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
 *  �ж��Ƿ�Ϊ�� 
 */
Status ListEmpty(DuLinkList D) 
{
	return (D == NULL || D->next == D || D->prior == D) ? TRUE:FALSE;
}

/*
 *  ˫��ѭ������ĳ��� 
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
 *  ȡֵ 
 */ 
Status GetElem(DuLinkList D, int i, ElemType *e)
{
	DuLinkList p;
	int j = 0;
	
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
 *  λ�� 
 */ 
int LocateElem(DuLinkList D, ElemType e, Status (Compare)(ElemType, ElemType))
{
	DuLinkList p;
	int i = 0;
	
	if (D == NULL || D->next == D || D->prior == D) {
		return ERROR;
	}
	
	p = D->next;
	
	while (p != D && !Compare(p->data, e)) {
		p = p->next;
		++i;
	}
	
	if (p == D) {
		return ERROR;
	}
	
	return i;
}

/*
 *  ǰ�� 
 */
Status PriorElem(DuLinkList D, ElemType cur_e, ElemType *e)
{
	DuLinkList p;
	
	if (D == NULL || D->next == D || D->prior == D) {
		return ERROR;
	}
	
	p = D->next;
	
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
 *  ��� 
 */
Status NextElem(DuLinkList D, ElemType cur_e, ElemType *e)
{
	DuLinkList p;
	
	if (D == NULL || D->next == D || D->prior == D) {
		return ERROR;
	}
	
	p = D->next;
	
	while (p != D && p->data != cur_e) {
		p = p->next;
	}
	
	if (p == D) {
		return ERROR;
	}
	
	*e = p->next->data;
	
	return OK;
}

/*
 *  Ԫ�ز��� 
 */ 
Status ListInsert(DuLinkList D, int i, ElemType e)
{
	DuLinkList p,node;
	int j = 0;
	
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
 *  ɾ��Ԫ�� 
 */ 
Status ListDelete(DuLinkList D, int i, ElemType *e)
{
	DuLinkList p,node;
	int j = 0;
	
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
	
	p->prior->next = p->next;
	p->next->prior = p->prior;
	*e = p->data;
	
	return OK;
}

/*
 *  �������� 
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
	
	return OK;
}
 
Status Compare(ElemType data, ElemType e)
{
	return data == e ? TRUE:FALSE; 
}

void Visit(ElemType data)
{
	printf("%d ", data);
}
