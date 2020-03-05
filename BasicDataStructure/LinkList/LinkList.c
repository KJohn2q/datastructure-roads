#include "LinkList.h"

/*
 *  初始化链表 
 */ 
Status InitList(LinkList *L) 
{
	*L = (LinkList) malloc(sizeof(LNode));
	if (L == NULL) {
		exit(OVERFLOW);
	}
	(*L)->next = NULL;

	return OK;
} 

/*
 *  输入n个值创建链表 
 */
Status CreateList(LinkList L, int n)
{
	LinkList p,node; 
	int i = 0;
	ElemType data;
	
	p = L;
	
	if (L == NULL) {
		return ERROR; 
	}
	for (; i < n; i++) {
		scanf("%d", &data);
		node = (LinkList) malloc(sizeof(LNode));
		
		if (node == NULL) {
			exit(OVERFLOW);
		}
		
		node->data = data;
		p->next = node;
		p = p->next;
	}
	
	p->next = NULL;
	
	return OK;
} 

/*
 *  销毁链表 
 */ 
Status DestroyList(LinkList *L) 
{
	LinkList p;
	
	while (*L != NULL) {
		p = (*L)->next;
		free(*L);
		(*L) = p;
	}
	
	return OK;
} 

/*
 *  清空链表 
 */ 
Status ClearList(LinkList L) 
{
	LinkList p,q;
	
	p = L->next;
	
	while (p != NULL) {
		q = p->next;
		free(p);
		p = q;
	} 
	
	L->next = NULL; 
	
	return OK;
} 

/*
 *  判断链表是否为空 
 */
Status ListEmpty(LinkList L)
{
	if (L == NULL) {
		return ERROR;
	}
	
	if (L->next != NULL) {
		return FALSE;
	}
	else {
		return TRUE;
	}
}

/*
 *  获得链表中i位置元素的值，赋值给e 
 */ 
Status GetElem(LinkList L, int i, ElemType *e)
{
	LinkList p;
	int j = 0;
	
	if (i < 1 || i > ListLength(L)) {
		return ERROR;
	}
	
	p = L->next;
	j = 1;  
	
	while (p != NULL && j < i) {
		p = p->next;
		j++;
	}
	
	*e = p->data;
	return OK;
} 

/*
 *  获得链表中与给定值相等的元素的位置 
 */ 
int LocateElem(LinkList L, ElemType e, Status (Compare)(ElemType, ElemType))
{
	LinkList p;
	int i = 0;
	
	if (L == NULL || L->next == NULL) {
		return ERROR;
	}
	
	p = L->next;
	i = 1;
	
	while (p != NULL && !Compare(p->data, e)) {
		p = p->next;
		++i;
	}
	
	if (i > ListLength(L)) {
		return -1;
	}
	return i;
}


/*
 *  查看链表中给定元素的前驱 
 */ 
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	LinkList p;
	int i = 1;
	
	p = L->next;
	
	/* 如果是第一个元素，则没有前驱 */
	if (p->data == cur_e) {
		return ERROR;
	}
	
	while (p != NULL && p->next->data != cur_e) {
		p = p->next;
		++i;
	}
	
	*pre_e = p->data;
	
	return OK;
}

/*
 *  查看链表中给定元素的后缀 
 */ 
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e)
{
	LinkList p;
	int i = 1;
	
	p = L->next;
	
	while (p != NULL && p->data != cur_e) {
		p = p->next;
		++i;
	}
	
	/* 最后一个元素没有后缀 */ 
	if (p->next == NULL) {
		return ERROR;
	}
	else {
		*next_e = p->next->data;
	}
	
	return OK;
}

/*
 *  向链表表中插入元素 
 */
Status ListInsert(LinkList L, int i, ElemType e) 
{
	LinkList node,p;
	int j = 0;
	
	// 确保链表存在 
    if (L == NULL) {
        return ERROR;
    }
    
    p = L;
	
	while (p != NULL && j < i - 1) {
		p = p->next;
		++j;
	}
	if (p == NULL || j > i - 1) {
		return ERROR;
	}
	node = (LinkList) malloc(sizeof(LNode));
	if (node == NULL) {
		exit(OVERFLOW);
	}
	
	node->data = e;
	node->next = p->next;
	p->next = node;
	
	return OK;
}
/*
 *  删除链表中指定元素 
 */
Status ListDelete(LinkList L, int  i, ElemType *e)
{
	LinkList p,q;
	int j = 0;
	
	if (L == NULL || L->next == NULL) {
		return ERROR;
	}
	
	p = L;
	j = 0;
	
	while (p->next != NULL && j < i - 1) {
		p = p->next;
		++j;
	}
	
	if (p->next == NULL || j > i - 1) {
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	*e = q->data;
	free(q);
	
	return OK;
} 

/*
 *  获得链表的长度 
 */
int ListLength(LinkList L)
{
	int i = 0;
	LinkList p;
	
	if (L == NULL || L->next == NULL) {
		return 0;
	}
	
	/* p从头结点开始 */
	p = L->next;
	
	while (p != NULL) {
		i++;
		p = p->next;
	}
	
	return i;
}

/*
 *  遍历链表 
 */
void ListTraverse(LinkList L, void (Visit)(ElemType)) 
{
	int i = 0;
	LinkList p;
	
	if (L == NULL || L->next == NULL) {
		exit(OVERFLOW);
	}
	
	p = L->next;
	
	while (p != NULL) {
		Visit(p->data);
		p = p->next;	
	}
	
	printf("\n");
} 

/*
 *  比较给定的两个值 是否相等 
 */
Status Compare(ElemType data, ElemType e)
{
	return data == e ? TRUE : FALSE;
}

/*
 *  打印元素的值 
 */
void Visit(ElemType data)
{
	printf("%d ", data);
}

/*
 * 链表翻转递归操作 
 */
LinkList ListReverse(LinkList L)
{
	if (L->next == NULL) {
		return L;
	}
	LinkList newL = ListReverse(L->next);
	
	L->next->next = L;
	L->next = NULL;
	
	return newL;
} 

/*
 * 链表翻转主例程 
 */
void LReverse(LinkList *L) 
{
	LinkList newL;
	
	newL = ListReverse((*L)->next);
	(*L)->next = newL;
}

/*
 * 迭代实现链表翻转 
 */
void IterationInvertList(LinkList *L)
{
	LinkList pre, cur;
	LinkList next;
	
	pre = (*L)->next;
	cur = pre->next;
	
	pre->next = NULL;
	
	while (cur != NULL) {
		next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	
	(*L)->next = pre;
}
 






