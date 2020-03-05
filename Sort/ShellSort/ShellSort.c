#include "ShellSort.h"

void ShellSort(int arr[], int n)
{
	int i, j, increment;
	int temp;
	
	for (increment = n/2; increment > 0; increment /= 2) {
		
		for (i = increment; i < n; i++) {
			temp = arr[i];
			
			for (j = i; j >= increment; j -= increment) {
				if (temp < arr[j - increment]) {
					arr[j] = arr[j - increment];
				}
				else {
					break;
				}
			}
			
			arr[j] = temp; 
		}
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
