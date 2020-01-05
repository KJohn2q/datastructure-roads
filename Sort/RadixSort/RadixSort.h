#ifndef RADIXSORT_H
#define RADIXSORT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * �������� 
 */
void RadixSort(int arr[], int n);

/*
 * ��ȡԪ�ص�λ�� 
 */
int getLoopTimes(int num); 

/*
 * ��ȡ����� 
 */
int findMaxNum(int arr[], int n); 

/*
 * ����
 */ 
void ArrayTraverse(int arr[], int n);

/*
 * ��¼Ͱ��Ԫ�ظ����������ʼ�� 
 */
void orderArrInit(int order[]);

/*
 * Ͱ�����ʼ�� 
 */ 
void bucketsArrInit(int buckets[][20]); 

/*
 * ��Ͱ��Ԫ�����ε���ԭ���� 
 */
void pullBuckets(int buckets[][20], int order[], int arr[]); 

#endif
