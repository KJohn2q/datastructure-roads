#include "SqBiTree.h"

void print(SqBiTree T) 
{
	int i;
	
	for (i = 0; i < 10; i++) {
		printf("%d ", T[i]);
	}	
}


int main(int argc, char *argv[]) {
	SqBiTree T;
	Status s;
	int len;
	TElemType e;
	position p;
	
	s = InitTree(T);
	printf("初始化二叉树%d\n", s);
	
	CreateTree(T);
	
	/* 二叉树深度 
	len = BiTreeDepth(T);
	printf("二叉树的深度为%d\n", len);
	*/
	/*  获取根元素 
	s = Root(T, &e);
	printf("获取根元素%d, 根元素的值为%d\n", s, e);
	*/
	
	/*  二叉树p结点的值 
	p.level = 1;
	p.order = 2;
	e = Value(T, p);
	printf("二叉树中p位置结点的值为%d\n", e);
	*/
	/*  设置二叉树中p位置结点的值 
	p.level = 2;
	p.order = 1;
	s = Assign(T, p, 25);
	printf("二叉树中设置p位置结点的值%d\n", s);
	*/
	/* 
	s = LevelOrderTraverse(T, Visit);
	printf("\n");	
	printf("层序遍历%d\n", s);
	*/
	s = PreOrderTraverse(T, Visit);
	printf("\n");	
	printf("先序遍历%d\n", s);
	
	return 0;
}
