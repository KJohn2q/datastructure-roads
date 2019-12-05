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
 *  ����һ���յľ�̬���� 
 */
Status InitList(SqList *L);

/*
 *  ���پ�̬���� 
 */
Status DestroyList(SqList *L);

/*
 *  ����n������������̬���� 
 */
Status CreateList(SqList *L, int n);

/*
 *  ��վ�̬���� 
 */
Status ClearList(SqList *L);

/*
 *  ��̬�����Ƿ�Ϊ�� 
 */ 
Status ListEmpty(SqList L);

/*
 *  ��̬����ĳ��� 
 */ 
int ListLength(SqList L);

/*
 *  ���ؾ�̬�����ֵ 
 */ 
Status GetElem(SqList L, int i, ElemType *e);

/*
 *  ���ص�һ�������ֵ��ȵ�Ԫ�� 
 */
int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType));

/*
 *  ���ظ���ֵ��ǰ�� 
 */ 
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e);

/*
 *  ���ظ���ֵ�ĺ�� 
 */
Status NextElem(SqList L, ElemType cur_e, ElemType *next_e);


/*
 *  ��iλ�ò���e 
 */ 
Status ListInsert(SqList *L, int i, ElemType e);

/*
 *  ��iλ��ɾ��Ԫ�� 
 */
Status ListDelete(SqList *L, int i, ElemType *e);

/*
 *  ������ӡ��̬�����е�Ԫ�� 
 */ 
void ListTraverse(SqList L, void (Visit)(ElemType));

/*
 *  �ȽϺ��� 
 */ 
Status Compare(ElemType, ElemType);

/*
 *  ��ӡ����Ԫ�ص�ֵ 
 */ 
void Visit(ElemType);


#endif
