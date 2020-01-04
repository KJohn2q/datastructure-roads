#include "LinkList.h"

/*
 *  ��ʼ������ 
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
 *  ����n��ֵ�������� 
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
 *  �������� 
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
 *  ������� 
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
 *  �ж������Ƿ�Ϊ�� 
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
 *  ���������iλ��Ԫ�ص�ֵ����ֵ��e 
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
 *  ��������������ֵ��ȵ�Ԫ�ص�λ�� 
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
 *  �鿴�����и���Ԫ�ص�ǰ�� 
 */ 
Status PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	LinkList p;
	int i = 1;
	
	p = L->next;
	
	/* ����ǵ�һ��Ԫ�أ���û��ǰ�� */
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
 *  �鿴�����и���Ԫ�صĺ�׺ 
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
	
	/* ���һ��Ԫ��û�к�׺ */ 
	if (p->next == NULL) {
		return ERROR;
	}
	else {
		*next_e = p->next->data;
	}
	
	return OK;
}

/*
 *  ��������в���Ԫ�� 
 */
Status ListInsert(LinkList L, int i, ElemType e) 
{
	LinkList node,p;
	int j = 0;
	
	// ȷ��������� 
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
 *  ɾ��������ָ��Ԫ�� 
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
 *  �������ĳ��� 
 */
int ListLength(LinkList L)
{
	int i = 0;
	LinkList p;
	
	if (L == NULL || L->next == NULL) {
		return 0;
	}
	
	/* p��ͷ��㿪ʼ */
	p = L->next;
	
	while (p != NULL) {
		i++;
		p = p->next;
	}
	
	return i;
}

/*
 *  �������� 
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
 *  �Ƚϸ���������ֵ �Ƿ���� 
 */
Status Compare(ElemType data, ElemType e)
{
	return data == e ? TRUE : FALSE;
}

/*
 *  ��ӡԪ�ص�ֵ 
 */
void Visit(ElemType data)
{
	printf("%d ", data);
}

/*
 * ����ת�ݹ���� 
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
 * ����ת������ 
 */
void LReverse(LinkList *L) 
{
	LinkList newL;
	
	newL = ListReverse((*L)->next);
	(*L)->next = newL;
}

/*
 * ����ʵ������ת 
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
 






