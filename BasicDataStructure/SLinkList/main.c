#include "SLinkList.h"

int main(int argc, char** argv) {
	SLinkList space;  // 备用空间 
	int S;  // 静态链表头结点索引 
	
	int i;
	ElemType e;
	
	Status s;
	
	s = InitList(space, &S);
	s = ListEmpty(space, S);
	
	for (i = 1; i <= 8; i++) {
		ListInsert(space, S, i, 2*i);
	}
	
//	GetElem(space, S, 2, &e);
//	printf("%d\n", e);
//	printf("%d\n", LocateElem(space, S, 8, Compare));
	NextElem(space, S, 8, &e);
	printf("%d\n", e);
	
	ListDelete(space, S, 3, &e);
	ListTraverse(space, S, Visit);
	
//	printf("%d", s);
	
	return 0;
}
