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

Position NewNode(TElemType data) {
  Position n = malloc(sizeof(SplayNode));
  n->data = data;
  n->parent = NULL;
  n->right = NULL;
  n->left = NULL;

  return n;
}

void Splay(SplayTree *T, Position x)
{	
	Position p;
	Position g;
	
	while (x->parent) {
		if (!x->parent->parent) {
			if (x == x->parent->left) {
				SingleRotateWithLeft(T, x->parent);
			}
			else {
				SingleRotateWithRight(T, x->parent);
			}	
		}
		else {
			p = x->parent;
			g = p->parent; 
			
			// zig-zig
			if (x == p->left && p == g->left) {
				SingleRotateWithLeft(T, g);
				SingleRotateWithLeft(T, p);
			}
			// zig-zag
			if (x == p->left && p == g->right) {
				SingleRotateWithLeft(T, p);
				SingleRotateWithRight(T, g); 
			}
			// zag-zig
			if (x == p->right && p == g->left) {
				SingleRotateWithRight(T, p);
				SingleRotateWithLeft(T, g); 
			}
			// zag-zag
			if (x == p->right && p == g->right) {
				SingleRotateWithRight(T, g);
				SingleRotateWithRight(T, p);
			}
		}
	}
}

Position Find(SplayTree T, TElemType e)
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

/* get the biggest data of the tree */
Position FindMax(SplayTree T)
{
	Position x = T;
	while(x->right != NULL)
    	x = x->right;
  	return x;
}

void Insert(SplayTree *T, TElemType e) 
{
	Position node;
	Position y = NULL;
	Position x = *T;
	
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
		*T = node;
	} else if (e < y->data) {
		y->left = node;
	} else {
		y->right = node;
	}	
	Splay(T, node); 
}


void Delete(SplayTree *T, TElemType e)
{
	SplayTree leftTree;
	SplayTree rightTree;
	Position node;
	Position leftTreeMax;
	
	node = Find(*T, e);
	
	Splay(T, node);
	
	leftTree = (*T)->left;
	if (leftTree != NULL) {
		leftTree->parent = NULL;
	}
	
	rightTree = (*T)->right;
	if (rightTree != NULL) {
		rightTree->parent = NULL;
	}
	
	free(node);
	
	if (leftTree != NULL) {
		leftTreeMax = FindMax(leftTree);
		Splay(&leftTree, leftTreeMax);
		leftTree->right = rightTree;
		*T = leftTree;
	}
	else {
		*T = rightTree;
	}
		
} 

void PrintTree(SplayTree T) 
{
	PrintTreeSingle(T);
}

void PrintTreeSingle(Position x) 
{
	if (x != NULL) {
		if (x->left != NULL)
			PrintTreeSingle(x->left);
			
		if (x->right != NULL) 
			PrintTreeSingle(x->right);
			
		printf("%d ", x->data);
			
	}
}

void SingleRotateWithLeft(SplayTree *T, Position x)
{
	Position y;
	
	y = x->left;
	x->left = y->right;
	
	if (y->right != NULL) {
		y->right->parent = x;
	}
	y->parent = x->parent;
	
	// x is root of the tree 
	if (x->parent == NULL) {
		*T = y;
	} else if (x == x->parent->left) {
		x->parent->left = y;
	}
	else {
		x->parent->right = y;
	}
	y->right = x;
	x->parent = y;
}

void SingleRotateWithRight(SplayTree *T, Position x)
{
	Position y;
	
	y = x->right;
	x->right = y->left;
	if (y->left != NULL) {
		y->left->parent = x;
	}
	
	y->parent = x->parent;
	
	// x is root of the tree 
	if (x->parent == NULL) {
		*T = y;
	}
	else if (x == x->parent->left) {
		x->parent->left = y;
	} else {
		x->parent->right = y;
	}
	
	y->left = x;
	x->parent = y;
}



