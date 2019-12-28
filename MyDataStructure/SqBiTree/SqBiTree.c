#include "SqBiTree.h"

TElemType NIL = 0; // ��������0Ϊ�� 

/*
 * �������������ն����� 
 */
Status InitTree(SqBiTree T)
{
	int i;
	
	for(i = 0; i < MAX_TREE_SIZE; i++) {
		T[i] = NIL;  // �����н����Ϊ�� 
	}
	
	return OK;
}

/*
 * ��ʼ������������T�Ѵ���
 * ������������ٶ�����T 
 */
Status DestroyTree(SqBiTree T)
{
	// ����SqBiTree�Ƕ������ͣ��޷����١� 
}

/*
 * ���ݲ���������������T 
 */ 
Status CreateTree(SqBiTree T)
{
	// ��Ϊ����ȫ���������ʲ�������ս��
	int ncount; // ��ʾ�㼶
	TElemType node = NIL; // ����������ʱ���� 
	int i;
	int j = 0;
	
	scanf("%d", &node);
	
	ncount = 1; // �ӵ�һ�㿪ʼ 
	
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
 * ��ʼ������������T����
 * �����������������T��Ϊ���� 
 */ 
Status ClearTree(SqBiTree T)
{
	// �ڶ�������˳��洢�ṹ�У���յ�ͬ�ڳ�ʼ��	
	int i;
	
	for(i = 0; i < MAX_TREE_SIZE; i++) {
		T[i] = NIL;  // �����н����Ϊ�� 
	}
	
	return OK;
}
