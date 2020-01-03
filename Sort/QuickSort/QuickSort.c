#include "QuickSort.h"
#define cutoff ( 3 )  // 最小的元素个数 

/*
 * 快速排序的调用函数 
 */ 
void QuickSort(int arr[], int n)
{
	// 指定被排序数组的范围left和right 
	Qsort(arr, 0, n - 1);
} 

/*
 * 取三数中值 
 * 中值：将统计总体当中的各个变量值按大小顺序排列起来，
 * 形成一个数列，位于变量数列中间位置的变量值就称为中位数 
 */
int Median3(int arr[], int left, int right)
{
	int center = (left + right) / 2;
	
	// 使得给定三个数按从小到大的顺序排列
	// 即：arr[left] <= arr[center] <= arr[right] 
	if (arr[left] > arr[center]) {
		Swap(&arr[left], &arr[center]);
	}	
	if (arr[left] > arr[right]) {
		Swap(&arr[left], &arr[right]);
	}
	if (arr[center] > arr[right]) {
		Swap(&arr[center], &arr[right]);
	}
	
	// 将枢纽元放在right-1,right位置的元素比枢纽元大 
	Swap(&arr[center], &arr[right - 1]);
	return arr[right - 1];
} 

/*
 * 快速排序主函数 
 */
void Qsort(int arr[], int left, int right)
{
	int i, j;
	int pivot;  // 枢纽元 根据此，进行划分
	
	if (left + cutoff <= right) {
		pivot = Median3(arr, left, right);
		i = left; j = right - 1;
		for (; ; ) {
			// 当i指针指向的元素小于枢纽元时，直接跳过 
			while (arr[++i] < pivot) {}
			// 当索引j指向的元素大于枢纽元时，直接跳过 
			while (arr[--j] > pivot) {}
			
			// i和j移动停止，若i<j,则两数交换 直到i和j交错为止，扫描所有的元素 
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
	
		// 使得给定三个数按从小到大的顺序排列
		// 即：arr[left] <= arr[center] <= arr[right] 
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

/*
 * 遍历数组的每个元素 
 */
void ArrayTraverse(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	
	printf("\n");
} 
