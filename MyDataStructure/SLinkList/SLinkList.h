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
 *  ��ʼ�����ÿռ� 
 *  ��һά����space�и���������һ����������,space[0].curΪͷָ�� 
 */
void InitSpace(SLinkList *space);

/*
 *  ����ռ� 
 * �����ÿռ�����ǿգ��򷵻ط���Ľڵ��±꣬���򷵻�0 
 */ 
int Malloc(SLinkList *space);

/*
 *  ���տռ� 
 *  ���±�Ϊk�Ŀ��нڵ���յ��������� 
 */ 
void Free(SLinkList *space, int k);

/*
 *  ����һ���յľ�̬���� 
 */
Status InitList(SLinkList *s);

/*
 *  ���پ�̬���� 
 */
Status DestroyList(SLinkList *s);

/*
 *  ����n������������̬���� 
 */
Status CreateList(SLinkList s, int n);

/*
 *  ��վ�̬���� 
 */
Status ClearList(SLinkList s);

/*
 *  ��̬�����Ƿ�Ϊ�� 
 */ 
Status ListEmpty(SLinkList s);

/*
 *  ��̬����ĳ��� 
 */ 
int ListLength(SLinkList s);

/*
 *  ���ؾ�̬�����ֵ 
 */ 
Status GetElem(SLinkList s, int i, ElemType *e);

/*
 *  ���ص�һ�������ֵ��ȵ�Ԫ�� 
 */
int LocateElem(SLinkList s, ElemType e, Status(Compare)(ElemType, ElemType));

/*
 *  ���ظ���ֵ��ǰ�� 
 */ 
Status PriorElem(SLinkList s, ElemType cur_e, ElemType *pre_e);

/*
 *  ���ظ���ֵ�ĺ�� 
 */
Status NextElem(SLinkList s, ElemType cur_e, ElemType *next_e);


/*
 *  ��iλ�ò���e 
 */ 
Status ListInsert(SLinkList *s, int i, ElemType e);

/*
 *  ��iλ��ɾ��Ԫ�� 
 */
Status ListDelete(SLinkList *s, int i, ElemType *e);

/*
 *  ������ӡ��̬�����е�Ԫ�� 
 */ 
void ListTraverse(SLinkList s, void (Visit)(ElemType));

/*
 *  �ȽϺ��� 
 */ 
Status Compare(ElemType, ElemType);

/*
 *  ��ӡ����Ԫ�ص�ֵ 
 */ 
void Visit(ElemType);


#endif
