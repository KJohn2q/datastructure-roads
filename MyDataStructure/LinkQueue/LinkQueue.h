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
 *  初始化链队列 
 */
Status InitQueue(LinkQueue *Q);

/*
 *  销毁 
 */
Status DestroyQueue(LinkQueue *Q);

/*
 *  清空 
 */ 
Status ClearQueue(LinkQueue *Q);

/*
 *  判空 
 */ 
Status QueueEmpty(LinkQueue Q);

/*
 *  队列长度 
 */ 
int QueueLength(LinkQueue Q);

/*
 *  头部 
 */ 
Status GetHead(LinkQueue Q, QElemType *e);

/*
 *  队尾插入元素 
 */ 
Status EnQueue(LinkQueue *Q, QElemType e);

/*
 * 删除队头元素 
 */ 
Status DeQueue(LinkQueue *Q, QElemType *e);

/*
 *  遍历队列 
 */ 
Status QueueTraverse(LinkQueue Q, void (Visit)(ElemType));

/*
 *  打印元素 
 */ 
void Visit(ElemType);



#endif
