#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 基数排序 
 */
void RadixSort(int arr[], int n);

/*
 * 获取元素的位数 
 */
int getLoopTimes(int num); 

/*
 * 获取最大数 
 */
int findMaxNum(int arr[], int n); 

/*
 * 遍历
 */ 
void ArrayTraverse(int arr[], int n);

/*
 * 记录桶中元素个数的数组初始化 
 */
void orderArrInit(int order[]);

/*
 * 桶数组初始化 
 */ 
void bucketsArrInit(int buckets[][20]); 

/*
 * 把桶中元素依次倒回原数组 
 */
void pullBuckets(int buckets[][20], int order[], int arr[]); 

#endif
