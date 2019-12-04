#ifndef LINKLIST_H
#define LINKLIST_H

#include <stdio.h>
#include <stdlib.h>   
#include "../common.h"

typedef int ElemType;

/* 
 * LNode ��ʾ����ڵ�
 * LinkList ��ʾָ�������ָ�� 
 */
typedef struct LNode {
	ElemType data;
	struct LNode *next;
} LNode, * LinkList;   

/*
 *  ��ʼ������ 
 */ 
Status InitList(LinkList *L);

/*
 *  �������� 
 */ 
Status CreateList(LinkList L, int n);

/*
 *  �������� 
 */ 
Status DestroyList(LinkList *L);

/*
 *  ������� 
 */
Status ClearList(LinkList L);

/*
 *  �����Ƿ�Ϊ�� 
 */ 
Status ListEmpty(LinkList L);

/*
 *  ����ĳ��� 
 */ 
int ListLength(LinkList L);

/*
 *  ���������iλ��Ԫ�ص�ֵ����ֵ��e 
 */ 
Status GetElem(LinkList L, int i, ElemType *e);

/*
 *  ��������������ֵ��ȵ�Ԫ�ص�λ�� 
 */ 
int LocateElem(LinkList L, ElemType e, Status (Compare)(ElemType, ElemType));

/*
 *  �鿴�����и���Ԫ�ص�ǰ�� 
 */ 
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e);

/*
 *  �鿴�����и���Ԫ�صĺ�׺ 
 */ 
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e);

/*
 *  ��������ָ��λ�ò���Ԫ�� 
 */
Status ListInsert(LinkList L, int i, ElemType e);
/*
 *  ɾ��������ָ��Ԫ�� 
 */
Status ListDelete(LinkList L, int  i, ElemType *e);
/*
 *  �������� 
 */
void ListTraverse(LinkList L, void (Visit)(ElemType));

/*
 *  �Ƚϸ���������ֵ �Ƿ���� 
 */
Status Compare(ElemType, ElemType);

/*
 *  ��ӡԪ�ص�ֵ 
 */ 
void Visit(ElemType data);

#endif



