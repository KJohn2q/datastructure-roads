#ifndef SQBITREE_H
#define SQBITREE_H

#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

#define MAX_TREE_SIZE 100  // 二叉树的最大结点数 

typedef int TElemType;

TElemType Nil = 0; // 设整型以0为空 

typedef TElemType SqBiTree[MAX_TREE_SIZE]; // 0号单元存储根节点 

typedef struct {
	int level, order;
} position;

/*
 *  初始化二叉树
 *  每个节点均设置为空 
 */
Status InitTree(SqBiTree *T);

/*
 *  销毁 
 */
Status DestroyTree(SqBiTree *T);

/*
 *  创建完全二叉树 
 */ 
Status CreateTree(SqBiTree *T);

/*
 *  清空二叉树 
 */ 
Status ClearTree(SqBiTree *T); 

/*
 * 二叉树判空 
 */ 
Status BiTreeEmpty(SqBiTree T);

/*
 * 二叉树的深度 
 */ 
int BiTreeDepth(SqBiTree T);

/*
 * 二叉树的根 
 */ 
Status Root(SqBiTree T, TElemType *e); 

/*
 *  返回处于位置e的节点的值 
 */
TElemType Value(SqBiTree T, position p);

/*
 *  给位于p位置处的节点赋新值value 
 */
Status Assign(SqBiTree T, position p, TElemType value);

/*
 *  返回节点e的双亲 
 */
TElemType Parent(SqBiTree T, TElemType e);

/*
 *  返回节点e的左孩子 
 */ 
TElemType LeftChild(SqBiTree T, TElemType e);

/*
 *  返回节点e的右孩子 
 */
TElemType RightChild(SqBiTree T, TElemType e);

/*
 *  返回e的左兄弟 
 */
TElemType LeftSibling(SqBiTree T, TElemType e);

/*
 *  返回e的右兄弟 
 */
TElemType RightSibling(SqBiTree T, TElemType e);

#endif
