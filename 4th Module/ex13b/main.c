#include <stdio.h>
#include "activate_bits.h"

int main(void){

	int left = 10;
	int right = 18;
	int a = 24;
	
	int result = activate_bits(a, left, right);
	
	printf("O resultado é %d\n", result);

	return 0;
}
