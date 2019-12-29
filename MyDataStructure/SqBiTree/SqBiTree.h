#ifndef SQBITREE_H
#define SQBITREE_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../common.h"

#define MAX_TREE_SIZE 5  // ��������������� 

typedef int TElemType;


typedef TElemType SqBiTree[MAX_TREE_SIZE]; // 0�ŵ�Ԫ�洢���ڵ� 

typedef struct {
	int level, order;
} position;

/*
 * �������������ն����� 
 */
Status InitTree(SqBiTree T);

/*
 * ��ʼ������������T�Ѵ���
 * ������������ٶ�����T 
 */
Status DestroyTree(SqBiTree T);

/*
 * ���ݲ���������������T 
 */ 
Status CreateTree(SqBiTree T);

/*
 * ��ʼ������������T����
 * �����������������T��Ϊ���� 
 */ 
Status ClearTree(SqBiTree T); 

/*
 * ��ʼ������������T����
 * �����������TΪ�ն��������򷵻�TRUE������FALSE 
 */ 
Status BiTreeEmpty(SqBiTree T);

/*
 * ��ʼ������������T���� 
 * �������������T����� 
 */ 
int BiTreeDepth(SqBiTree T);

/*
 * ��ʼ������������T����
 * �������������T�ĸ� 
 */ 
Status Root(SqBiTree T, TElemType *e); 

/*
 * ��ʼ������������T���ڣ�e��T��ĳ����� 
 * �������������e��ֵ 
 */
TElemType Value(SqBiTree T, position p);

/*
 * ��ʼ������������T���ڣ�e��T��ĳ�����
 * ������������e��ֵΪvalue 
 */
Status Assign(SqBiTree T, position p, TElemType value);

/*
 * ��ʼ������������T���ڣ�e��T��ĳ�����
 * �����������e��T�ķǸ���㣬�򷵻�����˫�ף����򷵻ء��� �� 
 */
TElemType Parent(SqBiTree T, TElemType e);

/*
 * ��ʼ������������T���ڣ�e��T��ĳ�����
 * �������������e�����ӡ���e�����ӣ��򷵻ء��ա� 
 */ 
TElemType LeftChild(SqBiTree T, TElemType e);

/*
 * ��ʼ������������T���ڣ�e��T��ĳ����� 
 * �������������e���Һ��ӡ���e���Һ��ӣ��򷵻ء��ա� 
 */
TElemType RightChild(SqBiTree T, TElemType e);

/*
 * ��ʼ������������T���ڣ�e��T��ĳ����� 
 * �������������e�����ֵܡ���e��T�����ӻ������ֵܣ��򷵻ء��ա� 
 */
TElemType LeftSibling(SqBiTree T, TElemType e);

/*
 * ��ʼ������������T���ڣ�e��T��ĳ�����
 * �������������e�����ֵܡ���e��T���Һ��ӻ������ֵܣ��򷵻ء��ա� 
 */
TElemType RightSibling(SqBiTree T, TElemType e);

/*
 * �Ѵ�q��j�ڵ㿪ʼ��������Ϊ��T��i�ڵ㿪ʼ������ 
 */
void Move(SqBiTree q, int j, SqBiTree T, int i);

/*
 * ��ʼ������������T���ڣ�pָ��T��ĳ����㣬LRΪ0��1���ǿն�����c��T���ཻ��������Ϊ�� 
 * �������������LRΪ0��1������cΪT��p���������������p����ԭ��������������Ϊc�������� 
 */ 
Status InsertChild(SqBiTree T, TElemType p, Status LR, SqBiTree c); 

/*
 * ��ʼ������������T���ڣ�pָ��T��ĳ����㣬LRΪ0��1
 * �������������LRΪ0��1��ɾ��T��p��ָ������������� 
 */
Status DeleteChild(SqBiTree T, TElemType p, Status LR); 

/*
 * ��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú���
 * ����������������T����ÿ�������ú���Visitһ���ҽ�һ�Σ�һ��visit()ʧ�ܣ������ʧ�� 
 */
Status PreOrderTraverse(SqBiTree T, void (Visit)(TElemType));

/*
 * ��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú���
 * ����������������T����ÿ�������ú���Visitһ���ҽ�һ�Σ�һ��visit()ʧ�ܣ������ʧ�� 
 */
Status InOrderTraverse(SqBiTree T, void (Visit)(TElemType));

/*
 * ��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú���
 * ����������������T����ÿ�������ú���Visitһ���ҽ�һ�Σ�һ��visit()ʧ�ܣ������ʧ�� 
 */
Status PostOrderTraverse(SqBiTree T, void (Visit)(TElemType));

/*
 * ��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú���
 * ����������������T����ÿ�������ú���Visitһ���ҽ�һ�Σ�һ��visit()ʧ�ܣ������ʧ�� 
 */
Status LevelOrderTraverse(SqBiTree T, void (Visit)(TElemType));

void Visit(TElemType e);
#endif
