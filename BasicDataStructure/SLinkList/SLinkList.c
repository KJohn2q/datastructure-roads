#include "SLinkList.h"

/*
 *  初始化备用空间 
 *  将一维数组space中各分量链成一个备用链表,space[0].cur为头指针 
 */
void InitSpace(SLinkList space)
{
	int i = 0;
	for (; i < MAXSIZE - 1; i++) {
		space[i].cur = i + 1;
	}	
	space[i - 1].cur = 0;  // 边界问题 
} 

/*
 *  申请空间 
 * 若备用空间链表非空，则返回分配的节点下标，否则返回0 
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
 *  回收空间 
 *  将下标为k的空闲节点回收到备用链表 
 */ 
void Free(SLinkList space, int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

/*
 *  初始化
 *  先初始化备用空间，而后从备用空间中申请头结点的空间，进而完成静态链表的初始化。
 *  初始化成功则使用S存储头结点索引，且返回OK，否则返回ERROR 
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
 *  销毁静态链表 
 */
Status DestroyList(SLinkList space, int *S) 
{
	int cur;
	
	// 确保静态链表存在 
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
 *  清空静态链表 
 *  释放静态链表中非头结点处的空间 
 */
Status ClearList(SLinkList space, int S)
{
	int P;
	int cur;
	
	if (S == 0) {
		return ERROR;
	}
	
	P = space[S].cur;  // 从第一个结点开始 
	
	while (P != 0) {
		cur = space[P].cur;
		Free(space, P);
		P = cur;
	}
	
	space[S].cur = 0;
	
	return OK;
}

/*
 *  静态链表是否为空 
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
 *  静态链表的长度 
 *  从第一个结点开始，如果结点的索引不为空，则累加，且指向下一个结点 
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
 *  取得静态链表中第i个元素的值，如果存在，则返回OK，否则返回ERROR 
 */ 
Status GetElem(SLinkList space, int S, int i, ElemType *e)
{
	int j = 0;
	
	// 静态链表不为空 
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
 *  返回第一个与给定值相等的元素 
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
 *  返回给定值的前驱 
 */ 
Status PriorElem(SLinkList space, int S, ElemType cur_e, ElemType *pre_e)
{
	int pre, next;
	
	if (S == 0 || space[S].cur == 0) {
		return ERROR;
	}
	
	// 指向第一个元素 
	pre = space[S].cur;
	
	// 第一个元素没有前驱 
	if (space[pre].data == cur_e) {
		return ERROR;
	}
	
	// 指向第二个元素	
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
 *  返回给定值的后继 
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
	
	// 从第一个元素开始，查找cur_e的位置，且保证该结点的后继存在 
	if (space[cur].cur == 0) {
		return ERROR;
	}
	next = space[cur].cur;
	
	*next_e = space[next].data;
	
	return OK;
}

/*
 *  在i位置插入e 
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
 *  在i位置删除元素 
 */
Status ListDelete(SLinkList space, int S, int i, ElemType *e)
{
	int j = 0;
	int p = 0,q = 0;
	
	if (S == 0) {
		return ERROR;
	}
	
	// P指向第一个元素 
	p = S;
	
	while (space[p].cur != 0 && j < i - 1) {
		p = space[p].cur;
		j++;
	}
	
	// i位置元素不存在 
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
 *  遍历打印静态链表中的元素 
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
 *  比较函数 
 */ 
Status Compare(ElemType data, ElemType e)
{
	return data > e ? TRUE : FALSE;
}

/*
 *  打印给定元素的值 
 */ 
void Visit(ElemType data)
{
	printf("%d ", data);
} 

/*
 *  以图形化形式输出当前结构，仅限内部测试使用
 */
void PrintGraph(SLinkList space, int S) {
    int i = 0;
    
    printf("==== 备用空间 ====\n");
    while(i < 20) {
        printf("%2d    | %2d | %2d |\n", i, space[i].data, space[i].cur);
        i = space[i].cur;
    }
    
    printf("==== 静态链表 ====\n");
    i = S;
    while(i>0 && i < 20) {
        printf("%2d    | %2d | %2d |\n", i, space[i].data, space[i].cur);
        i = space[i].cur;
    }
}



