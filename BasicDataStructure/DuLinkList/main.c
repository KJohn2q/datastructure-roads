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
	printf("��ʼ������%d\n", s);
	s = ListEmpty(D);
	printf("�����Ƿ�Ϊ��%d\n", s);
	for (i = 1; i <= 10; i++) {
		ListInsert(D, i, i * 2);
		ListTraverse(D, Visit);
	}	
	/*
	cur = LocateElem(D, 2, Compare);	
	printf("2�������е�λ��%d\n", cur);
	*/
	/*
	s = GetElem(D, 1, &e);
	printf("�ڶ���Ԫ�ص�ֵ%d\n", e);
	printf("ȡֵ����%d\n", s);
	*/
	/*
	s = ListDelete(D, 3, &e);
	printf("������ɾ����ֵ%d\n", e);
	printf("����Ԫ�ز���%d\n", s);
	*/
	/* 
	s = PriorElem(D, 2, &e);
	printf("������ָ��Ԫ�ص�ǰ��Ϊ%d\n", e);
	printf("����ǰ������%d\n", s);
	*/
	/* 
	s = NextElem(D, 10, &e);
	printf("������ָ��Ԫ�صĺ��Ϊ%d\n", e);
	printf("�����̲���%d\n", s);
	*/
	
//	ListTraverse(D, Visit);
	
	return 0;
}
