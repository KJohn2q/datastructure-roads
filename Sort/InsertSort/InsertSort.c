#include "InsertSort.h"

/*
 * �������� 
 * arr ����������
 * n �����������Ԫ�ظ��� 
 */
void InsertSort(int arr[], int n)
{
	int i, j;
	int temp;
	
	// �ӵڶ���Ԫ�ؿ�ʼ��ʹ�õ�ǰԪ��֮ǰ������Ԫ�رȵ�ǰԪ��С
	// ���ֱ��Լ����Ԫ�أ�������ƶ���ֱ���ҵ���ǰԪ�صĺ���λ�ý��в��� 
	for (i = 1; i < n; i++) {
		temp = arr[i];
		
		for (j = i; j > 0, arr[j - 1] > temp; j--) {
			arr[j] = arr[j - 1];
		}
		
		arr[j] = temp;
	}
}

/*
 * ������� 
 * arr ����
 * n  Ԫ�ظ��� 
 */
void ArrayTraverse(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	
	printf("\n");
} 
