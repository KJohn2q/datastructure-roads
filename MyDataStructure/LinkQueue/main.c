#include "LinkQueue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	LinkQueue Q;
	Status s;
	int len;
	int i;
	
	s = InitQueue(&Q);
	printf("��ʼ��������%d\n", s);
	s = EnQueue(&Q, 5);
	printf("��β����Ԫ��%d\n", s);
	
	return 0;
}
