#include <stdio.h>
#include "cube.h"

int main(void){
	
	int x = 9;
	
	int result = cube(x);
	
	printf("O cubo de %d é igual a %d\n", x, result);

	return 0;
}
