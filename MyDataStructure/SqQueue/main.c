#include "SqQueue.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	SqQueue Q;
	Status s;
	int len;
	int i;
	QElemType e;
	
	s = InitQueue(&Q);
	printf("��ʼ��˳�����%d\n", s);
	for (i = 0; i < 10; i++) {
		EnQueue(&Q, 5*(i+1));
	}
	/* ���ٶ��� 
	s = DestroyQueue(&Q);
	printf("���ٶ��в���%d\n", s);
	*/ 
	/* ��ն��� 
	s = ClearQueue(&Q);
	printf("��ն��в���%d\n", s);
	*/ 
	/*
	s = QueueEmpty(Q);
	printf("�пղ���%d\n", s);
	*/
	/*  ɾ������ 
	s = DeQueue(&Q, &e); 
	printf("���ж�ͷԪ��ɾ������%d\n", s);
	printf("����ɾ���Ķ�ͷԪ��Ϊ%d\n", e);
	*/
	/*  ���Ȳ��� 
	len = QueueLength(Q);
	printf("���г���Ϊ%d\n", len);
	*/
	QueueTraverse(Q, Visit);
	
	return 0;
}
