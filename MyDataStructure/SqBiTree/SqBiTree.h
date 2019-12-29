#ifndef SQBITREE_H
#define SQBITREE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../common.h"

#define MAX_TREE_SIZE 5  // 二叉树的最大结点数 

typedef int TElemType;


typedef TElemType SqBiTree[MAX_TREE_SIZE]; // 0号单元存储根节点 

typedef struct {
	int level, order;
} position;

/*
 * 操作结果：构造空二叉树 
 */
Status InitTree(SqBiTree T);

/*
 * 初始条件：二叉树T已存在
 * 操作结果：销毁二叉树T 
 */
Status DestroyTree(SqBiTree T);

/*
 * 依据层序遍历构造二叉树T 
 */ 
Status CreateTree(SqBiTree T);

/*
 * 初始条件：二叉树T存在
 * 操作结果：将二叉树T清为空树 
 */ 
Status ClearTree(SqBiTree T); 

/*
 * 初始条件：二叉树T存在
 * 操作结果：若T为空二叉树，则返回TRUE，否则FALSE 
 */ 
Status BiTreeEmpty(SqBiTree T);

/*
 * 初始条件：二叉树T存在 
 * 操作结果：返回T的深度 
 */ 
int BiTreeDepth(SqBiTree T);

/*
 * 初始条件：二叉树T存在
 * 操作结果：返回T的根 
 */ 
Status Root(SqBiTree T, TElemType *e); 

/*
 * 初始条件：二叉树T存在，e是T中某个结点 
 * 操作结果：返回e的值 
 */
TElemType Value(SqBiTree T, position p);

/*
 * 初始条件：二叉树T存在，e是T中某个结点
 * 操作结果：结点e赋值为value 
 */
Status Assign(SqBiTree T, position p, TElemType value);

/*
 * 初始条件：二叉树T存在，e是T中某个结点
 * 操作结果：若e是T的非根结点，则返回它的双亲，否则返回“空 ” 
 */
TElemType Parent(SqBiTree T, TElemType e);

/*
 * 初始条件：二叉树T存在，e是T中某个结点
 * 操作结果：返回e的左孩子。若e无左孩子，则返回“空” 
 */ 
TElemType LeftChild(SqBiTree T, TElemType e);

/*
 * 初始条件：二叉树T存在，e是T中某个结点 
 * 操作结果：返回e的右孩子。若e无右孩子，则返回“空” 
 */
TElemType RightChild(SqBiTree T, TElemType e);

/*
 * 初始条件：二叉树T存在，e是T中某个结点 
 * 操作结果：返回e的左兄弟。若e是T的左孩子或无左兄弟，则返回“空” 
 */
TElemType LeftSibling(SqBiTree T, TElemType e);

/*
 * 初始条件：二叉树T存在，e是T中某个结点
 * 操作结果：返回e的右兄弟。若e是T的右孩子或无右兄弟，则返回“空” 
 */
TElemType RightSibling(SqBiTree T, TElemType e);

/*
 * 把从q的j节点开始的子树移为从T的i节点开始的子树 
 */
void Move(SqBiTree q, int j, SqBiTree T, int i);

/*
 * 初始条件：二叉树T存在，p指向T中某个结点，LR为0或1，非空二叉树c与T不相交且右子树为空 
 * 操作结果：根据LR为0或1，插入c为T中p结点的左或右子树。p结点的原有左或右子树则成为c的右子树 
 */ 
Status InsertChild(SqBiTree T, TElemType p, Status LR, SqBiTree c); 

/*
 * 初始条件：二叉树T存在，p指向T中某个结点，LR为0或1
 * 操作结果：根据LR为0或1，删除T中p所指结点的左或右子树 
 */
Status DeleteChild(SqBiTree T, TElemType p, Status LR); 

/*
 * 初始条件：二叉树T存在，Visit是对结点操作的应用函数
 * 操作结果：先序遍历T，对每个结点调用函数Visit一次且仅一次，一旦visit()失败，则操作失败 
 */
Status PreOrderTraverse(SqBiTree T, void (Visit)(TElemType));

/*
 * 初始条件：二叉树T存在，Visit是对结点操作的应用函数
 * 操作结果：中序遍历T，对每个结点调用函数Visit一次且仅一次，一旦visit()失败，则操作失败 
 */
Status InOrderTraverse(SqBiTree T, void (Visit)(TElemType));

/*
 * 初始条件：二叉树T存在，Visit是对结点操作的应用函数
 * 操作结果：后序遍历T，对每个结点调用函数Visit一次且仅一次，一旦visit()失败，则操作失败 
 */
Status PostOrderTraverse(SqBiTree T, void (Visit)(TElemType));

/*
 * 初始条件：二叉树T存在，Visit是对结点操作的应用函数
 * 操作结果：层序遍历T，对每个结点调用函数Visit一次且仅一次，一旦visit()失败，则操作失败 
 */
Status LevelOrderTraverse(SqBiTree T, void (Visit)(TElemType));

void Visit(TElemType e);
#endif
