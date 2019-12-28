#include "SqBiTree.h"

TElemType NIL = 0; // 设整型以0为空 

/*
 * 操作结果：构造空二叉树 
 */
Status InitTree(SqBiTree T)
{
	int i;
	
	for(i = 0; i < MAX_TREE_SIZE; i++) {
		T[i] = NIL;  // 将所有结点置为空 
	}
	
	return OK;
}

/*
 * 初始条件：二叉树T已存在
 * 操作结果：销毁二叉树T 
 */
Status DestroyTree(SqBiTree T)
{
	// 由于SqBiTree是定长类型，无法销毁。 
}

/*
 * 依据层序遍历构造二叉树T 
 */ 
Status CreateTree(SqBiTree T)
{
	// 因为是完全二叉树，故不会输入空结点
	int ncount; // 表示层级
	TElemType node = NIL; // 存树结点的临时变量 
	int i;
	int j = 0;
	
	scanf("%d", &node);
	
	ncount = 1; // 从第一层开始 
	
	while(pow(2, ncount) - 1 < MAX_TREE_SIZE) {
		i = 1;
		while (i < pow(2, ncount) - 1 && node != NIL) {
			T[j] = node;
			i++;
			j++;
			scanf("%d", &node);
		}
		if (node != NIL) {
			break;
		}
		ncount++;
	} 
	
	return OK;
}

/*
 * 初始条件：二叉树T存在
 * 操作结果：将二叉树T清为空树 
 */ 
Status ClearTree(SqBiTree T)
{
	// 在二叉树的顺序存储结构中，清空等同于初始化	
	int i;
	
	for(i = 0; i < MAX_TREE_SIZE; i++) {
		T[i] = NIL;  // 将所有结点置为空 
	}
	
	return OK;
}
