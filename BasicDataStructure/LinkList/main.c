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
	
	
	/* ��ʼ�������� */
	s = InitList(&L);
	printf("��ʼ������%d\n", s);
	/* �������� */
	s = CreateList(L, 3);
	printf("��������%d\n", s);
	/*
	printf("����תǰ\n");
	ListTraverse(L, Visit);
	*/

	// ����ת 
	IterationInvertList(&L); 
	
	printf("����ת��\n"); 
	ListTraverse(L, Visit);
	
	/* ������ 
	len = ListLength(L);
	printf("������Ϊ��%d\n", len);
	*/ 
	/* �������� 
	ListTraverse(L, Visit);
	printf("\n", s);
	*/ 
	/* ������� 
	s = ClearList(L); 
	printf("�������%d\n", s);
	*/
	/* �鿴������ָ��λ�õ�ֵ 
	GetElem(L, 0, &e);	
	printf("�����еڶ���Ԫ�ص�ֵ�ǣ�%d", e);
	*/
	/* �鿴ָ��ֵ�������е�λ�� 
	pos = LocateElem(L, 3, Compare);
	printf("������Ԫ��Ϊ3��λ����%d", pos);
	*/ 
	/* �鿴������ָ��Ԫ�ص�ǰ�� 
	PriorElem(L, 3, &e);
	printf("������ָ��Ԫ�ص�ǰ����%d\n", e);
	*/
	/* �鿴������ָ��Ԫ�صĺ�׺
	NextElem(L, 3, &e);
	printf("������ָ��Ԫ�صĺ�׺��%d\n", e);
	*/ 
	/* ����Ԫ�� 
	s = ListInsert(L, 5, 5);
	printf("����Ԫ��%d\n", s);
	ListTraverse(L, Visit); 
	*/
	/* ɾ��Ԫ�� 
	s = ListDelete(L, 5, &e);
	printf("ɾ��Ԫ��%d\n", e);
	ListTraverse(L, Visit); 
	*/
	return 0;
}
