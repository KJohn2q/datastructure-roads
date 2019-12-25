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
	
	QueueTraverse(Q, Visit);

	return 0;
}
