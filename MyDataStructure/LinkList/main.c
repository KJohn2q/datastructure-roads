#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	LinkList L;
	Status s;
	
	/* ��ʼ�������� */
	s = InitList(L);
	printf("%d\n", s);
	/* �������� */
	s = CreateList(L, 3);
	printf("%d\n", s);
	return 0;
}
