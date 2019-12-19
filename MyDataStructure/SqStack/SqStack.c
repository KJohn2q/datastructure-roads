#include "SqStack.h"

/*
 *  ��ʼ��ջ 
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
 * ���� 
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
 * �ÿ�ջ 
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
 * �ж��Ƿ�Ϊ�� 
 */
Status StackEmpty(SqStack S)
{
	return S.top == S.base ? TRUE : FALSE;
}

/*
 * ջ�ĳ��� 
 */ 
int StackLength(SqStack S)
{
	if (S.base == NULL) {
		return 0;
	}
	
	return (int) (S.top - S.base);
}

/*
 * ��ȡջ��Ԫ�� 
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
 *  ����ջ��Ԫ�� 
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
 *  ��ջ������Ԫ�� 
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
 *  ջ�ı��� 
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
 * �������� 
 */
void Visit(SElemType data)
{
	printf("%d ", data);
}
