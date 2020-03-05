#include "LinkStack.h" 

/*
 *  初始化 
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
 *  销毁 
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
 *  置空 
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
 *  判空 
 */
Status StackEmpty(LinkStack S)
{
	return (S.top == NULL) ? TRUE : FALSE;
}

/*  
 *  栈的长度 
 */ 
int StackLength(LinkStack S)
{
	return S.count;
}

/*
 *  插入元素 
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
 *  取栈顶元素 
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
 *  弹出栈顶元素 
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
 *  栈的遍历 
 */
Status StackTraverse(LinkStack S, void Visit(SElemType))
{
	LinkTop p;
	
	if (S.top == NULL) {
		return ERROR;
	}
	
	p = S.top;
	
	printf("=====遍历元素======\n"); 
	
	while (p != NULL) {
		Visit(p->data);
		p = p->next;
	}
	
	return OK;
}

/*
 *  输出元素 
 */ 
void Visit(SElemType data)
{
	printf("%d ", data);
}
