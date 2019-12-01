#ifndef SQLIST_H
#define SQLIST_H

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#include "../common.h"

typedef int ElemType;

typedef struct{
	ElemType *elem; // Ԫ�ػ�ַ 
	int    length;  // ���Ա�ĳ��� 
	int    listsize;  // ���Ա��ַ 
}SqList;

/*
 *  ����һ���յ����Ա� 
 */
Status InitList(SqList *L);

/*
 *  �������Ա� 
 */
Status DestroyList(SqList *L);

/*
 *  ����n�������������Ա� 
 */
Status CreateList(SqList *L, int n);

/*
 *  ������Ա� 
 */
Status ClearList(SqList *L);

/*
 *  ���Ա��Ƿ�Ϊ�� 
 */ 
Status ListEmpty(SqList L);

/*
 *  ���Ա�ĳ��� 
 */ 
int ListLength(SqList L);

/*
 *  �������Ա��ֵ 
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
 *  ������ӡ���Ա��е�Ԫ�� 
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

/*
 *  ȡ A = A��B�Ĳ��� 
 */
void Union(SqList *La, SqList Lb);

/*
 * ��֪���Ա�LA��LB�е����ݰ�ֵ�ǵݼ���������
 * ��LA��LB�ϲ�Ϊһ���µ����Ա�LC����LC�е�����Ԫ���԰�ֵ�ǵݼ��������� 
 */
void MergeList(SqList La, SqList Lb, SqList *Lc); 

#endif




