#ifndef AVLTREE_H
#define AVLTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int TElemType;

typedef struct AvlNode {
	TElemType data;  // ������ 
	struct AvlNode *left;  // ������ 
	struct AvlNode *right; // ������ 
	int height;  // �߶� 
}AvlNode, *Position, *AvlTree;

AvlTree MakeEmpty(AvlTree T);

Position Find(AvlTree T, TElemType e);

Position FindMin(AvlTree T);

Position FindMax(AvlTree T);

AvlTree Insert(AvlTree T, TElemType e);

AvlTree Delete(AvlTree T, TElemType e);

static int Height(Position P);

// ����������ת 
static Position SingleRotateWithLeft(Position k2);

static Position DoubleRotateWithLeft(Position k3);

static Position SingleRotateWithRight(Position k1);

static Position DoubleRotateWithRight(Position k3);

static int Max(int m, int n);

void TreeTraverse(AvlTree T);

void Visit(TElemType data);

#endif
