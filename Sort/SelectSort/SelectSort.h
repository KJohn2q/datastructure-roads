#ifndef SELECTSORT_H
#define SELECTSORT_H

#include <stdio.h>
#include <stdlib.h>

/*
 * 选择排序
 * arr 待排序数组
 * n  待排序数组元素个数 
 */
void SelectSort(int arr[], int n);

/*
 * 数组遍历 
 * arr 数组
 * n  元素个数 
 */
void ArrayTraverse(int arr[], int n);

/*
 *  两数交换
 *  a = 1, b = 2
 * 执行结果为: a = 2,b = 1 
 */
void Swap(int *a, int *b);

#endif
