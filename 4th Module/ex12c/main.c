#include <stdio.h>
#include "activate_bit.h"
#include "activate_2bits.h"

int main(void){

	int num = 46, pos = 5;
	int *ptr = &num;
	printf("Número antes (decimal): %d\n", num);
	
	activate_2bits(ptr, pos);
	
	printf("Número depois (decimal): %d\n", num);

	return 0;
}
