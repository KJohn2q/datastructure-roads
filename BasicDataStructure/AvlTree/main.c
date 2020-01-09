#include "AvlTree.h"

int main(int argc, char *argv[]) {
	AvlTree T = NULL;
	Position P = NULL;
	int i = 1;
	int arr[] = {6, 2, 1, 4, 3, 8, 10, 5};
	
	T = MakeEmpty(T);
	
	for (i = 0; i < 8; i++) {
		T = Insert(T, arr[i]);
	}
	
	T = Delete(T, 6);
	
	TreeTraverse(T);
	
	return 0;
}
