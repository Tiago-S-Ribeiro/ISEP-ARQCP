#include <stdio.h>
#include "vec_greater20.h"

int *ptrvec;
int num = 5;

int main(void){
	
	long long int array[] = {22,21,45,7,8};
	ptrvec = array;
	
	int resultado = vec_greater20();
	
	printf("\nQuantidade de elementos maiores que 20: %d\n", resultado);
	
	return 0;
}
