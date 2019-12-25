#include "CQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	CQueue Q;
	Status s;
	int len;
	QElemType e;
	int i;
	
	s = InitQueue(&Q);
	printf("ѭ�����г�ʼ��%d\n", s);
	
	for (i = 0; i < 15; i++) {
		s = EnQueue(&Q, 3 * (i + 1));
		printf("ѭ�����ж�β����Ԫ��%d\n", s);	
	}
	
	QueueTraverse(Q, Visit);

	return 0;
}
