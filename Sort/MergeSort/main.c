#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int arr[] = {11, 5, 3, 18, 9, 7, 36, 21, 12, 6};
	
	MergeSort(arr, 10);
	
	ArrayTraverse(arr, 10);
	
	return 0;
}
