#ifndef LINKSTACK_H
#define LINKSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

typedef int SElemType;

typedef struct StackNode {
	SElemType data;
	struct StackNode *next;
}StackNode,* LinkTop;

typedef struct LinkStack {
	LinkTop top;
	int count;
}LinkStack;

/*
 *  ��ʼ�� 
 */
Status InitStack(LinkStack *S);

/*
 *  ���� 
 */ 
Status DestroyStack(LinkStack *S);

/*
 *  �ÿ� 
 */
Status ClearStack(LinkStack *S);

/*
 *  �п� 
 */
Status StackEmpty(LinkStack S);

/*  
 *  ջ�ĳ��� 
 */ 
int StackLength(LinkStack S);

/*
 *  ����Ԫ�� 
 */
Status Push(LinkStack *S, SElemType e);

/*
 *  ȡջ��Ԫ�� 
 */
Status GetTop(LinkStack S, SElemType *e);


/*
 *  ����ջ��Ԫ�� 
 */
Status Pop(LinkStack *S, SElemType *e);

/*
 *  ջ�ı��� 
 */
Status StackTraverse(LinkStack S, void Visit(SElemType)); 

/*
 *  ���Ԫ�� 
 */ 
void Visit(SElemType data);


#endif
