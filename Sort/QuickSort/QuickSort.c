#include "QuickSort.h"
#define cutoff ( 3 )  // ��С��Ԫ�ظ��� 

/*
 * ��������ĵ��ú��� 
 */ 
void QuickSort(int arr[], int n)
{
	// ָ������������ķ�Χleft��right 
	Qsort(arr, 0, n - 1);
} 

/*
 * ȡ������ֵ 
 * ��ֵ����ͳ�����嵱�еĸ�������ֵ����С˳������������
 * �γ�һ�����У�λ�ڱ��������м�λ�õı���ֵ�ͳ�Ϊ��λ�� 
 */
int Median3(int arr[], int left, int right)
{
	int center = (left + right) / 2;
	
	// ʹ�ø�������������С�����˳������
	// ����arr[left] <= arr[center] <= arr[right] 
	if (arr[left] > arr[center]) {
		Swap(&arr[left], &arr[center]);
	}	
	if (arr[left] > arr[right]) {
		Swap(&arr[left], &arr[right]);
	}
	if (arr[center] > arr[right]) {
		Swap(&arr[center], &arr[right]);
	}
	
	// ����ŦԪ����right-1,rightλ�õ�Ԫ�ر���ŦԪ�� 
	Swap(&arr[center], &arr[right - 1]);
	return arr[right - 1];
} 

/*
 * �������������� 
 */
void Qsort(int arr[], int left, int right)
{
	int i, j;
	int pivot;  // ��ŦԪ ���ݴˣ����л���
	
	if (left + cutoff <= right) {
		pivot = Median3(arr, left, right);
		i = left; j = right - 1;
		for (; ; ) {
			// ��iָ��ָ���Ԫ��С����ŦԪʱ��ֱ������ 
			while (arr[++i] < pivot) {}
			// ������jָ���Ԫ�ش�����ŦԪʱ��ֱ������ 
			while (arr[--j] > pivot) {}
			
			// i��j�ƶ�ֹͣ����i<j,���������� ֱ��i��j����Ϊֹ��ɨ�����е�Ԫ�� 
			if (i < j) {
				Swap(&arr[i], &arr[j]);
			}
			else {
				break;
			}
		}
	}
	else {
		int center = (left + right) / 2;
	
		// ʹ�ø�������������С�����˳������
		// ����arr[left] <= arr[center] <= arr[right] 
		if (arr[left] > arr[center]) {
			Swap(&arr[left], &arr[center]);
		}	
		if (arr[left] > arr[right]) {
			Swap(&arr[left], &arr[right]);
		}
		if (arr[center] > arr[right]) {
			Swap(&arr[center], &arr[right]);
		}
		return;
	}

	
	Swap(&arr[i], &arr[right - 1]);
	Qsort(arr, left, i);
	Qsort(arr, i + 1, right);
}

/*
 *  ��������
 *  a = 1, b = 2
 * ִ�н��Ϊ: a = 2,b = 1 
 */
void Swap(int *a, int *b) 
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

/*
 * ���������ÿ��Ԫ�� 
 */
void ArrayTraverse(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	
	printf("\n");
} 
