#include "MergeSort.h"

/*
 * 归并排序主例程
 * arr 待排序数组
 * tempArr 临时数组
 * left right 待排序数组范围 
 */ 
void Msort(int arr[], int tempArr[], int left, int right)
{
	int center;
	
	if (left < right) {
		center = (left + right) / 2; // 中间元素的位置 
		
		Msort(arr, tempArr, left, center);
		Msort(arr, tempArr, center + 1, right);
		Merge(arr, tempArr, left, center + 1, right);
	}
}

/*
 * 归并排序调用函数
 * arr 待排序的数组
 * n 待排序数组的元素个数 
 */
void MergeSort(int arr[], int n)
{
	int *tempArr;
	
	tempArr = malloc(n * sizeof(int));
	
	if (tempArr != NULL) {
		Msort(arr, tempArr, 0, n - 1);
		free(tempArr);
	}
	else {
		printf("No space for tempArr!!!");
	}
}

/*
 * 对已经排序好的数组进行逐个合并
 * 每录一个元素，指针向前移动一个
 * arr 待排序数组
 * tempArr 临时数组
 * lpos - (rpos-1) 待排序的第一部分的索引范围 
 * rpos-rightEnd 待排序的第二部分的索引范围 
 */ 
void Merge(int arr[], int tempArr[], int lpos, int rpos, int rightEnd)
{
	int leftEnd;
	int tempPos; // 临时索引指针 
	int elementNum; // 待排序数组的元素个数
	int i;
	
	elementNum = rightEnd - lpos + 1; 
	
	leftEnd = rpos - 1;
	
	tempPos = lpos;
	
	while (lpos <= leftEnd && rpos <= rightEnd) {
		if (arr[lpos] <= arr[rpos]) {
			tempArr[tempPos++] = arr[lpos++];
		}
		else {
			tempArr[tempPos++] = arr[rpos++];
		}
	}
	
	while (lpos <= leftEnd) {
		tempArr[tempPos++] = arr[lpos++];
	}
	
	while (rpos <= rightEnd) {
		tempArr[tempPos++] = arr[rpos++];
	}
	
	for (i = 0; i < elementNum; i++, rightEnd--) {
		arr[rightEnd] = tempArr[rightEnd];
	}
}

/*
 * 数组遍历 
 */
void ArrayTraverse(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	
	printf("\n");
}
