#ifndef SQBITREE_H
#define SQBITREE_H

#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

#define MAX_TREE_SIZE 100  // ��������������� 

typedef int TElemType;

TElemType Nil = 0; // ��������0Ϊ�� 

typedef TElemType SqBiTree[MAX_TREE_SIZE]; // 0�ŵ�Ԫ�洢���ڵ� 

/*
 *  ��ʼ��������
 *  ÿ���ڵ������Ϊ�� 
 */
Status InitTree(SqBiTree *T);

Status DestroyTree(SqBiTree *T);

Status CreateTree(SqBiTree *T);

Status ClearTree(SqBiTree *T); 

Status BiTreeEmpty(SqBiTree T);

int BiTreeDepth(SqBiTree T);

TElemType Root(SqBiTree T); 

#endif
