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
void Splay(Position x);
Position Find(TElemType e);
void Insert(TElemType e);
void Delete(TElemType e);
void PrintTree();
void PrintTreeSingle(Position x);

void SingleRotateWithLeft(Position K2);
void SingleRotateWithRight(Position K1);



#endif
