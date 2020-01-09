#include <stdio.h>
#include "vec_sum.h"
#include "vec_avg.h"

int *ptrvec;
int num = 5;
int soma = 0;
int media = 0;

int main(void){

	int array[] = {1,8,3,3,9};
	ptrvec = array;
	
	soma = vec_sum();
	media = vec_avg();
	
	printf("A soma dos elementos é: %d\n", soma);
	printf("A média é: %d\n", media);
	
	return 0;
}
