#include <stdio.h>
#include "CLinkList.h" 

/*
 *  初始化 
 */
Status InitList(CLinkList *C)
{
	(*C) = (CLinkList) malloc(sizeof(CLNode));
	
	if ((*C) == NULL) {
		exit(OVERFLOW);
	}
	
	(*C)->next = *C;
	
	return OK;
}

/*
 *  销毁 
 */ 
Status DestroyList(CLinkList *C)
{
 	CLinkList p = NULL;
 	
	if ((*C) == NULL) {
		exit(OVERFLOW);
	}
	
	while ((*C) != (*C)) {
		p = *C;
		*C = (*C)->next;
		free(p);		
	}
	
	*C = NULL;
	
	return OK;
}

/*
 *  创建一个有n个值的链表 
 */
Status CreateList(CLinkList C, int n)
{
	CLinkList p = NULL,node = NULL;
	int i = 0;
	
	if (C == NULL) {
		return ERROR;
	}
	
	p = C;
	
	for (i = 1; i <= n; i++) {
		node = (CLinkList) malloc(sizeof(CLNode));
		node->data = 2 * i;
		
		p->next = node;
		p = p->next; 
	}
	
	p->next = C;
	
	return OK;
}

/*
 * 清空 
 */  
Status ClearList(CLinkList C) {
	CLinkList p = NULL,pre = NULL;
	
	if (C == NULL) {
		exit(OVERFLOW);
	}
	
	p = C->next;
	
	while (p != C) {
		pre = p;
		p = p->next;
		free(pre);
	}
	
	C->next = C;
	
	return OK;
}

/*
 * 判断是否为空 
 * 判断条件：头结点为空或者头结点的next域指向自身 
 */
Status ListEmpty(CLinkList C)
{
	return (C == NULL || C->next == C) ? TRUE : FALSE;
}

/*
 *  计算链表的长度 
 */
int ListLength(CLinkList C) 
{
	CLinkList p = NULL;
	int i = 0;
	
	if (C == NULL || C->next == C) {
		return 0;
	}
	
	p = C->next;
	
	while (p != C ) {
		p = p->next;	
		++i;
	}
	
	return i;
}

/*
 *  取值 
 */
Status GetElem(CLinkList C, int i, ElemType* e) 
{
	CLinkList p = NULL;
	int j = 1;
	
	if (C == NULL || C->next == C) {
		return ERROR;
	}	
	
	p = C->next;
	
	while (p != C &&  j < i) {
		p = p->next;
		j++;
	}
	
	if (p == C || j > i) {
		return ERROR;
	}
	
	*e = p->data;
	
	return OK;
}

/*
 *  查找 
 */
int LocateElem(CLinkList C, ElemType e, Status(Compare)(ElemType, ElemType))
{
	CLinkList p = NULL;
	int i = 1;
	if (C == NULL || C->next == C) {
		return ERROR;
	}	
	
	p = C->next;
	
	while (p != C && !Compare(p->data, e) ) {
		p = p->next;
		i++;
	}
	
	if (p == C) {
		return ERROR;
	}
	
	return i;
}

/*
 *  前驱 
 */
Status PriorElem(CLinkList C, ElemType cur_e, ElemType* pre_e)
{
	CLinkList p = NULL;
	
	if (C == NULL || C->next == C) {
		return ERROR;
	}
	
	p = C->next;
	
	while (p != C && p->next->data != cur_e) {
		p = p->next;
	}
	
	// 到头，未找到与cur_e相等的元素 
	if (p == C) {
		return ERROR;
	}
	
	*pre_e = p->data;
	return OK;
}

/*
 *  后缀 
 */ 
Status NextElem(CLinkList C, ElemType cur_e, ElemType* next_e)
{
	CLinkList p = NULL;
	
	if (C == NULL || C->next == C) {
		return ERROR;
	}
	
	p = C->next;
	
	while (p->next != C && p->data != cur_e) {
		p = p->next;
	}
	
	if (p->next == C) {
		return ERROR;
	}
	
	*next_e = p->next->data;
	return OK;
}

/*
 *  插入 
 *  在i位置处插入元素e 
 */
Status ListInsert(CLinkList C, int i, ElemType e)
{
	CLinkList p = NULL,cnode = NULL;
	int j = 0;
	
	if (C == NULL) {
		return ERROR;
	}
	
	p = C;
	
	while (p->next != C && j < i - 1) {
		p = p->next;
		++j;
	}
	
	// 遍历到头了或没有找到第i个元素
	// 考虑只有头结点的情况 
	if (p->next == C || j > i - 1) {
		return ERROR;
	}
	
	cnode = (CLinkList) malloc(sizeof(CLNode));
	
	if (cnode == NULL) {
		exit(OVERFLOW);
	}
	
	cnode->data = e;
	cnode->next = p->next;
	p->next = cnode;
	
	return OK;
}

/*
 *  删除 
 */ 
Status ListDelete(CLinkList C, int i, ElemType* e)
{
	CLinkList p = NULL,q = NULL;
	int j = 0;
	
	if (C == NULL || C->next == C) {
		return ERROR;
	}
	
	p = C;
	
	while (p->next != C && j < i - 1) {
		p = p->next;
		++j;
	}
	
	if (p->next == C || j > i - 1) {
		return ERROR;
	}
	
	q = p->next;
	p->next = q->next;
	*e = q->data;
	q->next = NULL;
	free(q);
	
	return OK;
}

/*
 *  遍历 
 */ 
void ListTraverse(CLinkList C, void(Visit)(ElemType))
{
	CLinkList p = NULL;
	
	p = C->next;
	
	while (p != C) {
		Visit(p->data);
		p = p->next;
	}
} 

/*
 * 比较函数 
 */ 
Status Compare(ElemType data, ElemType e) 
{
	return data == e ? TRUE : FALSE;
}

/*
 * 打印数据 
 */
void Visit(ElemType data)
{
	printf("%d ", data);
}
