#ifndef SELECTSORT_H
#define SELECTSORT_H

#include <stdio.h>
#include <stdlib.h>

/*
 * ѡ������
 * arr ����������
 * n  ����������Ԫ�ظ��� 
 */
void SelectSort(int arr[], int n);

/*
 * ������� 
 * arr ����
 * n  Ԫ�ظ��� 
 */
void ArrayTraverse(int arr[], int n);

/*
 *  ��������
 *  a = 1, b = 2
 * ִ�н��Ϊ: a = 2,b = 1 
 */
void Swap(int *a, int *b);

#endif
