#include "SearchBiTree.h"

/*
 * ����һ�ÿ��� 
 */
SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL) {
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}
	
	return NULL;
}

/*
 * �ҵ�data��Ϊe�Ľ�� 
 */
Position Find(SearchTree T, TElemType e)
{
	if (T == NULL) {
		return NULL;
	}	
	if (e < T->data) {
		Find(T->left, e);
	} 
	else if(e > T->data) {
		Find(T->right, e);
	}
	else {
		return T;
	}
} 

Position FindMin(SearchTree T)
{
	if (T == NULL) {
		return NULL;
	}
	if (T->left != NULL) {
		FindMin(T->left);
	}
	else {
		return T;
	}
}

Position FindMax(SearchTree T)
{
	if (T != NULL) {
		while (T->right != NULL) {
			T = T->right;
		}
	} 
	
	return T;
}

SearchTree Insert(SearchTree T, TElemType e)
{
	if (T == NULL) {
		T = (SearchTree) malloc(sizeof(TreeNode));
		
		if (T == NULL) {
			exit(OVERFLOW);
		}
		T->data = e;
		T->left = T->right = NULL;
	}
	else {
		if (e < T->data) {
			T->left = Insert(T->left, e);
		}
		else if (e > T->data) {
			T->right = Insert(T->right, e);
		}
		// ���e == T->data ���ʾ�����Ѿ��и�Ԫ��  ʲôҲ���� 
	}
	
	return T;
}

SearchTree Delete(SearchTree T, TElemType e)
{
	Position TmpCell;
	
	if (T == NULL) {
		printf("Element not fund");
		exit(0);
	}
	else {
		if (e < T->data) {
			T->left = Delete(T->left, e);
		}
		else if (e > T->data) {
			T->right = Delete(T->right, e);
		}
		else if (T->left && T->right) {
			// ������������ӽ�㣬��ѡ������������С�Ľ�����ý�������
			// ���ݹ��ɾ���Ǹ���� 
			TmpCell = FindMin(T->right);
			T->data = TmpCell->data;
			T->right = Delete(T->right, T->data);
		}
		else {
			// ֻ��һ����û�к��ӽ��
			TmpCell = T;
			if (T->left == NULL) {
				T = T->right;
			}	
			else if (T->right == NULL) {
				T = T->left;
			}
			free(TmpCell);
		}
	} 
	return T;
}

void TreeTraverse(SearchTree T)
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
