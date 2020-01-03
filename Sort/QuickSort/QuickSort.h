#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdio.h>
#include <stdlib.h>

/*
 * 快速排序的调用函数 
 */ 
void QuickSort(int arr[], int n);

/*
 * 取三数中值 
 * 中值：将统计总体当中的各个变量值按大小顺序排列起来，
 * 形成一个数列，位于变量数列中间位置的变量值就称为中位数 
 */
int Median3(int arr[], int left, int right);

/*
 * 快速排序主函数 
 */
void Qsort(int arr[], int left, int right);

/*
 *  两数交换
 *  a = 1, b = 2
 * 执行结果为: a = 2,b = 1 
 */
void Swap(int *a, int *b);

/*
 * 遍历数组的每个元素 
 */
void ArrayTraverse(int arr[], int n);


#endif
