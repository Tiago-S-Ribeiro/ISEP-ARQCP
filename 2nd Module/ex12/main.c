#include <stdio.h>
#include "isMultiple.h"

int A = 4;
int B = 0;

int main(){
	printf("A a NÃO ser múltiplo de B\n");
	int resultado = isMultiple();
	printf("Resultado = %d\n", resultado);
	
	A=28;
	B=14;
	
	printf("A a ser múltiplo de B\n");
	resultado = isMultiple();
	printf("Resultado = %d\n", resultado);
	
	return 0;
}
