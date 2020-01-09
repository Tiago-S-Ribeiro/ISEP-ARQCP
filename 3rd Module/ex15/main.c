#include <stdio.h>
#include "sum_first_byte.h"

int *ptrvec;
int num = 5;
int somaBytes = 0;

int main(void){

	int array[] = {1,8,3,3,9};
	ptrvec = array;
	
	somaBytes = sum_first_byte();
	
	printf("A soma dos 1ºs bytes dos elementos é: %d\n", somaBytes);
	
	return 0;
}
