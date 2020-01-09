#include <stdio.h>
#include "greatest.h"

int main(void){
	
	int a = 9;
	int b = 11;
	int c = 2;
	
	int result = greatest(a, b, c);
	
	printf("O maior dos três números %d, %d e %d é o %d\n", a, b, c, result);
	
	return 0;
}
