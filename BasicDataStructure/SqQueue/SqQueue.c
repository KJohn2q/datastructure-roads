#include "SqQueue.h"

/*
 * 初始化顺序队列 
 */
Status InitQueue(SqQueue *Q)
{
	if (Q == NULL) {
		return ERROR;
	}
	
	Q->base = (QElemType *) malloc(sizeof(QElemType)*QUEUE_INIT_SIZE);
	
	if (Q->base == NULL) {
		exit(OVERFLOW);
	}
	
	Q->front = Q->rear = 0;
	
	Q->listsize = QUEUE_INIT_SIZE;
	
	return OK;
}

/*
 * 销毁 
 */ 
Status DestroyQueue(SqQueue *Q)
{
	if (Q == NULL) {
		return ERROR;
	}
	
	free(Q->base);
	
	Q->listsize = 0;
	Q->front = Q->rear = 0;
	
	return OK;
}

/*
 * 清空队列 
 */
Status ClearQueue(SqQueue *Q)
{
	if (Q == NULL || Q->base == NULL) {
		return ERROR;
	}
	
	Q->front = Q->rear = 0;
	
	return OK;
}

/*
 *  判空 
 */
Status QueueEmpty(SqQueue Q)
{
	return (Q.front == Q.rear) ? TRUE : FALSE;
}

/*
 *  队列长度 
 */
int QueueLength(SqQueue Q)
{
	if (Q.base == NULL) {
		return ERROR;
	} 
	
	return Q.rear - Q.front;
}

/*
 *  队头元素 
 */
Status GetHead(SqQueue Q, QElemType *e)
{
	if (Q.base == NULL || Q.front == Q.rear) {
		return ERROR;
	}	
	
	*e = *(Q.base + Q.front);
	
	return OK;
} 

/*
 *  插入新的队尾元素 
 */
Status EnQueue(SqQueue *Q, QElemType e)
{
	if (Q == NULL || Q->base == NULL) {
		return ERROR;
	}
	
	if ((Q->rear - Q->front) >= Q->listsize) {
		Q->base = (QElemType *) realloc(Q->base, sizeof(QElemType)*(Q->listsize + INCREMENTSIZE));
		
		if (Q->base == NULL) {
			exit(OVERFLOW);
		}
		
	}
	
	*(Q->base + Q->rear) = e;
	++Q->rear;
	
	Q->listsize += INCREMENTSIZE;
	
	return OK;
}

/*
 *  删除队头元素 
 */
Status DeQueue(SqQueue *Q, QElemType *e)
{
	if (Q == NULL || Q->base == NULL) {
		return ERROR;
	}
	
	if (Q->rear == Q->front) {
		return ERROR;
	}
	
	*e = *(Q->base + Q->front);
	
	Q->front++;
	
	return OK;
}

/*
 *  元素遍历 
 */
Status QueueTraverse(SqQueue Q, void (Visit)(QElemType))
{
	int p;
	
	if (Q.base == NULL || Q.front == Q.rear) {
		return ERROR;
	}
	
	p = Q.front;
	
	printf("队列遍历\n");
	
	while (p < Q.rear) {
		Visit(Q.base[p]);
		p++;
	}
	
	return OK;
}

/*
 *  输出元素 
 */
void Visit(QElemType data)
{
	printf("%d ", data);
}
