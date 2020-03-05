#include "RadixSort.h"

/*
 * 基数排序 
 */
void RadixSort(int arr[], int n)
{
	// 元素的每一位范围为0-9，n为待排序数组的个数 
	// 如果n过大，视情况而定设置数组大小 
	int buckets[10][20]; 
	int loop;
	int i, j;
	int divisor;
	int s;
	int maxNum = 0;
	int order[10];  // 统计每个桶中的元素个数 
	
	maxNum = findMaxNum(arr, n);
	// 获取循环次数 
	loop = getLoopTimes(maxNum);
	
	orderArrInit(order);
	bucketsArrInit(buckets);
	
	for (i = 1; i <= loop; i++) {
		divisor = pow(10, i - 1);
		for (j = 0; j < n; j++) {
			s = (arr[j] / divisor) % 10;
			buckets[s][order[s]] = arr[j];
			order[s]++; // 个数累加 		
		}
		
		pullBuckets(buckets, order, arr);		
		bucketsArrInit(buckets);
		orderArrInit(order);
	}
	
} 

/*
 * 把桶中元素依次倒回原数组 
 */
void pullBuckets(int buckets[][20], int order[], int arr[])
{
	int i, j, k;
	
	k = 0;
	
	for (i = 0; i < 10; i++) {
		for (j = 0; j < order[i]; j++) {
			arr[k++] = buckets[i][j];
		}
	}
}

/*
 * 桶数组初始化 
 */ 
void bucketsArrInit(int buckets[][20]) 
{
	int i, j;
	// order数组初始化 
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 20; j++) {
			buckets[i][j] = 0;
		}
	}
}

/*
 * 记录桶中元素个数数组初始化 
 */
void orderArrInit(int order[])
{
	int i;
	// order数组初始化 
	for (i = 0; i < 10; i++) {
		order[i] = 0;
	}
}


/*
 * 获取元素的位数 
 */
int getLoopTimes(int num)
{
	int s = 0;
	int loop = 1;
		
	s = num / 10;
	
	while (s != 0) {
		++loop;
		s = s / 10;
	}
	
	return loop;
}

/*
 * 获取最大数 
 */
int findMaxNum(int arr[], int n)
{
	int i;
	int max; // 最大数的索引
	
	max = 0;
	
	for (i = 1; i < n; i++) {
		if (arr[i] > arr[max]) {
			max = i;
		}
	}	
	
	return arr[max];
}  

/*
 * 遍历数组元素 
 */
void ArrayTraverse(int arr[], int n) {
	int i;
	
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	
	printf("\n");
}
