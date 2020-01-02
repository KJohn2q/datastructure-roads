#include "SqStack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	SqStack S;
	Status s;
	int i = 0;
	SElemType e;
	int len = 0;
	
	s = InitStack(&S);
	printf("ջ�ĳ�ʼ��%d\n", s);
	s = StackEmpty(S);
	printf("ջ�Ƿ�Ϊ��%d\n", s);
	for (i = 0; i < 10; i++) {
		Push(&S, 5 * i);
	}
	/*
	s = GetTop(S, &e);
	printf("ȡջ����ֵ%d\n", e);
	*/
	
	s = Pop(&S, &e);
	printf("����ջ����ֵ%d\n", s);
	
	len = StackLength(S);
	printf("ջ�ĳ���%d\n", len);
	
	StackTraverse(S, Visit);
	return 0;
}
