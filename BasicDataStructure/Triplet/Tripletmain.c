#include "Triplet.h"

int main()
{
	Triplet T;
	ElemType e;
	Status s;
	
	InitTriplet(&T, 5, 9, 4);
	Get(T, 2, &e);
	Put(&T, 3, 10);
	Get(T, 3, &e);
//	s = IsAscending(T); 
//	s = IsDescending(T);
	Max(T, &e);
	Min(T, &e);	
	s = DestroyTriplet(&T);
	printf("%d\n", s);
	return 0;
}
 
