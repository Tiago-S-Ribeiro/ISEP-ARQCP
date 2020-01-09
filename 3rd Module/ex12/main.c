#include <stdio.h>
#include "vec_zero.h"

short int *ptrvec;
int num = 8;

int main(void){
	
	short int vec[] = {201, 2, 34, 99, 100, 104, 98, 300};
	
	ptrvec = vec;
	
	int num_changed_elements = vec_zero();
	
	printf("O número de elementos mudados no vetor é igual a %d\n", num_changed_elements);
	
	return 0;
}
