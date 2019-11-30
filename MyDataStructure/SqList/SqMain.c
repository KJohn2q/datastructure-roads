#include "SqList.c"

int main()
{
	SqList L;
	Status s = 0;
	ElemType e;
	
    InitList(&L);
	s = CreateList(&L, 3);
	ListTraverse(L, Visit);
	printf("\n");
	GetElem(L, 2, &e);
	printf("%d\n", e);
	PriorElem(L, 3, &e);
	printf("3的前驱为%d\n", e);
	NextElem(L, 3, &e);
	printf("3的后缀为%d\n", e);
//	s = ListDelete(&L, 2, &e); 
//	ListTraverse(L, Visit);
	return 0;
}
