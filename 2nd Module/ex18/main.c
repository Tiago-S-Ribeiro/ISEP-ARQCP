#include <stdio.h>
#include "somatorio.h"

int n = 5, i = 1, resultado;

int main(){
	
	printf("N = %d\n", n);
	
	resultado = somatorio();
	
	printf("Resultado: %d\n", resultado);
	return 0;
}
