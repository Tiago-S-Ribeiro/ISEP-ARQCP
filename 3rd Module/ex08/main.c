#include <stdio.h>
#include "even.h"

int even = 2;

int num = 7;

int *ptrvec;

int main(void){

	int vec[] = {0, 4, 3, 7, 13, 12, 9};
	
	ptrvec = vec;
	
	int is_even = test_even();
	
	if(is_even == 1){
		printf("O número é par.\n");
	}
	else{
		printf("O número é impar.\n");
	}
	
	int sum = vec_sum_even();
	
	printf("A soma dos números pares do vetor é igual a %d\n", sum);

	return 0;
}
