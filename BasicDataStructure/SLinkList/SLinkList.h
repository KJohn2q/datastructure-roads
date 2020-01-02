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
void InitSpace(SLinkList space);

/*
 *  ����ռ� 
 * �����ÿռ�����ǿգ��򷵻ط���Ľڵ��±꣬���򷵻�0 
 */ 
int Malloc(SLinkList space);

/*
 *  ���տռ� 
 *  ���±�Ϊk�Ŀ��нڵ���յ��������� 
 */ 
void Free(SLinkList space, int k);

/*
 *  ����һ���յľ�̬���� 
 */
Status InitList(SLinkList space, int *S);

/*
 *  ���پ�̬���� 
 */
Status DestroyList(SLinkList space, int *S);

/*
 *  ��վ�̬���� 
 */
Status ClearList(SLinkList space, int S);

/*
 *  ��̬�����Ƿ�Ϊ�� 
 */ 
Status ListEmpty(SLinkList space, int S);

/*
 *  ��̬����ĳ��� 
 */ 
int ListLength(SLinkList space, int S);

/*
 *  ȡֵ 
 */ 
Status GetElem(SLinkList space, int S, int i, ElemType *e);

/*
 *  ���ص�һ�������ֵ��ȵ�Ԫ�� 
 */
int LocateElem(SLinkList space, int S, ElemType e, Status(Compare)(ElemType, ElemType));

/*
 *  ���ظ���ֵ��ǰ�� 
 */ 
Status PriorElem(SLinkList space, int S, ElemType cur_e, ElemType *pre_e);

/*
 *  ���ظ���ֵ�ĺ�� 
 */
Status NextElem(SLinkList space, int S, ElemType cur_e, ElemType *next_e);


/*
 *  ��iλ�ò���e 
 */ 
Status ListInsert(SLinkList space, int S, int i, ElemType e);

/*
 *  ��iλ��ɾ��Ԫ�� 
 */
Status ListDelete(SLinkList space, int S, int i, ElemType *e);

/*
 *  ������ӡ��̬�����е�Ԫ�� 
 */ 
void ListTraverse(SLinkList space, int S, void (Visit)(ElemType));

/*
 *  �ȽϺ��� 
 */ 
Status Compare(ElemType, ElemType);

/*
 *  ��ӡ����Ԫ�ص�ֵ 
 */ 
void Visit(ElemType);

/*
 *  ��ͼ�λ���ʽ�����ǰ�ṹ�������ڲ�����ʹ�� 
 */
void PrintGraph(SLinkList space, int S);


#endif
