#ifndef _BTREE_H
#define _BTREE_H

#include <stdio.h>
#include <stdlib.h> 
#include "../common.h"

#define M 3   // order of B-Tree
typedef int TElemType;

typedef struct BTNode {
	int n;  //  n <= M  No. of keys in BTNode always less than order(½×Êý) of B-Tree 
	TElemType keys[M];  // No. of keys in BTNode
	int t; // No. of child node  
	struct BTNode *p[M];  // No. of node 
	struct BTNode *parent;
} BTNode, * BTree, * Position;

Position NewNode(TElemType e);
void Insert(BTree *T, TElemType e);
Position Find(BTree T, TElemType e);


#endif
