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
 *  λ�� 
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
 *  ǰ�� 
 */
Status PriorElem(DuLinkList D, ElemType cur_e, ElemType *e)
{
	DuLinkList p;
	
	if (D == NULL || D->next == D || D->prior == D) {
		return ERROR;
	}
	
	p = D->next;
	
	// ��һ��Ԫ��û��ǰ�� 
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
 *  ��� 
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
	
	// ���һ��Ԫ��û�к�� 
	if (p->next == D) {
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
 *  ɾ��Ԫ�� 
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
	
	printf("\n");
	
	return OK;
}

/*
 *  ��ȡѭ�������е�i��Ԫ�ص�����
 *  
 *  ע��
 *  1. ��static�ĺ����ǵ�ǰ����ֻ��DuLinkList��ʹ�ã����ᱻ����ļ�����
 *  2. ����������Ϊlen,����Ҫ��ȡ��len+1��Ԫ�ص�����ʱ������������ѭ���������Է��ص���ͷ��� 
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
	
	// ���ˣ�˵��p->next == L,��ʱ��Ҫ�ж�i�Ƿ���� 
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
