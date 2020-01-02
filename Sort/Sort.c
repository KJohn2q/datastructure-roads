#include "Sort.h" 

/*
 * ð������ 
 * arr �����������
 * n  ����ĳ��� 
 */
void BubbleSort(int arr[], int n)
{
	// ���ѭ����ʾ�����Ԫ������ �ӵ�һ��Ԫ�ص������ڶ���Ԫ��
	// �ڲ�ѭ����ʾÿ��Ԫ�رȽϵĴ��� ��һ��Ԫ��n-1�Σ��ڶ���Ԫ��n-2�Σ���������
	// ��ʽ n - 1 - i 
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
 * �������� 
 * arr �����������
 * n  ����ĳ���
 */
void QuickSort(int arr[], int n);

/*
 * �������� 
 * arr �����������
 * n  ����ĳ���
 */
void InsertSort(int arr[], int n);

/*
 * ѡ������ 
 * arr �����������
 * n  ����ĳ���
 */
void SelectSort(int arr[], int n);

/*
 * �鲢���� 
 * arr �����������
 * n  ����ĳ���
 */
void MergeSort(int arr[], int n);
