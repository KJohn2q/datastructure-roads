#include "BubbleSort.h"

void BubbleSort(int arr[], int n)
{
	// 外层循环表示排序的元素索引 从第一个元素到倒数第二个元素
	// 内层循环表示每个元素比较的次数 第一个元素n-1次，第二个元素n-2次，依次类推
	// 公式 n - 1 - i 
	int i, j;
	int temp;
	
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] < arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void ArrayTraverse(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	
	printf("\n");
}
