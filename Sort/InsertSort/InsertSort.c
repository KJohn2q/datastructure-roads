#include "InsertSort.h"

/*
 * 插入排序 
 * arr 待排序数组
 * n 待排序数组的元素个数 
 */
void InsertSort(int arr[], int n)
{
	int i, j;
	int temp;
	
	// 从第二个元素开始，使得当前元素之前的所有元素比当前元素小
	// 发现比自己大的元素，就向后移动，直到找到当前元素的合适位置进行插入 
	for (i = 1; i < n; i++) {
		temp = arr[i];
		
		for (j = i; j > 0, arr[j - 1] > temp; j--) {
			arr[j] = arr[j - 1];
		}
		
		arr[j] = temp;
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
