#include "LinkQueue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	LinkQueue Q;
	Status s;
	int len;
	int i;
	QElemType e;
	
	s = InitQueue(&Q);
	printf("��ʼ��������%d\n", s);
	
	for (i = 0; i < 10; i++) {
		EnQueue(&Q, 5*(i+1));
	}
	
	/*  ��ղ��� 
	s = ClearQueue(&Q);
	printf("���������%d\n", s);
	*/
	/* ���ٲ��� 
	s = DestroyQueue(&Q);
	printf("����������%d\n", s); 
	*/ 
	/*  �пղ��� 
	s = QueueEmpty(Q);
	printf("�������п�%d\n", s);
	*/
	/*  ɾ��ͷԪ�� 
	s = DeQueue(&Q, &e);
	printf("������ɾ��ͷԪ��%d\n", e);
	*/
	/*  ��ȡͷԪ�� 
	s = GetHead(Q, &e);
	printf("������ͷԪ��%d\n", e);
	*/
	QueueTraverse(Q, Visit);
	
	return 0;
}
