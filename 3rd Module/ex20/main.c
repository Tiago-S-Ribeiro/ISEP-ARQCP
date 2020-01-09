#include <stdio.h>
#include "count_seq.h"

int *ptrvec;
int num = 12;

int main(void){
	
	int vec[] = {1, 2, 4, 5, 6, 7, 9, 0, 11, 12, 13, 4};
	
	ptrvec = vec;
	
	int num_sets = count_seq();
	
	printf("O número de conjuntos de três números consecutivos que o vetor tem é igual a %d\n", num_sets);
	
	return 0;
}
