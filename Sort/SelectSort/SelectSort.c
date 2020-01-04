#include "SelectSort.h"

/*
 * ѡ������
 * ÿһ�δ�δ�����Ԫ����ѡȡ��С��Ԫ���뵱ǰ����Ԫ�ؽ���
 * ���β��Ԫ����Ȼ��������һ���� 
 * arr ����������
 * n  ����������Ԫ�ظ��� 
 */
void SelectSort(int arr[], int n)
{
	int i, j;
	int min;
	
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}			
		}	
		Swap(&arr[i], &arr[min]);
	}
}

/*
 * ������� 
 * arr ����
 * n  Ԫ�ظ��� 
 */
void ArrayTraverse(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	
	printf("\n");
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
