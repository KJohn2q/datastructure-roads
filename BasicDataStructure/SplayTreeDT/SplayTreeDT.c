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
	
	K = x;
	
	while (x->parent) {
		if (x->parent->parent != NULL) {
			if (x == x->parent->left) {
				K = SingleRotateWithLeft(x);
			}
			else {
				K = SingleRotateWithRight(x);
			}	
		}
		else {
			// zig-zig
			if (x == x->parent->left && x->parent == x->parent->parent->left) {
				K2 = SingleRotateWithLeft(x->parent);
				K = SingleRotateWithLeft(K2->left); 
			}
			// zag-zig
			if (x == x->parent->left && x->parent == x->parent->parent->right) {
				K2 = SingleRotateWithLeft(x);
				K = SingleRotateWithRight(K2); 
			}
			// zig-zag
			if (x == x->parent->right && x->parent == x->parent->parent->left) {
				K2 = SingleRotateWithRight(x);
				K = SingleRotateWithLeft(K2); 
			}
			// zag-zag
			if (x == x->parent->left && x->parent == x->parent->parent->right) {
				K2 = SingleRotateWithLeft(x->parent);
				K = SingleRotateWithLeft(K2->right); 
			}
		}
	}	
	
	return K;
}

SplayTree Find(SplayTree T, TElemType e)
{
	return Splay(T);
}

SplayTree Insert(SplayTree T, TElemType e)
{
	Position node;
	
	node = malloc(sizeof(SplayNode));
	
	if (!node) {
		exit(OVERFLOW);
	}
	
	node->data = e;
	
	if (T == NULL) {
		node->left = node->right = node->parent = NULL;
		T = node;
	} 
	else {
		if (e < T->data) {
			node->left = T->left;
			node->right = T;
			
			T->left = NULL;
			T->parent = node;
			T = node;
		}
		else if(e > T->data) {
			node->right = T->right;
			node->left = T;
			
			T->right = NULL;
			T->parent = node;
			T = node;
		}
		else {
			T = Splay(T);
			return T;
		}
	}
	
	node = NULL;
	
	T = Splay(T);
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

Position SingleRotateWithLeft(Position K2)
{
	Position K1;

    K1 = K2->left;
    
    K2->left = K1->right;
    K1->right->parent = K2; 
    K1->right = K2;
    
    K1->parent = K2->parent;
    K2->parent = K1;

    return K1;  /* New root */
}

Position SingleRotateWithRight(Position K1)
{
	Position K2;

    K2 = K1->right;
    
    K1->right = K2->left;
    K2->left->parent = K1;
    K2->left = K1;
    
    K2->parent = K1->parent;
    K1->parent = K2;

    return K2;  /* New root */
}

