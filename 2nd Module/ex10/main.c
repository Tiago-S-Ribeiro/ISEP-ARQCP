#include <stdio.h>
#include "sum2ints.h"

int op1 = 403;
int op2 = 100;

int main(){
	
	long long resultado = sum2ints();
	printf("Resultado: %llu\n", resultado);
	return 0;
}
