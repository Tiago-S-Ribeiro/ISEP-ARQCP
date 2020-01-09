#include <stdio.h>
#include "calc.h"
 
int main(void){
	
	int a=2,b=8, c=3, z;
	
	z = calc(a, &b, c);
	printf("Resultado = %d\n", z);
	
	return 0;
}
