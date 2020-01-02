#ifndef DULINKLIST_H
#define DULINKLIST_H 

#include "../common.h"

typedef struct DuLNode {
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
} DuLNode, * DuLinkList;

Status InitList(DuLinkList *D);

Status DestroyList(DuLinkList *D);

Status ClearList(DuLinkList D);

int ListLength(DuLinkList D);

Status GetElem(DuLinkList D, int i, ElemType *e);

int LocateElem(DuLinkList D, ElemType e, Status (Compare)(ElemType, ElemType));

Status PriorElem(DuLinkList D, ElemType cur_e, ElemType *e);

Status NextElem(DuLinkList D, ElemType cur_e, ElemType *e);

Status ListInsert(DuLinkList D, int i, ElemType e);

Status ListDelete(DuLinkList D, int i, ElemType *e);

Status ListTraverse(DuLinkList D, void (Visit)(ElemType));

/*
 *  ��ȡѭ�������е�i��Ԫ�ص�����
 *  
 *  ע��
 *  1. ��static�ĺ����ǵ�ǰ����ֻ��DuLinkList��ʹ�ã����ᱻ����ļ�����
 *  2. ����������Ϊlen,����Ҫ��ȡ��len+1��Ԫ�ص�����ʱ������������ѭ���������Է��ص���ͷ��� 
 */
static DuLinkList GetElemP(DuLinkList D, int i);

Status Compare(ElemType, ElemType);

void Visit(ElemType);

#endif
