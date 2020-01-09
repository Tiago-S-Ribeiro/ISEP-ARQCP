#include <stdio.h>
#include "check_num.h"

int num = 0;
char resultado;

int main(){
	
	printf("Número = %d\n", num);
	
	resultado = check_num();
	
	printf("Resultado = %d\n", resultado);
	return 0;
}
