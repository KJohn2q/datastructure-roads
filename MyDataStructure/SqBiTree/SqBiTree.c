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

/*
 * ��ʼ������������T����
 * �����������TΪ�ն��������򷵻�TRUE������FALSE 
 */ 
Status BiTreeEmpty(SqBiTree T)
{
	// �����Ϊ�� ����Ϊ�� 
	return T[0] == NIL ? TRUE : FALSE;
}

/*
 * ��ʼ������������T���� 
 * �������������T����� 
 */ 
int BiTreeDepth(SqBiTree T)
{
	int i = 0;
	int last = 0;  // ���һ����Ϊ�յ�Ԫ�� 
	int level = 1;  // ���� 
	int index = 0;
	
	// �������п� 
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
 * ��ʼ������������T����
 * �������������T�ĸ� 
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
 * ��ʼ������������T���ڣ�p��T��ĳ������λ�� 
 * �������������e��ֵ 
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
 * ��ʼ������������T���ڣ�e��T��ĳ������λ�� 
 * ������������e��ֵΪvalue 
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
