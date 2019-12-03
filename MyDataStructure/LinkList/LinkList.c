#include "LinkList.h"

/*
 *  初始化链表 
 */ 
Status InitList(LinkList L) 
{
	L = (LinkList) malloc(sizeof(LNode));
	if (L == NULL) {
		exit(OVERFLOW);
	}
	L->next = NULL;

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
		node->next = NULL;
		p->next = node;
		p = p->next;
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
    
    if (i < 2 || i > ListLength(L) + 1 ) {
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
} 

/*
 *  打印元素的值 
 */
void Visit(ElemType data)
{
	printf("%d ", data);
}




