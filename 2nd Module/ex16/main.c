#include <stdio.h>
#include "steps.h"
int num = 6, resultado;

int main(){
	
	printf("Número original: %d\n", num);
	resultado = steps();
	printf("Número final: (((%d * 3) + 6) / 3) + 12 - %d - 1 = %d\n",num,num,resultado);
	return 0;
}
