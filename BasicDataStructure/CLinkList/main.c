#include <stdio.h>
#include <stdlib.h>
#include "CLinkList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	CLinkList C = NULL;
	Status s = 0;
	ElemType e = 0;
	int len = 0;  // 链表的长度 
	
	InitList(&C);
	
	CreateList(C, 10);
//	s = DestroyList(&C);
//	ClearList(C);
//	s = ListEmpty(C);
//	len = ListLength(C); 
//	GetElem(C, 25, &e);
//	s = LocateElem(C, 10, Compare);
//	PriorElem(C, 22, &e);
//	NextElem(C, 1, &e);
//	ListDelete(C, 1, &e);
//	printf("%d\n", e);
	
	ListTraverse(C, Visit);
	
	return 0;
}
