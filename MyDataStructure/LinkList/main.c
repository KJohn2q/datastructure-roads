#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	LinkList L;
	Status s;
	int len = 0;
	
	/* ��ʼ�������� */
	s = InitList(&L);
	printf("��ʼ������%d\n", s);
	/* �������� */
	s = CreateList(L, 3);
	printf("��������d\n", s);
	/* ������ */
	len = ListLength(L);
	printf("������Ϊ��%d\n", len);
	/* �������� */ 
	ListTraverse(L, Visit);
	printf("\n", s);
	/* ������� 
	s = ClearList(L); 
	printf("�������%d\n", s);
	*/
	return 0;
}
