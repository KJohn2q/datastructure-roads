#include "Sort.h"

int main(int argc, char *argv[]) {
	int arr[] = {2, 18, 14, 27, 20, 9, 16, 6, 10, 7};
	int i;
	
	BubbleSort(arr, 10);
	
	for(i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	
	printf("ÅÅÐòÍê³É\n");
	
	return 0;
}
