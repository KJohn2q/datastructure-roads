#include "SplayTreeDT.h"

SplayTree MakeEmpty(SplayTree T)
{
	if (!T) {
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		if (T->left) {
			T->left->parent = NULL;	
		}
		if (T->right) {
			T->right->parent = NULL;
		}
		free(T);
	}	
	return NULL;
}

SplayTree Splay(Position x)
{
	Position K,K2;
	
	while (x->parent) {
		if (!x->parent->parent) {
			if (x == x->parent->left) {
				x = SingleRotateWithLeft(x->parent);
			}
			else {
				x = SingleRotateWithRight(x->parent);
			}	
		}
		else {
			// zig-zig
			if (x == x->parent->left && x->parent == x->parent->parent->left) {
				SingleRotateWithLeft(x->parent->parent);
				SingleRotateWithLeft(x->parent);
			}
			// zag-zig
			if (x == x->parent->left && x->parent == x->parent->parent->right) {
				SingleRotateWithLeft(x->parent);
				SingleRotateWithRight(x->parent); 
			}
			// zig-zag
			if (x == x->parent->right && x->parent == x->parent->parent->left) {
				SingleRotateWithRight(x->parent);
				SingleRotateWithLeft(x->parent); 
			}
			// zag-zag
			if (x == x->parent->right && x->parent == x->parent->parent->right) {
				SingleRotateWithRight(x->parent->parent);
				SingleRotateWithRight(x->parent);
			}
		}
	}
	
	return x;
}

SplayTree Find(SplayTree T, TElemType e)
{
	while (T != NULL && T->data != e) {
		if (e < T->data && T->left != NULL) {
			T = T->left;
		}
		else if (e > T->data && T->right != NULL) {
			T = T->right;
		}
	}
	
	return T;
}

SplayTree Insert(SplayTree T, TElemType e) 
{
	Position node;
	Position y = NULL;
	
	node = malloc(sizeof(SplayNode));
	node->data = e;
	
	if (!node) {
		exit(OVERFLOW);
	} 
	
	while (T != NULL) {
		y = T;
		if (e < T->data) {
			T = T->left;
		} else {
			T = T->right;
		}
	}
	
	if (y == NULL) {
		y = node;
	} else if (e < y->data) {
		y->left = node;
	} else {
		y->right = node;
	}
	
	T = Splay(node); 
	
	return T;
}


SplayTree Delete(SplayTree T, TElemType e);

void PrintTree(SplayTree T) 
{
	if (T != NULL) {
		PrintTree(T->left);
		printf("%d ", T->data);
		PrintTree(T->right);
	}
}

Position SingleRotateWithLeft(Position x)
{
	Position y;
	
	y = x->left;
	x->left = y->right;
	
	if (y->right != NULL) {
		y->right->parent = x;
	}
	y->parent = x->parent;
	if (x == x->parent->left) {
		x->parent->left = y;
	}
	else if (x == x->parent->right) {
		x->parent->right = y;
	}
	y->right = x;
	x->parent = y;
	
	return y;
}

Position SingleRotateWithRight(Position x)
{
	Position y;
	
	y = x->right;
	x->right = y->left;
	if (y->left != NULL) {
		y->left->parent = x;
	}
	
	y->parent = x->parent;
	if (x == x->parent->left) {
		x->parent->left = y;
	} else if (x == x->parent->right) {
		x->parent->right = y;
	}
	
	y->left = x;
	x->parent = y;
	
	return y;
}



