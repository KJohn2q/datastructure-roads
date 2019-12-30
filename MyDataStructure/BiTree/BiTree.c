#include "BiTree.h"

/*
 * 构造空二叉树T 
 */
Status InitBiTree(BiTree *T);
{
	T = NULL; 
	return OK;
}

/*
 * 初始条件：二叉树T已存在 
 * 操作结果：销毁二叉树T 
 */
Status DestroyBiTree(BiTree *T)
{
	if (T == NULL) {
		// 二叉树不存在
		return ERROR; 
	}
	
	if (T) {
		if (T->lchild) {
			DestroyBiTree(T->lchild);
		}
		if (T->rchild) {
			DestroyBiTree(T->rchild);
		}
		free(T);
		T = NULL;
	}
	
	return OK;
}

/*
 * 按先序次序输入二叉树中结点的值（一个字符），空格字符标识空树 
 * 构造二叉链表表示的二叉树T 
 */
Status CreateBiTree(BiTree *T)
{
	
}


/*
 * 初始条件：二叉树T存在
 * 操作结果：若T为空二叉树，则返回TRUE，否则FALSE 
 */
Status BiTreeEmpty(BiTree T); 

/*
 * 初始条件：二叉树T存在 
 * 操作结果：返回T的深度 
 */
int BiTreeDepth(BiTree T);

/*
 * 初始条件：二叉树T存在
 * 操作结果：返回T的根 
 */
TElemType ROOT(BiTree T);

/*
 * 初始条件：二叉树T存在，p指向T中某个结点
 * 操作结果：返回p所指结点的值 
 */
TElemType Value(BiTree p);

/*
 * 初始条件：二叉树T存在，e是T中某个结点
 * 操作结果：结点e赋值为value 
 */
Status Assign(BiTree p, TElemType value); 

/*
 * 初始条件：二叉树T存在，e是T中某个结点
 * 操作结果：若e是T的非根结点，则返回它的双亲，否则返回“空” 
 */
TElemType Parent(BiTree T, TElemType e); 

/*
 * 初始条件： 二叉树T存在，e是T中某个结点
 * 操作结果：返回e的左孩子。若e无左孩子，则返回“空” 
 */
TElemType LeftChild(BiTree T, TElemType e);

/*
 * 初始条件： 二叉树T存在，e是T中某个结点
 * 操作结果：返回e的右孩子。若e无右孩子，则返回“空” 
 */
TElemType RightChild(BiTree T, TElemType e);

/*
 * 初始条件：二叉树T存在，e是T中某个结点 
 * 操作结果：返回e的左兄弟。若e是T的左孩子或无左兄弟，则返回“空” 
 */
TElemType LeftSibling(BiTree T, TElemType e);

/*
 * 初始条件：二叉树T存在，e是T中某个结点
 * 操作结果：返回e的右兄弟。若e是T的右孩子或无右兄弟，则返回“空” 
 */
TElemType RightSibling(BiTree T, TElemType e); 

/*
 * 初始条件：二叉树T存在，p指向T中某个结点，LR为0或1，非空二叉树c与T不相交且右子树为空 
 * 操作结果：根据LR为0或1，插入c为T中p结点的左或右子树。p结点的原有左或右子树则成为c的右子树 
 */ 
Status InsertChild(BiTree T, TElemType p, Status LR, BiTree c); 

/*
 * 初始条件：二叉树T存在，p指向T中某个结点，LR为0或1
 * 操作结果：根据LR为0或1，删除T中p所指结点的左或右子树 
 */
Status DeleteChild(BiTree T, TElemType p, Status LR); 

/*
 * 采用二叉链表存储结构，Visit是对结点操作的应用函数
 * 先序遍历二叉树T，对每个结点调用函数Visit一次且仅一次  
 */ 
Status PreOrderTraverse(BiTree T, void (Visit)(TElemType e));

/*
 * 采用二叉链表存储结构，Visit是对结点操作的应用函数
 * 中序遍历二叉树T，对每个结点调用函数Visit一次且仅一次  
 */ 
Status InOrderTraverse(BiTree T, void (Visit)(TElemType e));

/*
 * 采用二叉链表存储结构，Visit是对结点操作的应用函数
 * 后序遍历二叉树T，对每个结点调用函数Visit一次且仅一次  
 */ 
Status PostOrderTraverse(BiTree T, void (Visit)(TElemType e));

/*
 * 采用二叉链表存储结构，Visit是对结点操作的应用函数
 * 层序遍历二叉树T，对每个结点调用函数Visit一次且仅一次 
 */ 
Status LevelOrderTraverse(BiTree T, void (Visit)(TElemType e));

/*
 * 打印结点的值 
 */ 
void Visit(TElemType data)
{
	printf("%d ", data);	
}
