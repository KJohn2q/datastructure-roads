#include "SqBiTree.h"

void print(SqBiTree T) 
{
	int i;
	
	for (i = 0; i < 10; i++) {
		printf("%d ", T[i]);
	}	
}


int main(int argc, char *argv[]) {
	SqBiTree T;
	Status s;
	int len;
	TElemType e;
	position p;
	
	s = InitTree(T);
	printf("��ʼ��������%d\n", s);
	
	CreateTree(T);
	
	/* ��������� 
	len = BiTreeDepth(T);
	printf("�����������Ϊ%d\n", len);
	*/
	/*  ��ȡ��Ԫ�� 
	s = Root(T, &e);
	printf("��ȡ��Ԫ��%d, ��Ԫ�ص�ֵΪ%d\n", s, e);
	*/
	
	/*  ������p����ֵ 
	p.level = 1;
	p.order = 2;
	e = Value(T, p);
	printf("��������pλ�ý���ֵΪ%d\n", e);
	*/
	/*  ���ö�������pλ�ý���ֵ 
	p.level = 2;
	p.order = 1;
	s = Assign(T, p, 25);
	printf("������������pλ�ý���ֵ%d\n", s);
	*/
	/* 
	s = LevelOrderTraverse(T, Visit);
	printf("\n");	
	printf("�������%d\n", s);
	*/
	s = PreOrderTraverse(T, Visit);
	printf("\n");	
	printf("�������%d\n", s);
	
	return 0;
}
