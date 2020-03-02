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

SplayTree MakeEmpty();
void Splay(SplayTree *T, Position x);
Position NewNode(TElemType data);
Position Find(SplayTree T, TElemType e);
Position FindMax(SplayTree T);
void Insert(SplayTree *T, TElemType e);
void Delete(SplayTree *T, TElemType e);
void PrintTree();
void PrintTreeSingle(Position x);

void SingleRotateWithLeft(SplayTree *T, Position x);
void SingleRotateWithRight(SplayTree *T, Position x);



#endif
