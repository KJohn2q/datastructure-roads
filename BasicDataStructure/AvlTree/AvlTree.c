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

// 删除结点（e是结点值），返回根结点 
AvlTree Delete(AvlTree T, TElemType e)
{
	Position p;
	
	if ((p = Find(T, e)) != NULL) {
		T = DeleteNode(T, p);
	}
	
	T->height = Max(Height(T->left), Height(T->right)) + 1;
	
	return T;
}

// 删除结点（p是结点的位置），返回根结点 
AvlTree DeleteNode(AvlTree T, Position p)
{
	Position tepCell;
	
	// 根为空 或者没有要删除的结点  直接返回NULL 
	if (T == NULL || p == NULL) {
		return NULL;
	}
	
	if (p->data < T->data) {
		T->left = DeleteNode(T->left, p);
		
		// 删除结点后，若AVL树失去平衡，则进行相应的调节 
		if (Height(T->right) - Height(T->left) == 2) {
			tepCell = T->left;
			
			if (Height(tepCell->left) > Height(tepCell->right)) {
				T = DoubleRotateWithLeft(T);
			} else {
				T = SingleRotateWithRight(T);
			}
		} 
	}
	else if (p->data > T->data) {
		T->right = DeleteNode(T->right, p);
		
		// 删除结点后，若AVL树失去平衡，则进行相应的调节 
		if ((Height(T->left) - Height(T->right)) == 2) {
			tepCell = T->right;
			
			if (Height(tepCell->right) > Height(tepCell->left)) {
				T = DoubleRotateWithRight(T);
			} else {
				T = SingleRotateWithLeft(T);
			}
		}
	}
	else {
		// T是对应要删除的结点 
		
		// T的左右孩子都非空
		if ((T->left) && (T->right)) {
			if (Height(T->left) > Height(T->right)) {
				// 如果T的左子树比右子树高
				// 则（1)找出T的左子树的最大结点
				// (2) 将该最大结点的值赋给T
				// (3) 删除该最大结点
				// 采用这种方式的好处是：删除左子树的最大结点后，AVL树仍然是平衡的 
				tepCell = FindMax(T->left);
				T->data = tepCell->data;
				T->left = DeleteNode(T->left, tepCell);
			} else {
				// 如果T的左子树不比右子树高(即它们相等，或右子树比左子树高1)
				// 则（1)找出T的右子树的最小结点
				// (2) 将该最大结点的值赋给T
				// (3) 删除该最小结点
				// 采用这种方式的好处是：删除右子树的最小结点后，AVL树仍然是平衡的 
				tepCell = FindMin(T->right);
				T->data = tepCell->data;
				T->right = DeleteNode(T->right, tepCell);
			}
		}
		else {
			tepCell = T;
			T = T->left ? T->left : T->right;
			free(tepCell);
		}
	}
	
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
		Visit(T->data);	
		 
		TreeTraverse(T->left);
		
		TreeTraverse(T->right);			
	}
}

void Visit(TElemType data)
{
	printf("%d ", data);
}

