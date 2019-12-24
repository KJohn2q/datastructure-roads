#include "LinkQueue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	LinkQueue Q;
	Status s;
	int len;
	int i;
	
	s = InitQueue(&Q);
	printf("初始化链队列%d\n", s);
	s = EnQueue(&Q, 5);
	printf("队尾插入元素%d\n", s);
	
	return 0;
}
