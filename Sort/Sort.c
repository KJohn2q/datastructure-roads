#include "Sort.h" 

/*
 * 冒泡排序 
 * arr 待排序的数组
 * n  数组的长度 
 */
void BubbleSort(int arr[], int n)
{
	// 外层循环表示排序的元素索引 从第一个元素到倒数第二个元素
	// 内层循环表示每个元素比较的次数 第一个元素n-1次，第二个元素n-2次，依次类推
	// 公式 n - 1 - i 
	int i, j;
	int temp;
	
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j <= n - i - 1; j++) {
			if (arr[j] < arr[j+1]) {
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

/*
 * 快速排序 
 * arr 待排序的数组
 * n  数组的长度
 */
void QuickSort(int arr[], int n);

/*
 * 插入排序 
 * arr 待排序的数组
 * n  数组的长度
 */
void InsertSort(int arr[], int n);

/*
 * 选择排序 
 * arr 待排序的数组
 * n  数组的长度
 */
void SelectSort(int arr[], int n);

/*
 * 归并排序 
 * arr 待排序的数组
 * n  数组的长度
 */
void MergeSort(int arr[], int n);
