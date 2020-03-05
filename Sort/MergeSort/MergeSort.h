#ifndef MERGESORT_H
#define MERGESORT_H

#include <stdio.h>
#include <stdlib.h>

/*
 * 归并排序主例程
 * arr 待排序数组
 * tempArr 临时数组
 * left right 待排序数组范围 
 */ 
void Msort(int arr[], int tempArr[], int left, int right);

/*
 * 归并排序调用函数
 * arr 待排序的数组
 * n 待排序数组的元素个数 
 */
void MergeSort(int arr[], int n);

/*
 * 对已经排序好的数组进行逐个合并
 * 每录一个元素，指针向前移动一个
 * arr 待排序数组
 * tempArr 重组的数组
 * lpos-rpos 重组数组的第一部分
 * rpos-rightEnd 重组数组的第二部分 
 */ 
void Merge(int arr[], int tempArr[], int lpos, int rpos, int rightEnd);

/*
 * 数组遍历 
 */
void ArrayTraverse(int arr[], int n);

#endif
