#include "BiTree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	BiTree T;
	TElemType e;
	int len;
	Status s;
	
	/*  ��ʼ�� 
	s = InitBiTree(&T);
	printf("��ʼ��������%d\n", s);
	*/
	CreateBiTree(&T);
	
	PreOrderTraverse(T, Visit);
	
	return 0;
}
