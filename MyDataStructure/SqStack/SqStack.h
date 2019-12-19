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
 *  初始化栈 
 */
Status InitStack(SqStack *S);

/*
 * 销毁 
 */
Status DestroyStack(SqStack *S);

/*
 * 置空栈 
 */
Status ClearStack(SqStack *S);

/*
 * 判断是否为空 
 */
Status StackEmpty(SqStack S);

/*
 * 栈的长度 
 */ 
int StackLength(SqStack S);

/*
 * 获取栈顶元素 
 */
Status GetTop(SqStack S, SElemType *e);

/*
 *  弹出栈顶元素 
 */ 
Status Pop(SqStack* S, SElemType *e);

/*
 *  在栈顶插入元素 
 */
Status Push(SqStack* S, SElemType e);

/*
 *  栈的遍历 
 */ 
Status StackTraverse(SqStack S, void Visit(SElemType));

/*
 * 遍历函数 
 */
void Visit(SElemType); 

#endif
