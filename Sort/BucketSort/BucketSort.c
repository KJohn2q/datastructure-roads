#include "BucketSort.h"

/*
 * Ͱʽ����
 * ����������Ԫ�ص�ֵ��С��MAX ��ΧΪ0~MAX-1 
 * nΪ����������Ԫ�صĸ��� 
 */
void BucketSort(int arr[], int n)
{
	int i;
	int Count[MAX];
	
	// Count�����ʼ�� 
	for (i = 0; i < MAX; i++) {
		Count[i] = 0;
	}
	
	for (i = 0; i < n; i++) {
		Count[arr[i]]++;
	} 
	
	for (i = 0; i < MAX; i++) {
		if (Count[i] > 0) {
			printf("%d ", i);
		}
	}
	
	printf("\n");
} 
