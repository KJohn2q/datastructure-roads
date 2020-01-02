#include "LinkStack.h" 

/*
 *  ��ʼ�� 
 */
Status InitStack(LinkStack *S)
{
	if (S == NULL) {
		return ERROR;
	}
	
	S->top = NULL;
	S->count = 0;
	
	return OK;
}

/*
 *  ���� 
 */ 
Status DestroyStack(LinkStack *S)
{
	LinkTop p;
	
	if (S == NULL) {
		return ERROR;
	}
	
	p = S->top;
	
	while (p != NULL) {
		S->top = p->next;
		free(p);
		--S->count;
		p = S->top;
	}
	
	return OK;	
}

/*
 *  �ÿ� 
 */
Status ClearStack(LinkStack *S)
{
	if (S == NULL) {
		return ERROR;
	}
	
	S->top = NULL;
	S->count = 0;
	return OK;
}

/*
 *  �п� 
 */
Status StackEmpty(LinkStack S)
{
	return (S.top == NULL) ? TRUE : FALSE;
}

/*  
 *  ջ�ĳ��� 
 */ 
int StackLength(LinkStack S)
{
	return S.count;
}

/*
 *  ����Ԫ�� 
 */
Status Push(LinkStack *S, SElemType e)
{
	LinkTop node;
	
	if (S == NULL) {
		return ERROR;
	}
	
	node = (LinkTop) malloc(sizeof(StackNode));
	
	if (node == NULL) {
		exit(OVERFLOW);
	} 
	
	node->data = e;
	node->next = S->top;
	S->top = node;
	++S->count;
	return OK;
}

/*
 *  ȡջ��Ԫ�� 
 */
Status GetTop(LinkStack S, SElemType *e)
{
	if (S.top == NULL) {
		return ERROR;
	}
	
	*e = S.top->data;
	
	return OK;
}


/*
 *  ����ջ��Ԫ�� 
 */
Status Pop(LinkStack *S, SElemType *e)
{
	LinkTop p;
	
	if (S == NULL || S->top == NULL) {
		return ERROR;
	}
	
	p = S->top;
	
	*e = p->data;
	S->top = p->next;
	free(p);
	--S->count;
	
	return OK;
}

/*
 *  ջ�ı��� 
 */
Status StackTraverse(LinkStack S, void Visit(SElemType))
{
	LinkTop p;
	
	if (S.top == NULL) {
		return ERROR;
	}
	
	p = S.top;
	
	printf("=====����Ԫ��======\n"); 
	
	while (p != NULL) {
		Visit(p->data);
		p = p->next;
	}
	
	return OK;
}

/*
 *  ���Ԫ�� 
 */ 
void Visit(SElemType data)
{
	printf("%d ", data);
}
