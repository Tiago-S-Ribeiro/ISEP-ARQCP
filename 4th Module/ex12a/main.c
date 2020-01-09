#include <stdio.h>
#include "activate_bit.h"

int main(void){
	
	int num = 46, pos = 12;
	int *ptr = &num;
	int resultado;
	
	resultado = activate_bit(ptr, pos);
	
	if(resultado == 1){
		printf("O bit na posição %d, foi alterado de 0 para 1.\n", pos);
	}else{
		printf("O bit na posição %d, não foi alterado.\n", pos);
	}
	return 0;
}
