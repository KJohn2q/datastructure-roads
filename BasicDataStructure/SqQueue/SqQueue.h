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
	int front;  // 头指针，若队列不为空，指向队列头元素 
	int rear;  // 尾指针，若队列不为空，指向队列尾元素的下一个位置
	int listsize;
} SqQueue;

/*
 * 初始化顺序队列 
 */
Status InitQueue(SqQueue *Q);

/*
 * 销毁 
 */ 
Status DestroyQueue(SqQueue *Q);

/*
 * 清空队列 
 */
Status ClearQueue(SqQueue *Q);

/*
 *  判空 
 */
Status QueueEmpty(SqQueue Q);

/*
 *  队列长度 
 */
int QueueLength(SqQueue Q); 

/*
 *  对头元素 
 */
Status GetHead(SqQueue Q, QElemType *e); 

/*
 *  插入新的队尾元素 
 */
Status EnQueue(SqQueue *Q, QElemType e);

/*
 *  删除队头元素 
 */
Status DeQueue(SqQueue *Q, QElemType *e);

/*
 *  元素遍历 
 */
Status QueueTraverse(SqQueue Q, void (Visit)(QElemType)); 

/*
 *  输出元素 
 */
void Visit(QElemType data);

#endif
