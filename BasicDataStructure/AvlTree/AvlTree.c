#include "AvlTree.h"

AvlTree MakeEmpty(AvlTree T)
{
	if (T != NULL) {
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}
	
	return NULL;
}

Position Find(AvlTree T, TElemType e)
{
	if (T == NULL) {
		return NULL;
	}
	
	if (e < T->data) {
		return Find(T->left, e);
	} 
	else if (e > T->data) {
		return Find(T->right, e);
	} 
	else {
		return T;
	}
}
 
Position FindMin(AvlTree T)
{
	if (T == NULL) {
		return NULL;
	}
	else if (T->left == NULL) {
		return T;
	}
	else {
		return FindMin(T->left);
	}
}

Position FindMax(AvlTree T)
{
	if (T != NULL) {
		while (T->right != NULL) {
			T = T->right;
		}		
	}
	return T;	
}

AvlTree Insert(AvlTree T, TElemType e)
{
	if (T == NULL) {
		T = (AvlTree) malloc(sizeof(AvlNode));
		
		if (T == NULL) {
			exit(0);
		}
		
		T->data = e;
		T->left = T->right = NULL;
	}	
	else if (e < T->data) {
		T->left = Insert(T->left, e);
		// 一个结点的左子树与右子树高度差大于1
		// 则失去平衡 
		if (Height(T->left) - Height(T->right) == 2) {
			if (e < T->left->data) {
				// 在左孩子的左子树插入结点
				// 单旋转
				T = SingleRotateWithLeft(T); 
			} 
			else {
				T = DoubleRotateWithLeft(T);
			}
		}
	}	
	else if (e > T->data) {
		T->right = Insert(T->right, e);
		if (Height(T->right) - Height(T->left) == 2) {
			if (e > T->right->data) {
				T = SingleRotateWithRight(T);
			}
			else {
				T = DoubleRotateWithRight(T);
			}
		}
	}
	
	T->height = Max(Height(T->left), Height(T->right)) + 1;
	return T;
} 

static int Height(Position P)
{
	if (P == NULL) {
		return -1;
	}
	else {
		return P->height;
	}
}

// 左子树单旋转 
static Position SingleRotateWithLeft(Position k2)
{
	Position k1;
	
	k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	
	k2->height = Max(Height(k2->left), Height(k2->right)) + 1;
	k1->height = Max(Height(k1->left), k2->height) + 1;
	
	return k1;
}

static Position DoubleRotateWithLeft(Position k3)
{
	SingleRotateWithRight(k3->right);
	
	return SingleRotateWithLeft(k3);	
}

static Position SingleRotateWithRight(Position k1)
{
	Position k2;
	
	k2 = k1->right;
	k1->right = k2->left;
	k2->left = k1;
	
	k1->height = Max(Height(k1->left), Height(k1->right)) + 1;
	k2->height = Max(Height(k2->right), k1->height) + 1;
	
	return k2;
}

static Position DoubleRotateWithRight(Position k1)
{	
	SingleRotateWithLeft(k1->right);
	
	return SingleRotateWithRight(k1);
}

static int Max(int m, int n) 
{
	return m > n ? m : n;
}

void TreeTraverse(AvlTree T)
{
	if (T != NULL) {
		TreeTraverse(T->left);
		
		Visit(T->data);	 
		
		TreeTraverse(T->right);			
	}
}

void Visit(TElemType data)
{
	printf("%d ", data);
}

AvlTree Delete(AvlTree T, TElemType e)
{
	Position tempCell;
	if (T == NULL) {
		return NULL; 
	}
	
	if (e < T->data) {
		T->left = Delete(T->left, e);
	} 
	else if (e > T->data) {
		T->right = Delete(T->right, e);
	}
	else {
		// e = T->data
		// 找到要删除的结点
		if (!T->left && !T->right) {
			// 叶子结点
		}
		else if (T->left && !T->right) {
			// 只有左结点 
		}
		else if (T->right && !T->left) {
			// 只有右结点 
		}
		else {
			// 既有左结点 也有右结点
			 
		}
		
		
	}
}
