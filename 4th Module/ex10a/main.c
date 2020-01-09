#include <stdio.h>
#include "count_bits_zero.h"
 
int main(void){
	
	int x = 46;
	int resultado;
	
	resultado = count_bits_zero(x);
	
	printf("Nº de bits inativos = %d\n", resultado);
	
	return 0;
}
