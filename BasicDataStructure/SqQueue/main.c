#include "SqQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	SqQueue Q;
	Status s;
	int len;
	int i;
	QElemType e;
	
	s = InitQueue(&Q);
	printf("初始化顺序队列%d\n", s);
	for (i = 0; i < 10; i++) {
		EnQueue(&Q, 5*(i+1));
	}
	/* 销毁队列 
	s = DestroyQueue(&Q);
	printf("销毁队列测试%d\n", s);
	*/ 
	/* 清空队列 
	s = ClearQueue(&Q);
	printf("清空队列测试%d\n", s);
	*/ 
	/*
	s = QueueEmpty(Q);
	printf("判空测试%d\n", s);
	*/
	/*  删除测试 
	s = DeQueue(&Q, &e); 
	printf("队列队头元素删除测试%d\n", s);
	printf("队列删除的队头元素为%d\n", e);
	*/
	/*  长度测试 
	len = QueueLength(Q);
	printf("队列长度为%d\n", len);
	*/
	QueueTraverse(Q, Visit);
	
	return 0;
}
