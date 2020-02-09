#include "SplayTree.h"

SplayTree MakeEmpty(SplayTree T)
{
	if (T) {
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}	
	
	return NULL;
}

Position SingleRotateWithLeft(Position K2)
{
	Position K1;
	
	K1 = K2->left;
	K2->left =  K1->right;
	K1->right = K2;
	
	return K1;
}

Position SingleRotateWithRight(Position K1)
{
	Position K2;
	
	K2 = K1->right;
	K1->right = K2->left;
	K2->left = K1;
	
	return K2;
}

/*
 * 展开操作
 * top-down 
 */
SplayTree Splay(Position x, TElemType e)
{
	SplayNode Header;
	
	/* LeftTreeMax 为比x小的树 */
	/* RightTreeMin 为比e大的树 */ 
	Position LeftTreeMax, RightTreeMin;
	
	Header.left = Header.right = NULL;
	LeftTreeMax = RightTreeMin = &Header;
	
	while (e != x->data) {
		if (e < x->data) {
			if (!x->left) break;
			if (e < x->left->data) 
				x = SingleRotateWithLeft(x);
			
			/* 链接右树 */
			RightTreeMin->left = x;
			RightTreeMin = x;
			x = x->left;
		}
		if (e > x->data) {
			if (!x->right) break;
			if (e > x->right->data) 
				x = SingleRotateWithRight(x);
			
			LeftTreeMax->right = x;
			LeftTreeMx = x;
			x = x->right;
		}
		
		LeftTreeMax->right = x->left;
		RightTreeMin->left = x->right;
		
		x->left = Header.right;
		x->right = Header.left;
		
		return x; 
	}
} 

SplayTree Find(SplayTree T, TElemType e)
{
	return Splay(T, e);	
}

SplayTree Insert(SplayTree T, TElemType e)
{
	Position node;
	
	node = malloc(sizeof(SplayNode));
	
	if (!node) {
		exit(OVERFLOW);
	}
	
	if (!T) {
		node->left = node->right = NULL;
		T = node;
	}
	else {
		T = Splay(T, e);
		if (e < T->data) {
			node->left = T->left;
			node->right = T;
			T->left = NULL;
			T = node;
		}
		else if(T->data < e)
			node->right = T->right;
			node->left = T;
			T->right = NULL;
			T = node;	
		}
		else {
			return T;
		}
	}
	
	node = NULL;
	return T;
}
SplayTree Delete(SplayTree T, TElemType e); 
