#ifndef CQUEUE_H
#define CQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

#define MAXQUEUESIZE 10

typedef int QElemType;

typedef struct {
	QElemType *base;
	int front;
	int rear;
} CQueue;

/*
 *  ≥ı ºªØ 
 */
Status InitQueue(CQueue *Q);

Status DestroyQueue(CQueue *Q);

Status ClearQueue(CQueue *Q);

Status QueueEmpty(CQueue Q);

int QueueLength(CQueue Q);

Status GetHead(CQueue Q, QElemType *e);

Status EnQueue(CQueue *Q, QElemType e);

Status DeQueue(CQueue *Q, QElemType *e);

Status QueueTraverse(CQueue Q, void (Visit)(ElemType));

void Visit(QElemType);


#endif
