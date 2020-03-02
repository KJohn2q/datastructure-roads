#include "SplayTreeDT.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	// Ê÷µÄ¸ù 
	SplayTree T = NULL;
		
	Insert(&T, 13);
	
		
	Insert(&T, 11);		
	Insert(&T, 14);		
	Insert(&T, 12);	
	Insert(&T, 17);	
	Insert(&T, 16);	
	Insert(&T, 20);	
	Insert(&T, 21);
	Insert(&T, 18);
	Insert(&T, 15); 
	
	PrintTree(T);
	
	printf("\n");	
	Delete(&T, 18);
	
	PrintTree(T);
	
	return 0;
}
