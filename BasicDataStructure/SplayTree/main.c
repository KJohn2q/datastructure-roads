#include "SplayTree.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	SplayTree T = NULL;
	
	T = MakeEmpty(T);
	
	
	T = Insert(T, 5);
	T = Insert(T, 10);
	T = Insert(T, 4);
	T = Insert(T, 3);
	
	T = Delete(T, 4);
	
	PrintTree(T);
	return 0;
}
