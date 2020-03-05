#include "SqStack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	SqStack S;
	Status s;
	int i = 0;
	SElemType e;
	int len = 0;
	
	s = InitStack(&S);
	printf("栈的初始化%d\n", s);
	s = StackEmpty(S);
	printf("栈是否为空%d\n", s);
	for (i = 0; i < 10; i++) {
		Push(&S, 5 * i);
	}
	/*
	s = GetTop(S, &e);
	printf("取栈顶的值%d\n", e);
	*/
	
	s = Pop(&S, &e);
	printf("弹出栈顶的值%d\n", s);
	
	len = StackLength(S);
	printf("栈的长度%d\n", len);
	
	StackTraverse(S, Visit);
	return 0;
}
