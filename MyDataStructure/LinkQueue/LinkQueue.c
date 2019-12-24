#include "LinkQueue.h" 

/*
 *  ��ʼ�������� 
 */
Status InitQueue(LinkQueue *Q)
{
	if (Q == NULL) {
		return ERROR;
	}
	
	Q->front = (QueuePtr) malloc(sizeof(QNode));
	
	
	Q->rear = Q->front;
	
	Q->front->next = NULL;
	
	return OK; 
}

/*
 *  ���� 
 */
Status DestroyQueue(LinkQueue *Q)
{	
	QueuePtr p,q;
	
	if (Q == NULL) {
		return ERROR;
	}
	
	p = Q->front;
	
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	
	return OK;
}

/*
 *  ��� 
 */ 
Status ClearQueue(LinkQueue *Q)
{
	QueuePtr p,q;
	
	if (Q == NULL) {
		return ERROR;
	}
	
	p = Q->front->next;
	
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	
	Q->rear = Q->front;
	
	return OK;
}

/*
 *  �п� 
 */ 
Status QueueEmpty(LinkQueue Q)
{
	return (Q.rear == Q.front) ? TRUE : FALSE;
}

/*
 *  ���г��� 
 */ 
int QueueLength(LinkQueue Q)
{
	QueuePtr p;
	int i = 0;
	
	if (Q.front == Q.rear) {
		return ERROR;
	}
	
	p = Q.front;
	
	while (p != Q.rear) {
		p = p->next;
		++i;
	}
	
	return i;
}

/*
 *  ͷ�� 
 */ 
Status GetHead(LinkQueue Q, QElemType *e)
{
	if (Q.front == Q.rear) {
		return ERROR;
	}
	
	*e = Q.front->data;
	
	return OK;
}

/*
 *  ��β����Ԫ�� 
 */ 
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr node;
	
	if (Q == NULL) {
		return ERROR;
	}
	
	node = (QueuePtr) malloc(sizeof(QNode));
	
	if (node == NULL) {
		exit(OVERFLOW);
	}
	
	node->data = e;
	node->next = NULL;
	Q->rear->next = node;
	Q->rear = node;
	
	return OK;
}

/*
 * ɾ����ͷԪ�� 
 */ 
Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	
	if (Q == NULL || Q->front == Q->rear) {
		return ERROR;
	}
	
	p = Q->front;
	Q->front = Q->front->next;
	free(p);
	*e = p->data;
	
	return OK; 
}

/*
 *  �������� 
 */ 
Status QueueTraverse(LinkQueue Q, void (Visit)(ElemType))
{
	QueuePtr p;
	
	if (Q.front == Q.rear) {
		return ERROR;
	}
	
	p = Q.front;
	
	printf("=====�����б���======"); 
	
	while (p != NULL) {
		Visit(p->data);
		p = p->next;
	}
	
	return OK;
}

/*
 *  ��ӡԪ�� 
 */ 
void Visit(ElemType data)
{
	printf("%d ", data);
}

