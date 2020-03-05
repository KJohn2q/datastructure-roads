#include "BiTree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	BiTree T;
	TElemType e;
	int len;
	Status s;
	
	/*  初始化 
	s = InitBiTree(&T);
	printf("初始化二叉树%d\n", s);
	*/
	s = CreateBiTree(&T);
	printf("%d\n", s);
	
	PostOrderTraverse(T, Visit);
	
	return 0;
}
