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
	// ѭ������Ϊ�յ�ַ����ѭ������Ϊ�� 
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
	// ѭ������Ϊ�յ�ַ����ѭ���������� 
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
	
	printf("=====ѭ�����б�����ʼ=====\n"); 
	
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
