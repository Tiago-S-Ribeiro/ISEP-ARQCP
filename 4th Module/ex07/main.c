#include <stdio.h>
#include "count_even.h"

int main(void){
	
	int n = 9;
	short vec[] = {12, 32, 23, 43, 1, 13, 12, 10, 19};
	
	int result = count_even(vec, n);
	
	printf("O número de números pares contidos no vetor é igual a %d\n", result);
	
	return 0;
}
