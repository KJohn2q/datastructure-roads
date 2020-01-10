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
		// һ���������������������߶Ȳ����1
		// ��ʧȥƽ�� 
		if (Height(T->left) - Height(T->right) == 2) {
			if (e < T->left->data) {
				// �����ӵ�������������
				// ����ת
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

// ɾ����㣨e�ǽ��ֵ�������ظ���� 
AvlTree Delete(AvlTree T, TElemType e)
{
	Position p;
	
	if ((p = Find(T, e)) != NULL) {
		T = DeleteNode(T, p);
	}
	
	T->height = Max(Height(T->left), Height(T->right)) + 1;
	
	return T;
}

// ɾ����㣨p�ǽ���λ�ã������ظ���� 
AvlTree DeleteNode(AvlTree T, Position p)
{
	Position tepCell;
	
	// ��Ϊ�� ����û��Ҫɾ���Ľ��  ֱ�ӷ���NULL 
	if (T == NULL || p == NULL) {
		return NULL;
	}
	
	if (p->data < T->data) {
		T->left = DeleteNode(T->left, p);
		
		// ɾ��������AVL��ʧȥƽ�⣬�������Ӧ�ĵ��� 
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
		
		// ɾ��������AVL��ʧȥƽ�⣬�������Ӧ�ĵ��� 
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
		// T�Ƕ�ӦҪɾ���Ľ�� 
		
		// T�����Һ��Ӷ��ǿ�
		if ((T->left) && (T->right)) {
			if (Height(T->left) > Height(T->right)) {
				// ���T������������������
				// ��1)�ҳ�T���������������
				// (2) ����������ֵ����T
				// (3) ɾ���������
				// �������ַ�ʽ�ĺô��ǣ�ɾ����������������AVL����Ȼ��ƽ��� 
				tepCell = FindMax(T->left);
				T->data = tepCell->data;
				T->left = DeleteNode(T->left, tepCell);
			} else {
				// ���T��������������������(��������ȣ�������������������1)
				// ��1)�ҳ�T������������С���
				// (2) ����������ֵ����T
				// (3) ɾ������С���
				// �������ַ�ʽ�ĺô��ǣ�ɾ������������С����AVL����Ȼ��ƽ��� 
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

// ����������ת 
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

