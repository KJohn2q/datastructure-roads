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
	
	while(pow(2, ncount - 1) < MAX_TREE_SIZE) {
		i = 1;
		while (i <= pow(2, ncount - 1) && node != NIL && j < MAX_TREE_SIZE) {
			T[j] = node;
			i++;
			j++;
			scanf("%d", &node);
		}
		if (node == NIL) {
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

/*
 * 初始条件：二叉树T存在
 * 操作结果：若T为空二叉树，则返回TRUE，否则FALSE 
 */ 
Status BiTreeEmpty(SqBiTree T)
{
	// 根结点为空 则树为空 
	return T[0] == NIL ? TRUE : FALSE;
}

/*
 * 初始条件：二叉树T存在 
 * 操作结果：返回T的深度 
 */ 
int BiTreeDepth(SqBiTree T)
{
	int i = 0;
	int last = 0;  // 最后一个不为空的元素 
	int level = 1;  // 层数 
	int index = 0;
	
	// 二叉树判空 
	if (T[0] == NIL) {
		return ERROR;
	}
	
	while (i < MAX_TREE_SIZE - 1 && T[i] != NIL) {
		i++;
	}
	
	if (i >= MAX_TREE_SIZE - 1) {
		last = MAX_TREE_SIZE - 1;
	}
	
	if (T[i] == NIL) {
		last = i;
	}
	
	while (pow(2, level - 1) < last + 1) {
		++level;
	}
	
	return level - 1;
}

/*
 * 初始条件：二叉树T存在
 * 操作结果：返回T的根 
 */ 
Status Root(SqBiTree T, TElemType *e)
{
	if (T[0] == NIL) {
		return ERROR;
	}
    *e = T[0];
		
    return OK;
} 

/*
 * 初始条件：二叉树T存在，p是T中某个结点的位置 
 * 操作结果：返回e的值 
 */
TElemType Value(SqBiTree T, position p)
{
	int index = 0;
	int i;
	
	if (T[0] == NIL) {
		return ERROR;
	}
	
	if (p.order > pow(2, p.level - 1) || p.order < 1 || p.level < 1) {
		return ERROR;
	}
	
	for (i = 1; i <= p.level - 1; i++) {
		index += pow(2, i - 1);
	}
	
	index += p.order;
	
	if (index > MAX_TREE_SIZE) {
		return ERROR;
	}
	
	return T[index - 1];
}

/*
 * 初始条件：二叉树T存在，e是T中某个结点的位置 
 * 操作结果：结点e赋值为value 
 */
Status Assign(SqBiTree T, position p, TElemType value)
{
	int index = 0;
	int i;
	
	if (T[0] == NIL) {
		return ERROR;
	}
	
	if (p.order > pow(2, p.level - 1) || p.order < 1 || p.level < 1 || p.level > BiTreeDepth(T)) {
		return ERROR;
	}
	
	for (i = 1; i <= p.level - 1; i++) {
		index += pow(2, i - 1);
	}
	
	index += p.order;
	
	if (index > MAX_TREE_SIZE) {
		return ERROR;
	}
	
	T[index - 1] = value;
	return OK; 
}

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
Status LevelOrderTraverse(SqBiTree T, void (Visit)(TElemType))
{
	int i, j;
	int depth;
	int index = 0;
	int temp = 0;
	depth = BiTreeDepth(T);
	
	for (i = 1; i <= depth; i++) {
		
		for (j = 1; j <= pow(2, i - 1); j++) {
			index = temp;
			index += j;
			
			if(index > MAX_TREE_SIZE) {
				break;
			}
			
			Visit(T[index - 1]);
		}
		
		if(index > MAX_TREE_SIZE) {
			break;
		}
		temp += pow(2, i - 1);
	
		printf("\n");
	}
	
	return OK;
}

void Visit(TElemType e) {
	printf("%d ", e);
}
