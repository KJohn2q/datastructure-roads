#include "MergeSort.h"

/*
 * �鲢����������
 * arr ����������
 * tempArr ��ʱ����
 * left right ���������鷶Χ 
 */ 
void Msort(int arr[], int tempArr[], int left, int right)
{
	int center;
	
	if (left < right) {
		center = (left + right) / 2; // �м�Ԫ�ص�λ�� 
		
		Msort(arr, tempArr, left, center);
		Msort(arr, tempArr, center + 1, right);
		Merge(arr, tempArr, left, center + 1, right);
	}
}

/*
 * �鲢������ú���
 * arr �����������
 * n �����������Ԫ�ظ��� 
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
 * ���Ѿ�����õ������������ϲ�
 * ÿ¼һ��Ԫ�أ�ָ����ǰ�ƶ�һ��
 * arr ����������
 * tempArr ��ʱ����
 * lpos - (rpos-1) ������ĵ�һ���ֵ�������Χ 
 * rpos-rightEnd ������ĵڶ����ֵ�������Χ 
 */ 
void Merge(int arr[], int tempArr[], int lpos, int rpos, int rightEnd)
{
	int leftEnd;
	int tempPos; // ��ʱ����ָ�� 
	int elementNum; // �����������Ԫ�ظ���
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
 * ������� 
 */
void ArrayTraverse(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	
	printf("\n");
}
