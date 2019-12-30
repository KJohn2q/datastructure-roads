#include "BiTree.h"

/*
 * ����ն�����T 
 */
Status InitBiTree(BiTree *T);
{
	T = NULL; 
	return OK;
}

/*
 * ��ʼ������������T�Ѵ��� 
 * ������������ٶ�����T 
 */
Status DestroyBiTree(BiTree *T)
{
	if (T == NULL) {
		// ������������
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
 * �������������������н���ֵ��һ���ַ������ո��ַ���ʶ���� 
 * ������������ʾ�Ķ�����T 
 */
Status CreateBiTree(BiTree *T)
{
	
}


/*
 * ��ʼ������������T����
 * �����������TΪ�ն��������򷵻�TRUE������FALSE 
 */
Status BiTreeEmpty(BiTree T); 

/*
 * ��ʼ������������T���� 
 * �������������T����� 
 */
int BiTreeDepth(BiTree T);

/*
 * ��ʼ������������T����
 * �������������T�ĸ� 
 */
TElemType ROOT(BiTree T);

/*
 * ��ʼ������������T���ڣ�pָ��T��ĳ�����
 * �������������p��ָ����ֵ 
 */
TElemType Value(BiTree p);

/*
 * ��ʼ������������T���ڣ�e��T��ĳ�����
 * ������������e��ֵΪvalue 
 */
Status Assign(BiTree p, TElemType value); 

/*
 * ��ʼ������������T���ڣ�e��T��ĳ�����
 * �����������e��T�ķǸ���㣬�򷵻�����˫�ף����򷵻ء��ա� 
 */
TElemType Parent(BiTree T, TElemType e); 

/*
 * ��ʼ������ ������T���ڣ�e��T��ĳ�����
 * �������������e�����ӡ���e�����ӣ��򷵻ء��ա� 
 */
TElemType LeftChild(BiTree T, TElemType e);

/*
 * ��ʼ������ ������T���ڣ�e��T��ĳ�����
 * �������������e���Һ��ӡ���e���Һ��ӣ��򷵻ء��ա� 
 */
TElemType RightChild(BiTree T, TElemType e);

/*
 * ��ʼ������������T���ڣ�e��T��ĳ����� 
 * �������������e�����ֵܡ���e��T�����ӻ������ֵܣ��򷵻ء��ա� 
 */
TElemType LeftSibling(BiTree T, TElemType e);

/*
 * ��ʼ������������T���ڣ�e��T��ĳ�����
 * �������������e�����ֵܡ���e��T���Һ��ӻ������ֵܣ��򷵻ء��ա� 
 */
TElemType RightSibling(BiTree T, TElemType e); 

/*
 * ��ʼ������������T���ڣ�pָ��T��ĳ����㣬LRΪ0��1���ǿն�����c��T���ཻ��������Ϊ�� 
 * �������������LRΪ0��1������cΪT��p���������������p����ԭ��������������Ϊc�������� 
 */ 
Status InsertChild(BiTree T, TElemType p, Status LR, BiTree c); 

/*
 * ��ʼ������������T���ڣ�pָ��T��ĳ����㣬LRΪ0��1
 * �������������LRΪ0��1��ɾ��T��p��ָ������������� 
 */
Status DeleteChild(BiTree T, TElemType p, Status LR); 

/*
 * ���ö�������洢�ṹ��Visit�ǶԽ�������Ӧ�ú���
 * �������������T����ÿ�������ú���Visitһ���ҽ�һ��  
 */ 
Status PreOrderTraverse(BiTree T, void (Visit)(TElemType e));

/*
 * ���ö�������洢�ṹ��Visit�ǶԽ�������Ӧ�ú���
 * �������������T����ÿ�������ú���Visitһ���ҽ�һ��  
 */ 
Status InOrderTraverse(BiTree T, void (Visit)(TElemType e));

/*
 * ���ö�������洢�ṹ��Visit�ǶԽ�������Ӧ�ú���
 * �������������T����ÿ�������ú���Visitһ���ҽ�һ��  
 */ 
Status PostOrderTraverse(BiTree T, void (Visit)(TElemType e));

/*
 * ���ö�������洢�ṹ��Visit�ǶԽ�������Ӧ�ú���
 * �������������T����ÿ�������ú���Visitһ���ҽ�һ�� 
 */ 
Status LevelOrderTraverse(BiTree T, void (Visit)(TElemType e));

/*
 * ��ӡ����ֵ 
 */ 
void Visit(TElemType data)
{
	printf("%d ", data);	
}
