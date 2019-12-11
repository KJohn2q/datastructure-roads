#include <stdio.h>
#include <stdlib.h>
#include "CLinkList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	CLinkList C = NULL;
	Status s = 0;
	
	InitList(&C);
	
	ListTraverse(C, Visit);
	
	return 0;
}
