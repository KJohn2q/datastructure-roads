#include <stdio.h>
#include "SqList.h"

Status InitList(SqList *L) 
{
	(*L).elem = malloc(LIST_INIT_SIZE * sizeof((SqList)(*L)));
	if ((*L).elem == NULL) {
		exit(OVERFLOW);
	}
	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
	return OK;
}

Status CreateList(SqList *L, int n)
{	
	int i = 0;
	Status s = 1;
	ElemType data;
	if (L == NULL || (*L).elem == NULL) {
		return ERROR;
	}	
	for (i = 0; i < n; i++) {
		scanf("%d", &data);
		s = ListInsert(L, (*L).length + 1, data);
		if (!s) {
			return ERROR;
		}
	}
	return OK;
}

Status DestroyList(SqList *L)
{
	if (L == NULL || (*L).elem == NULL) {
		return ERROR;
	}
	free((*L).elem);
	(*L).elem = NULL;
	
	(*L).length = 0;
	(*L).listsize = 0;
	
	return OK;
}

Status ClearList(SqList *L)
{
	if (L == NULL || (*L).elem == NULL) {
		return ERROR;
	}
	(*L).length = 0;	
	
	return OK;
}

Status ListEmpty(SqList L)
{
	return (L.length == 0) ? OK : ERROR; 
}

int ListLength(SqList L)
{
	return L.length;
}

Status GetElem(SqList L, int i, ElemType *e)
{
	if (L.elem == NULL) {
		return ERROR;
	}
	if (i < 1 || i > (L.length + 1)) {
		return OVERFLOW;
	}
	*e = L.elem[i - 1];
	return OK;
}

int LocateElem(SqList L, ElemType e, Status (Compare)(ElemType, ElemType))
{
	ElemType *p = NULL;
	int i = 0;
	if (L.elem == NULL) {
		return ERROR;
	}
	
	p = L.elem;
	
	while (i < L.length && !Compare(*p++, e)) {
		i++;
	}
	
	if (i <= L.length) {
		return i + 1;
	}
	else {
		return 0;
	}
}

Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e)
{
	int i = 0;
	ElemType *p = NULL;
	
	p = L.elem;
	while (i < L.length && *p++ != cur_e) {
		i++;
	} 
	
	if (i < L.length) {
		*pre_e = L.elem[i - 1];
		return OK;
	} else {
		return OVERFLOW;
	}
}

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e)
{
	int i = 0;
	ElemType *p = NULL;
	
	p = L.elem;
	while (i < L.length && *p++ != cur_e) {
		i++;
	} 
	printf("%d\n", L.length);
	if (i < L.length && i != (L.length - 1)) {
		*next_e = L.elem[i+1];
		return OK;
	} else {
		return OVERFLOW;
	}
}

Status ListInsert(SqList *L, int i, ElemType e)
{
	ElemType *newbase = NULL;
	ElemType *p = NULL;
	ElemType *q = NULL;
	if (L == NULL || (*L).elem == NULL) {
		return ERROR;
	}
	if (i < 1 || i > ((*L).length + 1)) {
		return ERROR;
	}
	
	if ((*L).length >= (*L).listsize) {
		newbase = (ElemType *) realloc((*L).elem, (*L).listsize + LISTINCREMENT);
		if (newbase == NULL) {
			exit(OVERFLOW);
		}
	
		(*L).elem = newbase;
		
		(*L).listsize += LISTINCREMENT; 
	}
	
	// 将i处位置的地址赋值给q 
	q = (*L).elem + (i - 1);
	
	for (p = q; p < ((*L).elem + (*L).length - 1); p++) {
		*(p+1) = *p;
	}
	
	// 将i处位置的值设为给定的e 
	*q = e;
	(*L).length++;
	return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e)
{
	ElemType *p = NULL;
	if (L == NULL || (*L).elem == NULL) {
		return ERROR;
	}
	if ((i < 1) || (i > (*L).length)) {
		return OVERFLOW;
	}
	
	*e = *((*L).elem + i - 1);
	
	for (p = (*L).elem + i - 1; p <= ((*L).elem + (*L).length - 1); p++) {
		*p = *(p+1);
	}
	(*L).length--;
	return OK;
}

void ListTraverse(SqList L, void (Visit)(ElemType))
{
	ElemType *p = NULL;
	int i = 0;
	p = L.elem;
	
	for (; i < L.length; i++) {
		Visit(*p++);
	} 
}

/*
 *  比较函数 
 */ 
Status Compare(ElemType data, ElemType e)
{
	return (data == e) ? OK : ERROR; 
} 

/*
 *  打印给定元素的值 
 */ 
void Visit(ElemType data)
{
	printf("%d ", data);		
}

