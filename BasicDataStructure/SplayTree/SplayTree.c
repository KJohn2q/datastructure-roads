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

/*
 * չ������ 
 */
SplayTree Splay(Position x, TElemType e);

SplayTree Find(SplayTree T, TElemType e)
{
		
}

SplayTree FindMin(SplayTree T);
SplayTree FindMax(SplayTree T);
SplayTree Insert(SplayTree T, TElemType e);
SplayTree Delete(SplayTree T, TElemType e); 
