#include <stdio.h>
#include "sum_and_subtract.h"

char A = 1;
short B = 0;
int C = 0;
int D = 0;

int main(){
	
	long long resultado = sum_and_subtract();
	printf("Resultado = %lld\n", resultado);
	return 0;
}
