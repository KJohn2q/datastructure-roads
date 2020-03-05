#include "LinkStack.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	LinkStack S;
	Status s;
	int len;
	int i = 0;
	SElemType e;
	
	s = InitStack(&S);
	printf("初始化链栈%d\n", s);
	/* 
	s = DestroyStack(&S);
	printf("销毁链栈%d\n", s);
	*/
	/*
	s = ClearStack(&S);
	printf("清空链栈%d\n", s);
	*/
	for(i = 0; i < 10; i++) {
		Push(&S, 2*i);
	}
	/*
	s = Push(&S, 5);
	printf("插入元素%d\n", s);
	*/
	/*
	GetTop(S, &e);
	printf("栈顶元素为%d\n", e);
	*/
	s = Pop(&S, &e);
	printf("弹出栈顶元素%d,栈顶元素为%d\n", s, e);
	
	StackTraverse(S, Visit);
	
	return 0;
}
