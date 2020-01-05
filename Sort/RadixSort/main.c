#include "RadixSort.h"

int main(int argc, char *argv[]) {
	int arr[] = {64, 8, 216, 512, 27, 729, 0, 1, 343, 125};
	
	RadixSort(arr, 10);
	ArrayTraverse(arr, 10);
	
	return 0;
}
