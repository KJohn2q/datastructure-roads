#include "SLinkList.h"

/*
 *  ��ʼ�����ÿռ� 
 *  ��һά����space�и���������һ����������,space[0].curΪͷָ�� 
 */
void InitSpace(SLinkList space)
{
	int i = 0;
	for (; i < MAXSIZE - 1; i++) {
		space[i].cur = i + 1;
	}	
	space[i - 1].cur = 0;  // �߽����� 
} 

/*
 *  ����ռ� 
 * �����ÿռ�����ǿգ��򷵻ط���Ľڵ��±꣬���򷵻�0 
 */ 
int Malloc(SLinkList space)
{
	int i = 0;
	i = space[0].cur;
	
	if (i != 0) {
		space[0].cur = space[i].cur;
	}
	
	return i;	
} 

/*
 *  ���տռ� 
 *  ���±�Ϊk�Ŀ��нڵ���յ��������� 
 */ 
void Free(SLinkList space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

/*
 *  ��ʼ��
 *  �ȳ�ʼ�����ÿռ䣬����ӱ��ÿռ�������ͷ���Ŀռ䣬������ɾ�̬����ĳ�ʼ����
 *  ��ʼ���ɹ���ʹ��S�洢ͷ����������ҷ���OK�����򷵻�ERROR 
 */
Status InitList(SLinkList space, int *S)
{
	int index;
	
	InitSpace(space);
	
	index = Malloc(space);
	
	if (index == 0) {
		return ERROR;
	}
	
	space[index].cur = 0;
	*S = index;
	
	return OK;
}

/*
 *  ���پ�̬���� 
 */
Status DestroyList(SLinkList space, int *S) 
{
	int cur;
	
	// ȷ����̬������� 
	if (S == NULL || *S == 0) {
		return ERROR;
	}
	
	while (*S != 0) {
		cur = space[*S].cur;
		Free(space, *S);
		*S = cur;
	}  
	
	return OK;
}

/*
 *  ��վ�̬���� 
 *  �ͷž�̬�����з�ͷ��㴦�Ŀռ� 
 */
Status ClearList(SLinkList space, int S)
{
	int P;
	int cur;
	
	if (S == 0) {
		return ERROR;
	}
	
	P = space[S].cur;  // �ӵ�һ����㿪ʼ 
	
	while (P != 0) {
		cur = space[P].cur;
		Free(space, P);
		P = cur;
	}
	
	space[S].cur = 0;
	
	return OK;
}

/*
 *  ��̬�����Ƿ�Ϊ�� 
 */ 
Status ListEmpty(SLinkList space, int S)
{
	if (S != 0 && space[S].cur == 0) {
		return TRUE;
	}
	else {
		return FALSE;
	}
} 

/*
 *  ��̬����ĳ��� 
 *  �ӵ�һ����㿪ʼ���������������Ϊ�գ����ۼӣ���ָ����һ����� 
 */
int ListLength(SLinkList space, int S)
{
	int len = 0;
	
	if (S == 0 || space[S].cur == 0) {
		return ERROR;
	}
	
	S = space[S].cur;
	
	while (S != 0) {
		++len;
		S = space[S].cur;
	}
	
	return len;
} 

/*
 *  ȡ�þ�̬�����е�i��Ԫ�ص�ֵ��������ڣ��򷵻�OK�����򷵻�ERROR 
 */ 
Status GetElem(SLinkList space, int S, int i, ElemType *e)
{
	int j = 0;
	
	// ��̬����Ϊ�� 
	if (S == 0 || space[S].cur == 0) {
		return ERROR;
	}
	
	S = space[S].cur;
	
	while (S != 0 && j < i - 1) {
		++j;
		S = space[S].cur;
	} 
	
	if (S == 0 || j > i - 1) {
		return ERROR;
	}
	
	*e = space[S].data;
	
	return OK;
} 

/*
 *  ���ص�һ�������ֵ��ȵ�Ԫ�� 
 */
int LocateElem(SLinkList space, int S, ElemType e, Status(Compare)(ElemType, ElemType))
{
	int i = 0;
	
	if (S == 0 || space[S].cur == 0) {
		return ERROR;
	}
	
	S = space[S].cur;
	
	while (S != 0 && !Compare(space[S].data, e)) {
		++i;
		S = space[S].cur;
	}
	
	if (S == 0) {
		return 0;
	} else {
		return i;
	}
}

/*
 *  ���ظ���ֵ��ǰ�� 
 */ 
Status PriorElem(SLinkList space, int S, ElemType cur_e, ElemType *pre_e)
{
	int pre, next;
	
	if (S == 0 || space[S].cur == 0) {
		return ERROR;
	}
	
	// ָ���һ��Ԫ�� 
	pre = space[S].cur;
	
	// ��һ��Ԫ��û��ǰ�� 
	if (space[pre].data == cur_e) {
		return ERROR;
	}
	
	// ָ��ڶ���Ԫ��	
	next = space[pre].cur;
	
	while (next != 0 && space[next].data != cur_e) {
		pre = next;
		next = space[pre].cur;
	}
	
	if (next == 0) {
		return ERROR;
	} 
	*pre_e = space[pre].data;
	
	return OK;
	
}

/*
 *  ���ظ���ֵ�ĺ�� 
 */
Status NextElem(SLinkList space, int S, ElemType cur_e, ElemType *next_e)
{
	int cur;
	int next;
	
	if (S == 0 || space[S].cur == 0) {
		return ERROR;
	}
	
	cur = space[S].cur;
	
	while (space[cur].cur != 0 && space[cur].data != cur_e) {
		cur = space[cur].cur;
	}
	
	// �ӵ�һ��Ԫ�ؿ�ʼ������cur_e��λ�ã��ұ�֤�ý��ĺ�̴��� 
	if (space[cur].cur == 0) {
		return ERROR;
	}
	next = space[cur].cur;
	
	*next_e = space[next].data;
	
	return OK;
}

/*
 *  ��iλ�ò���e 
 */ 
Status ListInsert(SLinkList space, int S, int i, ElemType e)
{
	int j = 0;
	int index = 0;
	int p = 0;

	if (S == 0) {
		return ERROR;
	}
	
	p = S;
	
	while (p != 0 && j < i - 1) {
		p = space[p].cur;
		++j;
	}	
	
	if (p == 0 || j > i - 1) {
		return ERROR;
	}
	
	index = Malloc(space);
	
	space[index].data = e;
	space[index].cur = space[p].cur;
	space[p].cur = index;
	
	return OK;
} 

/*
 *  ��iλ��ɾ��Ԫ�� 
 */
Status ListDelete(SLinkList space, int S, int i, ElemType *e)
{
	int j = 0;
	int p = 0,q = 0;
	
	if (S == 0) {
		return ERROR;
	}
	
	// Pָ���һ��Ԫ�� 
	p = S;
	
	while (space[p].cur != 0 && j < i - 1) {
		p = space[p].cur;
		j++;
	}
	
	// iλ��Ԫ�ز����� 
	if (space[p].cur == 0 || j > i - 1) {
		return ERROR;
	}
	
	q = space[p].cur;
	space[p].cur = space[q].cur;
	*e = space[q].data;
	Free(space, q);
	
	return OK;
}

/*
 *  ������ӡ��̬�����е�Ԫ�� 
 */ 
void ListTraverse(SLinkList space, int S, void (Visit)(ElemType))
{
	int p;
	
	if (S == 0 || space[S].cur == 0) {
		return;
	}
	
	p = space[S].cur;
	
	while (p != 0) {
		Visit(space[p].data);
		p = space[p].cur;
	}
	
	printf("\n");
}

/*
 *  �ȽϺ��� 
 */ 
Status Compare(ElemType data, ElemType e)
{
	return data > e ? TRUE : FALSE;
}

/*
 *  ��ӡ����Ԫ�ص�ֵ 
 */ 
void Visit(ElemType data)
{
	printf("%d ", data);
} 

/*
 *  ��ͼ�λ���ʽ�����ǰ�ṹ�������ڲ�����ʹ��
 */
void PrintGraph(SLinkList space, int S) {
    int i = 0;
    
    printf("==== ���ÿռ� ====\n");
    while(i < 20) {
        printf("%2d    | %2d | %2d |\n", i, space[i].data, space[i].cur);
        i = space[i].cur;
    }
    
    printf("==== ��̬���� ====\n");
    i = S;
    while(i>0 && i < 20) {
        printf("%2d    | %2d | %2d |\n", i, space[i].data, space[i].cur);
        i = space[i].cur;
    }
}



