#include "SqList.h"

Status InitList(SqList *L) 
{
	*L.elem = malloc(LIST_INIT_SIZE * sizeof((ElemType)SqList));
	if (!*L.elem == NULL) {
		exit(OVERFLOW);
	}
	*L.length = 0;
	*L.listsize = LIST_INIT_SIZE;
	return OK;
}

Status DestroyList(SqList *L)
{
	if (L == NULL || (*L).elem == NULL) {
		return ERROR;
	}
	free(*L.elem);
	(*L).elem = NULL;
	
	(*L).length = 0;
	(*L).listsize = 0;
	
	return OK;
}

Status ClearList(SqList *L)
{
	
}

Status ListEmpty(SqList L)
{
	
}

int ListLength(SqList L)
{
	
}

Status GetElem(SqList L, int i, ElemType *e)
{
	
}

int LocateElem(SqList L, ElemType e, Status(Compare)(ElemType, ElemType))
{
	
}

Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e)
{
	
}

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e)
{
	
}

Status ListInsert(SqList *L, int i, ElemType e)
{
	
}

Status ListDelete(SqList *L, int i, ElemType *e)
{
	
}

void ListTraverse(SqList L, void (Visit)(ElemType))
{
	
}

