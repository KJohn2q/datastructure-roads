#include "../common.h"

typedef struct DuLNode {
	ElemType data;
	struct DuLNode *prior;
	struct DuLNode *next;
} DuLNode, * DuLinkList;

Status InitList(DuLinkList *D);

Status DestroyList(DuLinkList *D);

Status ClearList(DuLinkList D);

int ListLength(DuLinkList D);

Status GetElem(DuLinkList D, int i, ElemType *e);

int LocateElem(DuLinkList D, ElemType e, Status (Compare)(ElemType, ElemType));

Status PriorElem(DuLinkList D, ElemType cur_e, ElemType *e);

Status NextElem(DuLinkList D, ElemType cur_e, ElemType *e);

Status ListInsert(DuLinkList D, int i, ElemType e);

Status ListDelete(DuLinkList D, int i, ElemType *e);

Status ListTraverse(DuLinkList D, void (Visit)(ElemType));

Status Compare(ElemType, ElemType);

void Visit(ElemType);

