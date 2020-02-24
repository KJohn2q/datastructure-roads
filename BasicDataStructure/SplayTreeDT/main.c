#include "SplayTreeDT.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	SplayTree T;
	
	T = MakeEmpty(T);
	T = Insert(T, 11);
	T = Insert(T, 13);
	T = Insert(T, 14);
	T = Insert(T, 12);
	T = Insert(T, 17);
	T = Insert(T, 16);
	T = Insert(T, 20);
	T = Insert(T, 21);
	T = Insert(T, 18);
	T = Insert(T, 15); 
	
	PrintTree(T);
	
	return 0;
}
