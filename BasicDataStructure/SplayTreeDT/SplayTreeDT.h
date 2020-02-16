#ifndef _SPLAYTREE_DT_H
#define _SPLAYTREE_DT_H

#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

typedef int TElemType;

typedef struct SplayNode {
	TElemType data;
	struct SplayNode* parent; 
	struct SplayNode* left;
	struct SplayNode* right;
} SplayNode, *SplayTree;

typedef struct SplayNode *Position;

SplayTree MakeEmpty(SplayTree T);
SplayTree Splay(Position x, TElemType e);
SplayTree Find(SplayTree T, TElemType e);
SplayTree Insert(SplayTree T, TElemType e);
SplayTree Delete(SplayTree T, TElemType e);
void PrintTree(SplayTree T);

Position SingleRotateWithLeft(Position K2);
Position SingleRotateWithRight(Position K1);



#endif
