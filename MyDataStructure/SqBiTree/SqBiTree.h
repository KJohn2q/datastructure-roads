#ifndef SQBITREE_H
#define SQBITREE_H

#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

#define MAX_TREE_SIZE 100  // ��������������� 

typedef int TElemType;

TElemType Nil = 0; // ��������0Ϊ�� 

typedef TElemType SqBiTree[MAX_TREE_SIZE]; // 0�ŵ�Ԫ�洢���ڵ� 

typedef struct {
	int level, order;
} position;

/*
 *  ��ʼ��������
 *  ÿ���ڵ������Ϊ�� 
 */
Status InitTree(SqBiTree *T);

/*
 *  ���� 
 */
Status DestroyTree(SqBiTree *T);

/*
 *  ������ȫ������ 
 */ 
Status CreateTree(SqBiTree *T);

/*
 *  ��ն����� 
 */ 
Status ClearTree(SqBiTree *T); 

/*
 * �������п� 
 */ 
Status BiTreeEmpty(SqBiTree T);

/*
 * ����������� 
 */ 
int BiTreeDepth(SqBiTree T);

/*
 * �������ĸ� 
 */ 
Status Root(SqBiTree T, TElemType *e); 

/*
 *  ���ش���λ��e�Ľڵ��ֵ 
 */
TElemType Value(SqBiTree T, position p);

/*
 *  ��λ��pλ�ô��Ľڵ㸳��ֵvalue 
 */
Status Assign(SqBiTree T, position p, TElemType value);

/*
 *  ���ؽڵ�e��˫�� 
 */
TElemType Parent(SqBiTree T, TElemType e);

/*
 *  ���ؽڵ�e������ 
 */ 
TElemType LeftChild(SqBiTree T, TElemType e);

/*
 *  ���ؽڵ�e���Һ��� 
 */
TElemType RightChild(SqBiTree T, TElemType e);

/*
 *  ����e�����ֵ� 
 */
TElemType LeftSibling(SqBiTree T, TElemType e);

/*
 *  ����e�����ֵ� 
 */
TElemType RightSibling(SqBiTree T, TElemType e);

#endif
