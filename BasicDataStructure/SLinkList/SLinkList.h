#ifndef SLINKLIST_H
#define SLINKLIST_H

#define MAXSIZE 100

#include "../common.h"

typedef int ElemType;

typedef struct{
	ElemType data;
	int cur; 
}SLinkList[MAXSIZE];

/*
 *  初始化备用空间 
 *  将一维数组space中各分量链成一个备用链表,space[0].cur为头指针 
 */
void InitSpace(SLinkList space);

/*
 *  申请空间 
 * 若备用空间链表非空，则返回分配的节点下标，否则返回0 
 */ 
int Malloc(SLinkList space);

/*
 *  回收空间 
 *  将下标为k的空闲节点回收到备用链表 
 */ 
void Free(SLinkList space, int k);

/*
 *  构造一个空的静态链表 
 */
Status InitList(SLinkList space, int *S);

/*
 *  销毁静态链表 
 */
Status DestroyList(SLinkList space, int *S);

/*
 *  清空静态链表 
 */
Status ClearList(SLinkList space, int S);

/*
 *  静态链表是否为空 
 */ 
Status ListEmpty(SLinkList space, int S);

/*
 *  静态链表的长度 
 */ 
int ListLength(SLinkList space, int S);

/*
 *  取值 
 */ 
Status GetElem(SLinkList space, int S, int i, ElemType *e);

/*
 *  返回第一个与给定值相等的元素 
 */
int LocateElem(SLinkList space, int S, ElemType e, Status(Compare)(ElemType, ElemType));

/*
 *  返回给定值的前驱 
 */ 
Status PriorElem(SLinkList space, int S, ElemType cur_e, ElemType *pre_e);

/*
 *  返回给定值的后继 
 */
Status NextElem(SLinkList space, int S, ElemType cur_e, ElemType *next_e);


/*
 *  在i位置插入e 
 */ 
Status ListInsert(SLinkList space, int S, int i, ElemType e);

/*
 *  在i位置删除元素 
 */
Status ListDelete(SLinkList space, int S, int i, ElemType *e);

/*
 *  遍历打印静态链表中的元素 
 */ 
void ListTraverse(SLinkList space, int S, void (Visit)(ElemType));

/*
 *  比较函数 
 */ 
Status Compare(ElemType, ElemType);

/*
 *  打印给定元素的值 
 */ 
void Visit(ElemType);

/*
 *  以图形化形式输出当前结构，仅限内部测试使用 
 */
void PrintGraph(SLinkList space, int S);


#endif
