#include <stdio.h>
#include "crossSumBytes.h"

short s1 = 0xFAA;
short s2 = 0x111;

int main(void){
	
	short result = crossSumBytes();

	printf("Resultado = 0x%hx\n", result);
	
	return 0;
}
