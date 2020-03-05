#include "../Sort/InsertSort/InsertSort.h" 
#include "BTree.h"

void Insert(BTree *T, TElemType e)
{
	// B-tree is empty
	if (T == NULL) {
		T = malloc(sizeof(BTNode));
		
		if (!T) {
			exit(OVERFLOW);
		}
		
		T->keys[0] = e;
		T->n = 1;  //  No. of the keys 
		T->t = 0;  // No. of the child node.
	}
	else {
		// B-tree is not empty
			
	}
}


