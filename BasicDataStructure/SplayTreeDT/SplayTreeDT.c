#include "SplayTreeDT.h"

SplayTree T;

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

void Splay(Position x)
{	
	while (x->parent) {
		if (!x->parent->parent) {
			if (x == x->parent->left) {
				SingleRotateWithLeft(x->parent);
			}
			else {
				SingleRotateWithRight(x->parent);
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
}

Position Find(TElemType e)
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

void Insert(TElemType e) 
{
	Position node;
	Position y = NULL;
	Position x = T;
	
	node = malloc(sizeof(SplayNode));
	node->data = e;
	node->left = node->right = node->parent = NULL;
	
	if (!node) {
		exit(OVERFLOW);
	} 
	
	while (x != NULL) {
		y = x;
		if (e < x->data) {
			x = x->left;
		} else {
			x = x->right;
		}
	}
	
	node->parent = y;
	if (y == NULL) {
		T = node;
	} else if (e < y->data) {
		y->left = node;
	} else {
		y->right = node;
	}	
	Splay(node); 
}


void Delete(TElemType e);

void PrintTree() 
{
	PrintTreeSingle(T);
}

void PrintTreeSingle(Position x) 
{
	if (x != NULL) {
		if (x->left != NULL)
			PrintTreeSingle(x->left);
		printf("%d ", x->data);
		
		if (x->right != NULL) 
			PrintTreeSingle(x->right);
	}
}

void SingleRotateWithLeft(Position x)
{
	Position y;
	
	y = x->left;
	x->left = y->right;
	
	if (y->right != NULL) {
		y->right->parent = x;
	}
	y->parent = x->parent;
	
	if (x->parent == NULL) {
		T = y;
	} else if (x == x->parent->left) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	y->right = x;
	x->parent = y;
}

void SingleRotateWithRight(Position x)
{
	Position y;
	
	y = x->right;
	x->right = y->left;
	if (y->left != NULL) {
		y->left->parent = x;
	}
	
	y->parent = x->parent;
	
	if (x->parent == NULL) {
		T = y;
	}
	else if (x == x->parent->left) {
		x->parent->left = y;
	} else {
		x->parent->right = y;
	}
	
	y->left = x;
	x->parent = y;
}



