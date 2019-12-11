#ifndef CLINKLIST_H
#define CLINKLIST_H

#include "../common.h"

typedef int ElemType;

typedef struct CLNode {
	ElemType data;
	struct CLNode* next;
} CLNode, *CLinkList;

/*
 *  初始化 
 */
Status InitList(CLinkList *C);

/*
 *  创建链表 
 */
Status CreateList(CLinkList C, int n);

/*
 *  销毁 
 */ 
Status DestroyList(CLinkList *C);

/*
 * 清空 
 */  
Status ClearList(CLinkList C);

/*
 * 判断是否为空 
 */
Status ListEmpty(CLinkList C);

/*
 *  计算链表的长度 
 */
int ListLength(CLinkList C);

/*
 *  取值 
 */
Status GetElem(CLinkList C, int i, ElemType* e); 

/*
 *  查找 
 */
int LocateElem(CLinkList C, ElemType e, Status(Compare)(ElemType, ElemType));

/*
 *  前驱 
 */
Status PriorElem(CLinkList C, ElemType cur_e, ElemType* pre_e);

/*
 *  后缀 
 */ 
Status NextElem(CLinkList C, ElemType cur_e, ElemType* next_e);

/*
 *  插入 
 */
Status ListInsert(CLinkList C, int i, ElemType e);

/*
 *  删除 
 */ 
Status ListDelete(CLinkList C, int i, ElemType* e);

/*
 *  遍历 
 */ 
void ListTraverse(CLinkList C, void(Visit)(ElemType)); 

/*
 * 比较函数 
 */ 
Status Compare(ElemType, ElemType);

/*
 * 打印数据 
 */
void Visit(ElemType);

#endif
