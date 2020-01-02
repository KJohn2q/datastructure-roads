#ifndef SORT_H
#define SORT_H

#include <stdio.h>

/*
 * 冒泡排序 
 * arr 待排序的数组
 * n  数组的长度
 */
void BubbleSort(int arr[], int n);

/*
 * 快速排序 
 * arr 待排序的数组
 * n  数组的长度
 */
void QuickSort(int arr[], int n);

/*
 * 插入排序 
 * arr 待排序的数组
 * n  数组的长度
 */
void InsertSort(int arr[], int n);

/*
 * 选择排序 
 * arr 待排序的数组
 * n  数组的长度
 */
void SelectSort(int arr[], int n);

/*
 * 归并排序 
 * arr 待排序的数组
 * n  数组的长度
 */
void MergeSort(int arr[], int n);

#endif
