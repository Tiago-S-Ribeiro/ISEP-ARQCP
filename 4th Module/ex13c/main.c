#include <stdio.h>
#include "activate_bits.h"
#include "activate_invert_bits.h"

int main(void){

	int left = 1;
	int right = 19;
	int a = 650;
	
	int result = activate_invert_bits(a, left, right);
	
	printf("O resultado é %d\n", result);

	return 0;
}
