#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int TElemType;

typedef struct SplayNode {
	TElemType data;
	struct SplayNode* left;
	struct SplayNode* right;
} SplayNode, *SplayTree;

typedef struct SplayNode *Position;

SplayTree MakeEmpty(SplayTree T);
SplayTree Splay(Position x, TElemType e);
SplayTree Find(SplayTree T, TElemType e);
SplayTree Insert(SplayTree T, TElemType e);
SplayTree Delete(SplayTree T, TElemType e); 

Position SingleRotateWithRight(Position K1);
Position SingleRotateWithRight(Position K2);


#endif
