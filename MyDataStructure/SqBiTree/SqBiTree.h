#ifndef SQBITREE_H
#define SQBITREE_H

#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

#define MAX_TREE_SIZE 100  // 二叉树的最大结点数 

typedef int TElemType;

TElemType Nil = 0; // 设整型以0为空 

typedef TElemType SqBiTree[MAX_TREE_SIZE]; // 0号单元存储根节点 

/*
 *  初始化二叉树
 *  每个节点均设置为空 
 */
Status InitTree(SqBiTree *T);

Status DestroyTree(SqBiTree *T);

Status CreateTree(SqBiTree *T);

Status ClearTree(SqBiTree *T); 

Status BiTreeEmpty(SqBiTree T);

int BiTreeDepth(SqBiTree T);

TElemType Root(SqBiTree T); 

#endif
