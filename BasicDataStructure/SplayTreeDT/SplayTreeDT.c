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

SplayTree Splay(Position x, TElemType e)
{
	Position K,K2;
	while (x->parent) {
		if (x->parent->parent) {
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
		else {
			if (x == x->parent->left) {
				K = SingleRotateWithLeft(x);
			}
			else {
				K = SingleRotateWithRight(x);
			}
		}
	}	
	
	return (SplayTree) K;
}

SplayTree Find(SplayTree T, TElemType e);
SplayTree Insert(SplayTree T, TElemType e);
SplayTree Delete(SplayTree T, TElemType e);
void PrintTree(SplayTree T);

Position SingleRotateWithLeft(Position K2)
{
	Position K1;

    K1 = K2->Left;
    K2->Left = K1->Right;
    K1->Right = K2;

    return K1;  /* New root */
}

Position SingleRotateWithRight(Position K1)
{
	Position K2;

    K2 = K1->right;
    K1->right = K2->left;
    K2->left = K1;

    return K2;  /* New root */
}

