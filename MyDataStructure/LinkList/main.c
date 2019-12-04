#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	LinkList L;
	Status s;
	int len = 0;
	
	/* 初始化单链表 */
	s = InitList(&L);
	printf("初始化链表%d\n", s);
	/* 创建链表 */
	s = CreateList(L, 3);
	printf("创建链表d\n", s);
	/* 链表长度 */
	len = ListLength(L);
	printf("链表长度为：%d\n", len);
	/* 遍历链表 */ 
	ListTraverse(L, Visit);
	printf("\n", s);
	/* 清空链表 
	s = ClearList(L); 
	printf("清空链表%d\n", s);
	*/
	return 0;
}
