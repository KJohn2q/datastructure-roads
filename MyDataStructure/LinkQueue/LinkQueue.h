#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

typedef int QElemType;

typedef struct QNode {
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

/*
 *  ��ʼ�������� 
 */
Status InitQueue(LinkQueue *Q);

/*
 *  ���� 
 */
Status DestroyQueue(LinkQueue *Q);

/*
 *  ��� 
 */ 
Status ClearQueue(LinkQueue *Q);

/*
 *  �п� 
 */ 
Status QueueEmpty(LinkQueue Q);

/*
 *  ���г��� 
 */ 
int QueueLength(LinkQueue Q);

/*
 *  ͷ�� 
 */ 
Status GetHead(LinkQueue Q, QElemType *e);

/*
 *  ��β����Ԫ�� 
 */ 
Status EnQueue(LinkQueue *Q, QElemType e);

/*
 * ɾ����ͷԪ�� 
 */ 
Status DeQueue(LinkQueue *Q, QElemType *e);

/*
 *  �������� 
 */ 
Status QueueTraverse(LinkQueue Q, void (Visit)(ElemType));

/*
 *  ��ӡԪ�� 
 */ 
void Visit(ElemType);



#endif
