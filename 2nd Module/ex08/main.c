#include <stdio.h>
#include "crossSumBytes.h"

int main(void){
	
	short result = crossSumBytes();

	printf("Resultado = 0x%hx\n", result);
	
	return 0;
}
