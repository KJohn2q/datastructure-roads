#ifndef MERGESORT_H
#define MERGESORT_H

#include <stdio.h>
#include <stdlib.h>

/*
 * �鲢����������
 * arr ����������
 * tempArr ��ʱ����
 * left right ���������鷶Χ 
 */ 
void Msort(int arr[], int tempArr[], int left, int right);

/*
 * �鲢������ú���
 * arr �����������
 * n �����������Ԫ�ظ��� 
 */
void MergeSort(int arr[], int n);

/*
 * ���Ѿ�����õ������������ϲ�
 * ÿ¼һ��Ԫ�أ�ָ����ǰ�ƶ�һ��
 * arr ����������
 * tempArr ���������
 * lpos-rpos ��������ĵ�һ����
 * rpos-rightEnd ��������ĵڶ����� 
 */ 
void Merge(int arr[], int tempArr[], int lpos, int rpos, int rightEnd);

/*
 * ������� 
 */
void ArrayTraverse(int arr[], int n);

#endif
