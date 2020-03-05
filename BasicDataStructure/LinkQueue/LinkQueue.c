#include "LinkQueue.h" 

/*
 *  初始化链队列 
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
 *  销毁 
 */
Status DestroyQueue(LinkQueue *Q)
{	
	QueuePtr p,q;
	
	if (Q == NULL || Q->front == NULL) {
		return ERROR;
	}
	
	p = Q->front;
	
	while (p != NULL) {
		q = p;
		p = p->next;
		free(q);
	}
	
	Q->front = Q->rear = NULL;
	
	return OK;
}

/*
 *  清空 
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
 *  判空 
 */ 
Status QueueEmpty(LinkQueue Q)
{
	return (Q.rear == Q.front) ? TRUE : FALSE;
}

/*
 *  队列长度 
 */ 
int QueueLength(LinkQueue Q)
{
	QueuePtr p;
	int i = 0;
	
	if (Q.front == NULL || Q.front == Q.rear) {
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
 *  头部 
 */ 
Status GetHead(LinkQueue Q, QElemType *e)
{
	if (Q.front == NULL || Q.front == NULL || Q.front == Q.rear) {
		return ERROR;
	}
	
	*e = Q.front->next->data;
	
	return OK;
}

/*
 *  队尾插入元素 
 */ 
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr node;
	
	if (Q == NULL || Q->front == NULL) {
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
 * 删除队头元素 
 */ 
Status DeQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p;
	
	if (Q == NULL || Q->front == NULL || Q->front == Q->rear) {
		return ERROR;
	}
	
	p = Q->front->next;
	Q->front->next = p->next;
	*e = p->data;
	free(p);
		
	return OK; 
}

/*
 *  遍历队列 
 */ 
Status QueueTraverse(LinkQueue Q, void (Visit)(ElemType))
{
	QueuePtr p;
	
	if (Q.front == NULL || Q.front == NULL || Q.front == Q.rear) {
		return ERROR;
	}
	
	p = Q.front->next;
	
	printf("=====链队列遍历======\n"); 
	
	while (p != NULL) {
		Visit(p->data);
		p = p->next;
	}
	
	return OK;
}

/*
 *  打印元素 
 */ 
void Visit(ElemType data)
{
	printf("%d ", data);
}

