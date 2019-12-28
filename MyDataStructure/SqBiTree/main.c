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
	
	s = InitTree(T);
	printf("³õÊ¼»¯¶þ²æÊ÷%d\n", s);
	
	CreateTree(T);
	
	
	return 0;
}
