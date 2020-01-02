#include "SqStack.h"

/*
 *  初始化栈 
 */
Status InitStack(SqStack *S)
{
	if (S == NULL) {
		return ERROR;
	}
	
	S->base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (S->base == NULL) {
		exit(OVERFLOW);
	}
	
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	
	return OK;
}

/*
 * 销毁 
 */
Status DestroyStack(SqStack *S)
{
	if (S == NULL) {
		return ERROR;
	}
	
	free(S->base);
	
	S->base = NULL;
	S->top = NULL;
	S->stacksize = 0;
	
	return OK;
}

/*
 * 置空栈 
 */
Status ClearStack(SqStack* S)
{
	if (S == NULL || S->base == NULL) {
		return ERROR;
	}
	S->top = S->base;
	
	return OK;
} 


/*
 * 判断是否为空 
 */
Status StackEmpty(SqStack S)
{
	return S.top == S.base ? TRUE : FALSE;
}

/*
 * 栈的长度 
 */ 
int StackLength(SqStack S)
{
	if (S.base == NULL) {
		return 0;
	}
	
	return (int) (S.top - S.base);
}

/*
 * 获取栈顶元素 
 */
Status GetTop(SqStack S, SElemType *e)
{
	if (S.base == NULL || S.base == S.top) {
		return ERROR;
	}
	
	*e = *(S.top - 1);
	
	return OK;
}

/*
 *  弹出栈顶元素 
 */ 
Status Pop(SqStack* S, SElemType *e)
{
	if (S == NULL || S->base == NULL || S->base == S->top) {
		return ERROR;
	}
	
	*e = *--S->top;
	return OK;
}

/*
 *  在栈顶插入元素 
 */
Status Push(SqStack* S, SElemType e)
{
	if (S == NULL || S->base == NULL) {
		return ERROR;
	}
	
	if (S->top - S->base >= S->stacksize) {
		S->base = (SElemType *) realloc(S->base, (S->stacksize + STACKINCREAMENT) * sizeof(SElemType));
		
		if (S->base == NULL) {
			exit(OVERFLOW);
		}
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREAMENT;
	} 
	
	*(S->top++) = e;
	return OK;
}

/*
 *  栈的遍历 
 */ 
Status StackTraverse(SqStack S, void Visit(SElemType))
{
	SElemType *p;
	p = S.base;
	
	while (p < S.top) {
		Visit(*p);
		p++;
	}
	
	printf("\n");
	
	return OK;
}

/*
 * 遍历函数 
 */
void Visit(SElemType data)
{
	printf("%d ", data);
}
