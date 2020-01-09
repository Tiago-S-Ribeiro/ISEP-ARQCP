#include <stdio.h>
#include "join_bits.h"
#include "mixed_sum.h"

int main(void) {

	int a = 4, b = 6, pos = 2;
	int resultado = mixed_sum(a,b,pos);
	
	printf("Resultado = %d\n", resultado);

	return 0;
}
