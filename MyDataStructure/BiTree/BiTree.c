#include "BiTree.h"

TElemType NIL = ' ';

/*
 * ����ն�����T 
 */
Status InitBiTree(BiTree *T)
{
	*T = NULL; 
	return OK;
}

/*
 * ��ʼ������������T�Ѵ��� 
 * ������������ٶ�����T 
 */
Status DestroyBiTree(BiTree *T)
{
	if (*T == NULL) {
		// ������������
		return ERROR; 
	}
	
	if (*T) {
		if ((*T)->lchild) {
			DestroyBiTree(&(*T)->lchild);
		}
		if ((*T)->rchild) {
			DestroyBiTree(&(*T)->rchild);
		}
		free((*T));
		*T = NULL;
	}
	
	return OK;
}

/*
 * �������������������н���ֵ��һ���ַ������ո��ַ���ʶ���� 
 * ������������ʾ�Ķ�����T 
 */
Status CreateBiTree(BiTree *T)
{
	TElemType e;
	
	// �������ֵ 
	scanf("%d", &e);

	if (e == NIL) {
		*T = NULL;
	}
	else {
		*T = (BiTree) malloc(sizeof(BiTNode));
		if (!*T) {
			// �޿����ڴ�
			exit(OVERFLOW); 
		}
		(*T)->data = e; // ���ɸ����
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild); 
	}
	
	return OK;
}


/*
 * ��ʼ������������T����
 * �����������TΪ�ն��������򷵻�TRUE������FALSE 
 */
Status BiTreeEmpty(BiTree T)
{
	return T == NULL ? TRUE:FALSE;	
}

/*
 * ��ʼ������������T���� 
 * �������������T����� 
 */
int BiTreeDepth(BiTree T)
{
	int i, j;
	if (!T) {
		return ERROR;
	}
	i = T->lchild != NULL ? BiTreeDepth(T->lchild) : 0;
	j = T->rchild != NULL ? BiTreeDepth(T->rchild) : 0;
	
	return i > j ? i + 1 : j + 1;
}

/*
 * ��ʼ������������T����
 * �������������T�ĸ� 
 */
TElemType ROOT(BiTree T)
{
	if (!T) {
		return ERROR;
	}
	return T->data;
}

/*
 * ��ʼ������������T���ڣ�pָ��T��ĳ�����
 * �������������p��ָ����ֵ 
 */
TElemType Value(BiTree p)
{
	if (!p) {
		return ERROR;
	}
	return p->data;
}

/*
 * ��ʼ������������T���ڣ�p��T��ĳ�����
 * ������������p��ֵΪvalue 
 */
Status Assign(BiTree p, TElemType value)
{
	if (!p) {
		return ERROR;
	}
	p->data = value;
	return OK;
}

/*
 * ��ʼ������������T���ڣ�e��T��ĳ�����
 * �����������e��T�ķǸ���㣬�򷵻�����˫�ף����򷵻ء��ա� 
 */
TElemType Parent(BiTree T, TElemType e)
{
	if (!T) {
		return ERROR;
	}
	
	if (T->lchild) {
		if (T->lchild->data == e) {
			return T->data;
		} 
		return Parent(T->lchild, e);
	}
	else if (T->rchild) {
		if (T->rchild->data == e) {
			return T->data;
		}
		return Parent(T->rchild, e);
	}
	
	return NIL;
}

/*
 * ��ʼ������ ������T���ڣ�e��T��ĳ�����
 * �������������e�����ӡ���e�����ӣ��򷵻ء��ա� 
 */
TElemType LeftChild(BiTree T, TElemType e)
{
	if (!T) {
		return ERROR;
	} 
	
	if (T->data == e) {
		if (T->lchild) {
			return T->lchild->data;
		}
		else {
			return NIL;
		}
	} 
	else {
		if (T->lchild) {
			return LeftChild(T->lchild, e);
		}
		else if (T->rchild){
			return LeftChild(T->rchild, e);
		}
		else {
			return NIL;
		}
	}

}

/*
 * ��ʼ������ ������T���ڣ�e��T��ĳ�����
 * �������������e���Һ��ӡ���e���Һ��ӣ��򷵻ء��ա� 
 */
TElemType RightChild(BiTree T, TElemType e)
{
	if (!T) {
		return ERROR;
	} 
	
	if (T->data == e) {
		if (T->rchild) {
			return T->rchild->data;
		}
		else {
			return NIL;
		}
	} 
	else {
		if (T->lchild) {
			return RightChild(T->lchild, e);
		}
		else if (T->rchild){
			return RightChild(T->rchild, e);
		}
		else {
			return NIL;
		}
	}
}

/*
 * ��ʼ������������T���ڣ�e��T��ĳ����� 
 * �������������e�����ֵܡ���e��T�����ӻ������ֵܣ��򷵻ء��ա� 
 */
 /*
TElemType LeftSibling(BiTree T, TElemType e)
{
	BiTree parent;
	
	if (!T) {
		return NIL; 
	}
	
	if (T->data == e) {
		parent = Parent(T, e);
		if (parent) {
			if (parent->lchild) {
				if (parent->lchild->data != e) {
					return parent->lchild->data;
				}
			} 
		} 
	}
	else {
		if (T->lchild)
			return LeftSibling(T->lchild, e);
		else if(T->rchild){
			return LeftSibling(T->rchild, e);
		}
	}
	return NIL;
}
*/


/*
 * ��ʼ������������T���ڣ�e��T��ĳ�����
 * �������������e�����ֵܡ���e��T���Һ��ӻ������ֵܣ��򷵻ء��ա� 
 */
 /*
TElemType RightSibling(BiTree T, TElemType e)
{
	BiTree parent;
	
	if (!T) {
		return NIL; 
	}
	
	if (T->data == e) {
		parent = Parent(T, e);
		if (parent) {
			if (parent->rchild) {
				if (parent->rchild->data != e) {
					return parent->rchild->data;
				}
			} 
		} 
	}
	else {
		if (T->lchild)
			return RightSibling(T->lchild, e);
		else if(T->rchild){
			return RightSibling(T->rchild, e);
		}
	}
	return NIL;
}
*/

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
Status PreOrderTraverse(BiTree T, void (Visit)(TElemType e))
{
	if (!T) {
		return NIL;
	}
	
	Visit(T->data);
	PreOrderTraverse(T->lchild, Visit);
	PreOrderTraverse(T->rchild, Visit);
}

/*
 * ���ö�������洢�ṹ��Visit�ǶԽ�������Ӧ�ú���
 * �������������T����ÿ�������ú���Visitһ���ҽ�һ��  
 */ 
Status InOrderTraverse(BiTree T, void (Visit)(TElemType e))
{
	if (!T) {
		return NIL;
	}
	
	Visit(T->data);
	InOrderTraverse(T->lchild, Visit);
	InOrderTraverse(T->rchild, Visit);
}

/*
 * ���ö�������洢�ṹ��Visit�ǶԽ�������Ӧ�ú���
 * �������������T����ÿ�������ú���Visitһ���ҽ�һ��  
 */ 
Status PostOrderTraverse(BiTree T, void (Visit)(TElemType e))
{
	if (!T) {
		return NIL;
	}
	
	Visit(T->data);
	PostOrderTraverse(T->lchild, Visit);
	PostOrderTraverse(T->rchild, Visit);
}

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
