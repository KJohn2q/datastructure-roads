#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int TElemType;

typedef struct SplayNode {
	TElemType data;
	typedef SplayNode* left;
	typedef SplayNode* right;
}SplayNode, *SplayTree;

typedef struct SplayNode *Position;

SplayTree Initialize(void);
SplayTree MakeEmpty(SplayTree T);
SplayTree Splay(Position x, TElemType e);
SplayTree Find(SplayTree T, TElemType e);
SplayTree FindMin(SplayTree T);
SplayTree FindMax(SplayTree T);
SplayTree Insert(SplayTree T, TElemType e);
SplayTree Delete(SplayTree T, TElemType e); 

#endif
