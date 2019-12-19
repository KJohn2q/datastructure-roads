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
 *  初始化 
 */
Status InitStack(LinkStack *S);

/*
 *  销毁 
 */ 
Status DestroyStack(LinkStack *S);

/*
 *  置空 
 */
Status ClearStack(LinkStack *S);

/*
 *  判空 
 */
Status StackEmpty(LinkStack S);

/*  
 *  栈的长度 
 */ 
int StackLength(LinkStack S);

/*
 *  插入元素 
 */
Status Push(LinkStack *S, SElemType e);

/*
 *  取栈顶元素 
 */
Status GetTop(LinkStack S, SElemType *e);


/*
 *  弹出栈顶元素 
 */
Status Pop(LinkStack *S, SElemType *e);

/*
 *  栈的遍历 
 */
Status StackTraverse(LinkStack S, void Visit(SElemType)); 

/*
 *  输出元素 
 */ 
void Visit(SElemType data);


#endif
