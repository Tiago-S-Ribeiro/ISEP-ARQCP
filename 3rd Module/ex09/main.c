#include <stdio.h>
#include "vec_search.h"

short *ptrvec;
int num = 5;
short x = 3;

int main(void){
	
	short array[] = {2,3,0,7,8};
	ptrvec = array;
	
	short *xPointer = vec_search();
	
	printf("\nEndereço de %d: %p.\n", x, xPointer);
	
	return 0;
}
