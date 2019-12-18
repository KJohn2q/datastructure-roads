#include <stdio.h>
#include <stdlib.h>
#include "DuLinkList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	DuLinkList D;
	Status s;
	int cur;
	ElemType e;
	int i = 0;
	
	s = InitList(&D);
	printf("初始化链表%d\n", s);
	s = ListEmpty(D);
	printf("链表是否为空%d\n", s);
	for (i = 1; i <= 10; i++) {
		ListInsert(D, i, i * 2);
		ListTraverse(D, Visit);
	}	
	/*
	cur = LocateElem(D, 2, Compare);	
	printf("2在链表中的位置%d\n", cur);
	*/
	/*
	s = GetElem(D, 1, &e);
	printf("第二个元素的值%d\n", e);
	printf("取值测试%d\n", s);
	*/
	/*
	s = ListDelete(D, 3, &e);
	printf("链表中删除的值%d\n", e);
	printf("链表元素测试%d\n", s);
	*/
	/* 
	s = PriorElem(D, 2, &e);
	printf("链表中指定元素的前驱为%d\n", e);
	printf("链表前驱测试%d\n", s);
	*/
	/* 
	s = NextElem(D, 10, &e);
	printf("链表中指定元素的后继为%d\n", e);
	printf("链表后继测试%d\n", s);
	*/
	
//	ListTraverse(D, Visit);
	
	return 0;
}
