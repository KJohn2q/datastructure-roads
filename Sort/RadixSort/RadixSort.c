#include "RadixSort.h"

/*
 * �������� 
 */
void RadixSort(int arr[], int n)
{
	// Ԫ�ص�ÿһλ��ΧΪ0-9��nΪ����������ĸ��� 
	// ���n����������������������С 
	int buckets[10][20]; 
	int loop;
	int i, j;
	int divisor;
	int s;
	int maxNum = 0;
	int order[10];  // ͳ��ÿ��Ͱ�е�Ԫ�ظ��� 
	
	maxNum = findMaxNum(arr, n);
	// ��ȡѭ������ 
	loop = getLoopTimes(maxNum);
	
	orderArrInit(order);
	bucketsArrInit(buckets);
	
	for (i = 1; i <= loop; i++) {
		divisor = pow(10, i - 1);
		for (j = 0; j < n; j++) {
			s = (arr[j] / divisor) % 10;
			buckets[s][order[s]] = arr[j];
			order[s]++; // �����ۼ� 		
		}
		
		pullBuckets(buckets, order, arr);		
		bucketsArrInit(buckets);
		orderArrInit(order);
	}
	
} 

/*
 * ��Ͱ��Ԫ�����ε���ԭ���� 
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
 * Ͱ�����ʼ�� 
 */ 
void bucketsArrInit(int buckets[][20]) 
{
	int i, j;
	// order�����ʼ�� 
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 20; j++) {
			buckets[i][j] = 0;
		}
	}
}

/*
 * ��¼Ͱ��Ԫ�ظ��������ʼ�� 
 */
void orderArrInit(int order[])
{
	int i;
	// order�����ʼ�� 
	for (i = 0; i < 10; i++) {
		order[i] = 0;
	}
}


/*
 * ��ȡԪ�ص�λ�� 
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
 * ��ȡ����� 
 */
int findMaxNum(int arr[], int n)
{
	int i;
	int max; // �����������
	
	max = 0;
	
	for (i = 1; i < n; i++) {
		if (arr[i] > arr[max]) {
			max = i;
		}
	}	
	
	return arr[max];
}  

/*
 * ��������Ԫ�� 
 */
void ArrayTraverse(int arr[], int n) {
	int i;
	
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	
	printf("\n");
}
