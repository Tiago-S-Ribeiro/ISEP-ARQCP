#include <stdio.h>
#include "sum_smaller.h"
 
int main(void){
	
	int num1 = 4;
	int num2 = 6;
	int resultado;
	int *smaller = &resultado;
	int soma;
	
	soma = sum_smaller(num1, num2, &resultado);
	
	printf("The sum of %d and %d = %d", num1, num2, soma);
	printf("\nThe smaller of both of them is: %d\n", *smaller);
	
	return 0;
}
