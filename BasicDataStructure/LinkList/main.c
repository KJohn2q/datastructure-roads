#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	LinkList L;
	Status s;
	int len = 0;
	int pos = 0;
	ElemType e;
	
	
	/* 初始化单链表 */
	s = InitList(&L);
	printf("初始化链表%d\n", s);
	/* 创建链表 */
	s = CreateList(L, 3);
	printf("创建链表%d\n", s);
	/*
	printf("链表翻转前\n");
	ListTraverse(L, Visit);
	*/

	// 链表翻转 
	IterationInvertList(&L); 
	
	printf("链表翻转后\n"); 
	ListTraverse(L, Visit);
	
	/* 链表长度 
	len = ListLength(L);
	printf("链表长度为：%d\n", len);
	*/ 
	/* 遍历链表 
	ListTraverse(L, Visit);
	printf("\n", s);
	*/ 
	/* 清空链表 
	s = ClearList(L); 
	printf("清空链表%d\n", s);
	*/
	/* 查看链表中指定位置的值 
	GetElem(L, 0, &e);	
	printf("链表中第二个元素的值是：%d", e);
	*/
	/* 查看指定值在链表中的位置 
	pos = LocateElem(L, 3, Compare);
	printf("链表中元素为3的位置是%d", pos);
	*/ 
	/* 查看链表中指定元素的前驱 
	PriorElem(L, 3, &e);
	printf("链表中指定元素的前驱是%d\n", e);
	*/
	/* 查看链表中指定元素的后缀
	NextElem(L, 3, &e);
	printf("链表中指定元素的后缀是%d\n", e);
	*/ 
	/* 插入元素 
	s = ListInsert(L, 5, 5);
	printf("插入元素%d\n", s);
	ListTraverse(L, Visit); 
	*/
	/* 删除元素 
	s = ListDelete(L, 5, &e);
	printf("删除元素%d\n", e);
	ListTraverse(L, Visit); 
	*/
	return 0;
}
