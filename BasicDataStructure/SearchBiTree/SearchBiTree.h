#ifndef SEARCHBITREE_H
#define SEARCHBITREE_H

#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

typedef int TElemType;

typedef struct TreeNode {
	ElemType data;
	struct TreeNode *left;
	struct TreeNode *right;
}TreeNode, *Position, *SearchTree;

SearchTree MakeEmpty(SearchTree T);

Position Find(SearchTree T, TElemType e);

Position FindMin(SearchTree T);

Position FindMax(SearchTree T);

SearchTree Insert(SearchTree T, TElemType e);

SearchTree Delete(SearchTree T, TElemType e);

void TreeTraverse(SearchTree T);

void Visit(TElemType data);

#endif


