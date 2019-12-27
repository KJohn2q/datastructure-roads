#include "CQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	CQueue Q;
	Status s;
	int len;
	QElemType e;
	int i;
	
	s = InitQueue(&Q);
	printf("循环队列初始化%d\n", s);
	
	for (i = 0; i < 15; i++) {
		s = EnQueue(&Q, 3 * (i + 1));
		printf("循环队列队尾插入元素%d\n", s);	
	}
	
	s = QueueEmpty(Q);
	printf("循环队列是否为空%d\n", s);
	
	len = QueueLength(Q);
	printf("循环队列长度%d\n", len);
	
	s = GetHead(Q, &e);
	printf("循环队列头部元素%d\n", e);
	
	s = DeQueue(&Q, &e);
	printf("循环队列删除头部元素%d, 头部元素为%d\n", s, e);
	
	/*  循环队列清空测试 
	s = ClearQueue(&Q);
	printf("循环队列清空%d\n", s);
	*/
	
	/*  循环队列销毁测试 
	s = DestroyQueue(&Q);
	printf("循环队列销毁%d\n", s);
	*/ 
	
	QueueTraverse(Q, Visit);

	return 0;
}
