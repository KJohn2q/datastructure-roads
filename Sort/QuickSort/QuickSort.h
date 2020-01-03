#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <stdio.h>
#include <stdlib.h>

/*
 * ��������ĵ��ú��� 
 */ 
void QuickSort(int arr[], int n);

/*
 * ȡ������ֵ 
 * ��ֵ����ͳ�����嵱�еĸ�������ֵ����С˳������������
 * �γ�һ�����У�λ�ڱ��������м�λ�õı���ֵ�ͳ�Ϊ��λ�� 
 */
int Median3(int arr[], int left, int right);

/*
 * �������������� 
 */
void Qsort(int arr[], int left, int right);

/*
 *  ��������
 *  a = 1, b = 2
 * ִ�н��Ϊ: a = 2,b = 1 
 */
void Swap(int *a, int *b);

/*
 * ���������ÿ��Ԫ�� 
 */
void ArrayTraverse(int arr[], int n);


#endif
