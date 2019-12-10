#include <stdio.h>
#include "CLinkList.h" 

/*
 *  ��ʼ�� 
 */
Status InitList(CLinkList* C)
{
	(*C) = (CLinkList) malloc(sizeof(CLNode));
	
	if ((*C) == NULL) {
		exit(OVERFLOW);
	}
	
	*C->next = NULL;
	
	return OK;
}

/*
 *  ���� 
 */ 
Status DestroyList(CLinkList* C)
{
 	CLinkList p = NULL;
 	
	if ((*C) == NULL) {
		exit(OVERFLOW);
	}
	
	p = *C;
	
	while (p != NULL) {
		p = (*C)->next;
		free(*C);
		*C = p;
	}
	
	*C = NULL;
	return OK;
}

/*
 * ��� 
 */  
Status ClearList(CLinkList C) {
	CLinkList p = NULL,pre = NULL;
	
	if (C == NULL) {
		exit(OVERFLOW);
	}
	
	p = C->next;
	
	while (p != NULL) {
		pre = p;
		p = p->next;
		free(pre);
	}
	
	C->next = NULL;
	
	return OK;
}

/*
 * �ж��Ƿ�Ϊ�� 
 */
Status ListEmpty(CLinkList C)
{
	return (C == NULL && C->next == NULL) ? TRUE : FALSE;
}

/*
 *  ��������ĳ��� 
 */
int ListLength(CLinkList C) 
{
	CLinkList p = NULL;
	int i = 1;
	
	if (C == NULL || C->next == NULL) {
		return 0;
	}
	
	p = C->next;
	
	while (p != C ) {
		p = p->next;	
		++i;
	}
	
	return i;
}

/*
 *  ȡֵ 
 */
Status GetElem(CLinkList C, int i, ElemType* e) 
{
	CLinkList p = NULL;
	int j = 1;
	
	if (C == NULL || C->next == NULL) {
		return ERROR;
	}	
	
	p = C->next;
	
	while (p != C &&  j < i) {
		p = p->next;
		j++;
	}
	
	if (p == C || j > i) {
		return ERROR;
	}
	
	*e = p->data;
	
	return OK;
}

/*
 *  ���� 
 */
int LocateElem(CLinkList C, ElemType e, Status(Compare)(ElemType, ElemType))
{
	CLinkList p = NULL;
	int i = 0;
	if (C == NULL || C->next == NULL) {
		return ERROR;
	}	
	
	p = C->next;
	
	while (p != C && !Compare(p->data, e) ) {
		p = p->next;
		i++;
	}
	
	if (p == C) {
		return ERROR;
	}
	
	return i;
}

/*
 *  ǰ�� 
 */
Status PriorElem(CLinkList C, ElemType cur_e, ElemType* pre_e);

/*
 *  ��׺ 
 */ 
Status NextElem(CLinkList C, ElemType cur_e, ElemType* next_e);

/*
 *  ���� 
 */
Status ListInsert(CLinkList C, int i, ElemType e);

/*
 *  ɾ�� 
 */ 
Status ListDelete(CLinkList C, int i, ElemType* e);

/*
 *  ���� 
 */ 
void ListTraverse(CLinkList C, void(Visit)(ElemType)); 

/*
 * �ȽϺ��� 
 */ 
Status Compare(ElemType, ElemType);

/*
 * ��ӡ���� 
 */
void Visit(ElemType);
