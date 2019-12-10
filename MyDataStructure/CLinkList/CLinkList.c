#include <stdio.h>
#include "CLinkList.h" 

/*
 *  初始化 
 */
Status InitList(CLinkList* C)
{
	(*C) = (CLinkList) malloc(sizeof(CLNode));
	
	if ((*C) == NULL) {
		exit(OVERFLOW);
	}
	
	*C->next = NULL;
	
	return OK;
}

/*
 *  销毁 
 */ 
Status DestroyList(CLinkList* C)
{
 	CLinkList p = NULL;
 	
	if ((*C) == NULL) {
		exit(OVERFLOW);
	}
	
	p = *C;
	
	while (p != NULL) {
		p = (*C)->next;
		free(*C);
		*C = p;
	}
	
	*C = NULL;
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
	
	while (p != NULL) {
		pre = p;
		p = p->next;
		free(pre);
	}
	
	C->next = NULL;
	
	return OK;
}

/*
 * 判断是否为空 
 */
Status ListEmpty(CLinkList C)
{
	return (C == NULL && C->next == NULL) ? TRUE : FALSE;
}

/*
 *  计算链表的长度 
 */
int ListLength(CLinkList C) 
{
	CLinkList p = NULL;
	int i = 1;
	
	if (C == NULL || C->next == NULL) {
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
	
	if (C == NULL || C->next == NULL) {
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
	int i = 0;
	if (C == NULL || C->next == NULL) {
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
Status PriorElem(CLinkList C, ElemType cur_e, ElemType* pre_e);

/*
 *  后缀 
 */ 
Status NextElem(CLinkList C, ElemType cur_e, ElemType* next_e);

/*
 *  插入 
 */
Status ListInsert(CLinkList C, int i, ElemType e);

/*
 *  删除 
 */ 
Status ListDelete(CLinkList C, int i, ElemType* e);

/*
 *  遍历 
 */ 
void ListTraverse(CLinkList C, void(Visit)(ElemType)); 

/*
 * 比较函数 
 */ 
Status Compare(ElemType, ElemType);

/*
 * 打印数据 
 */
void Visit(ElemType);
