#include "LinkStack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	LinkStack S;
	Status s;
	int len;
	int i = 0;
	SElemType e;
	
	s = InitStack(&S);
	printf("��ʼ����ջ%d\n", s);
	/* 
	s = DestroyStack(&S);
	printf("������ջ%d\n", s);
	*/
	/*
	s = ClearStack(&S);
	printf("�����ջ%d\n", s);
	*/
	for(i = 0; i < 10; i++) {
		Push(&S, 2*i);
	}
	/*
	s = Push(&S, 5);
	printf("����Ԫ��%d\n", s);
	*/
	/*
	GetTop(S, &e);
	printf("ջ��Ԫ��Ϊ%d\n", e);
	*/
	s = Pop(&S, &e);
	printf("����ջ��Ԫ��%d,ջ��Ԫ��Ϊ%d\n", s, e);
	
	StackTraverse(S, Visit);
	
	return 0;
}
