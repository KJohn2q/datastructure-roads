#include <stdio.h>
#include <stdlib.h>
#include "DuLinkList.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	DuLinkList *D;
	Status s;
	
	s = InitList(&D);
	printf("≥ı ºªØ¡¥±Ì%d\n", s);
	
	return 0;
}
