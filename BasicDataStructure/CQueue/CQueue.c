#include "CQueue.h"

Status InitQueue(CQueue *Q)
{
	if (Q == NULL) {
		return ERROR;
	}
	
	Q->base = (QElemType *) malloc(sizeof(QElemType) * MAXQUEUESIZE);
	
	if (!Q->base) {
		exit(OVERFLOW);
	}
	
	Q->front = Q->rear = 0;
	
	return OK;
}

Status DestroyQueue(CQueue *Q)
{
	if (Q == NULL) {
		return ERROR;
	}
	
	Q->front = Q->rear = 0;
	
	free(Q->base);
	
	return OK;
}

Status ClearQueue(CQueue *Q)
{
	// 循环队列为空地址或者循环队列为空 
	if (Q == NULL || Q->front == Q->rear) {
		return ERROR;
	}
	
	Q->front = Q->rear = 0;
	
	return OK;
}

Status QueueEmpty(CQueue Q)
{
	return (Q.front == Q.rear) ? TRUE : FALSE;
}

int QueueLength(CQueue Q)
{
	if (Q.front == Q.rear) {
		return ERROR;
	}
	
	return (Q.rear - Q.front + MAXQUEUESIZE) % MAXQUEUESIZE;
}

Status GetHead(CQueue Q, QElemType *e)
{
	if (Q.front == Q.rear) {
		return ERROR;
	}
	
	*e = Q.base[Q.front];
	
	return OK;
}

Status EnQueue(CQueue *Q, QElemType e)
{
	// 循环队列为空地址或者循环队列已满 
	if (Q == NULL || (Q->rear + 1) % MAXQUEUESIZE == Q->front) {
		return ERROR;
	}
	
	Q->base[Q->rear++] = e;
	
	return OK;
}

Status DeQueue(CQueue *Q, QElemType *e)
{
	if (Q == NULL || Q->front == Q->rear) {
		return ERROR;
	}
	
	*e = Q->base[Q->front++];
	
	return OK; 
}

Status QueueTraverse(CQueue Q, void (Visit)(ElemType))
{
	int p;
	
	if (Q.front == Q.rear) {
		return ERROR;
	}
	
	p = Q.front;
	
	printf("=====循环队列遍历开始=====\n"); 
	
	while (p != Q.rear) {
		Visit(Q.base[p]);
		p++;
	}
	
	return OK;
}

void Visit(QElemType data)
{
	printf("%d ", data);
}
