#include "LinkQueue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	LinkQueue Q;
	Status s;
	int len;
	int i;
	QElemType e;
	
	s = InitQueue(&Q);
	printf("初始化链队列%d\n", s);
	
	for (i = 0; i < 10; i++) {
		EnQueue(&Q, 5*(i+1));
	}
	
	/*  清空测试 
	s = ClearQueue(&Q);
	printf("链队列清空%d\n", s);
	*/
	/* 销毁测试 
	s = DestroyQueue(&Q);
	printf("链队列销毁%d\n", s); 
	*/ 
	/*  判空测试 
	s = QueueEmpty(Q);
	printf("链队列判空%d\n", s);
	*/
	/*  删除头元素 
	s = DeQueue(&Q, &e);
	printf("链队列删除头元素%d\n", e);
	*/
	/*  获取头元素 
	s = GetHead(Q, &e);
	printf("链队列头元素%d\n", e);
	*/
	QueueTraverse(Q, Visit);
	
	return 0;
}
