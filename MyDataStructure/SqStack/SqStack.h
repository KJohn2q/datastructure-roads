#ifndef SQSTACK_H
#define SQSTACK_H

#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

#define STACK_INIT_SIZE 100
#define STACKINCREAMENT 10

typedef int SElemType;

typedef struct {
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack; 

/*
 *  ��ʼ��ջ 
 */
Status InitStack(SqStack *S);

/*
 * ���� 
 */
Status DestroyStack(SqStack *S);

/*
 * �ÿ�ջ 
 */
Status ClearStack(SqStack *S);

/*
 * �ж��Ƿ�Ϊ�� 
 */
Status StackEmpty(SqStack S);

/*
 * ջ�ĳ��� 
 */ 
int StackLength(SqStack S);

/*
 * ��ȡջ��Ԫ�� 
 */
Status GetTop(SqStack S, SElemType *e);

/*
 *  ����ջ��Ԫ�� 
 */ 
Status Pop(SqStack* S, SElemType *e);

/*
 *  ��ջ������Ԫ�� 
 */
Status Push(SqStack* S, SElemType e);

/*
 *  ջ�ı��� 
 */ 
Status StackTraverse(SqStack S, void Visit(SElemType));

/*
 * �������� 
 */
void Visit(SElemType); 

#endif
