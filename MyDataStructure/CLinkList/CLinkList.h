#ifndef CLINKLIST_H
#define CLINKLIST_H

#include "../common.h"

typedef int ElemType;

typedef struct CLNode {
	ElemType data;
	struct CLNode* next;
} CLNode, *CLinkList;

/*
 *  ��ʼ�� 
 */
Status InitList(CLinkList *C);

/*
 *  �������� 
 */
Status CreateList(CLinkList C, int n);

/*
 *  ���� 
 */ 
Status DestroyList(CLinkList *C);

/*
 * ��� 
 */  
Status ClearList(CLinkList C);

/*
 * �ж��Ƿ�Ϊ�� 
 */
Status ListEmpty(CLinkList C);

/*
 *  ��������ĳ��� 
 */
int ListLength(CLinkList C);

/*
 *  ȡֵ 
 */
Status GetElem(CLinkList C, int i, ElemType* e); 

/*
 *  ���� 
 */
int LocateElem(CLinkList C, ElemType e, Status(Compare)(ElemType, ElemType));

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

#endif
