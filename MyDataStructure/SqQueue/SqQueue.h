#ifndef SQQUEUE_H
#define SQQUEUE_H

#define QUEUE_INIT_SIZE 100
#define INCREMENTSIZE 10

#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

typedef int QElemType;

typedef struct {
	QElemType *base;
	int front;  // ͷָ�룬�����в�Ϊ�գ�ָ�����ͷԪ�� 
	int rear;  // βָ�룬�����в�Ϊ�գ�ָ�����βԪ�ص���һ��λ��
	int listsize;
} SqQueue;

/*
 * ��ʼ��˳����� 
 */
Status InitQueue(SqQueue *Q);

/*
 * ���� 
 */ 
Status DestroyQueue(SqQueue *Q);

/*
 * ��ն��� 
 */
Status ClearQueue(SqQueue *Q);

/*
 *  �п� 
 */
Status QueueEmpty(SqQueue Q);

/*
 *  ���г��� 
 */
int QueueLength(SqQueue Q); 

/*
 *  ��ͷԪ�� 
 */
Status GetHead(SqQueue Q, QElemType *e); 

/*
 *  �����µĶ�βԪ�� 
 */
Status EnQueue(SqQueue *Q, QElemType e);

/*
 *  ɾ����ͷԪ�� 
 */
Status DeQueue(SqQueue *Q, QElemType *e);

/*
 *  Ԫ�ر��� 
 */
Status QueueTraverse(SqQueue Q, void (Visit)(QElemType)); 

/*
 *  ���Ԫ�� 
 */
void Visit(QElemType data);

#endif
