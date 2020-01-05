#include "BucketSort.h"

/*
 * 桶式排序
 * 给定数组中元素的值均小于MAX 范围为0~MAX-1 
 * n为给定数组中元素的个数 
 */
void BucketSort(int arr[], int n)
{
	int i;
	int Count[MAX];
	
	// Count数组初始化 
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
