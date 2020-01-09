#include <stdio.h>
#include "join_bits.h"

int main(void) {

	int a = 4, b = -37, pos=4;
	int resultado = join_bits(a, b, pos);
	
	printf("Resultado = %d\n", resultado);

	return 0;
}
