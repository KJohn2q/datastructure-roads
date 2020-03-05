#ifndef AVLTREE_H
#define AVLTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int TElemType;

typedef struct AvlNode {
	TElemType data;  // 数据域 
	struct AvlNode *left;  // 左子树 
	struct AvlNode *right; // 右子树 
	int height;  // 高度 
}AvlNode, *Position, *AvlTree;

AvlTree MakeEmpty(AvlTree T);

Position Find(AvlTree T, TElemType e);

Position FindMin(AvlTree T);

Position FindMax(AvlTree T);

AvlTree Insert(AvlTree T, TElemType e);

// 删除结点（e是结点值），返回根结点 
AvlTree Delete(AvlTree T, TElemType e);

// 删除结点（p是结点的位置），返回根结点 
AvlTree DeleteNode(AvlTree T, Position p);

static int Height(Position P);

// 左子树单旋转 
static Position SingleRotateWithLeft(Position k2);

static Position DoubleRotateWithLeft(Position k3);

static Position SingleRotateWithRight(Position k1);

static Position DoubleRotateWithRight(Position k3);

static int Max(int m, int n);

void TreeTraverse(AvlTree T);

void Visit(TElemType data);

#endif
