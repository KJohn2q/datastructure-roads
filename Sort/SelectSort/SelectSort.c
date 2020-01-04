#include "SelectSort.h"

/*
 * 选择排序
 * 每一次从未排序的元素中选取最小的元素与当前索引元素交换
 * 最后尾部元素自然是最大的那一个了 
 * arr 待排序数组
 * n  待排序数组元素个数 
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
 * 数组遍历 
 * arr 数组
 * n  元素个数 
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
 *  两数交换
 *  a = 1, b = 2
 * 执行结果为: a = 2,b = 1 
 */
void Swap(int *a, int *b) 
{
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}
