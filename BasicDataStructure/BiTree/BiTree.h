#ifndef BITREE_H
#define BITREE_H

#include "../common.h"

typedef int TElemType; 

typedef struct BiTNode {
	TElemType data;
	struct BiTNode  *lchild, *rchild;
}BiTNode, * BiTree;


Status InitBiTree(BiTree *T); 


Status DestroyBiTree(BiTree *T); 


Status CreateBiTree(BiTree *T);


Status ClearBiTree(BiTree T);

Status BiTreeEmpty(BiTree T); 


int BiTreeDepth(BiTree T);


TElemType ROOT(BiTree T);


TElemType Value(BiTree p);


Status Assign(BiTree p, TElemType value); 


TElemType Parent(BiTree T, TElemType e); 

TElemType LeftChild(BiTree T, TElemType e);


TElemType RightChild(BiTree T, TElemType e);


TElemType LeftSibling(BiTree T, TElemType e);


TElemType RightSibling(BiTree T, TElemType e); 

Status InsertChild(BiTree T, TElemType p, Status LR, BiTree c); 

Status DeleteChild(BiTree T, TElemType p, Status LR); 

Status PreOrderTraverse(BiTree T, void (Visit)(TElemType e));

Status InOrderTraverse(BiTree T, void (Visit)(TElemType e));

Status PostOrderTraverse(BiTree T, void (Visit)(TElemType e));

Status LevelOrderTraverse(BiTree T, void (Visit)(TElemType e));

void Visit(TElemType data);

#endif
