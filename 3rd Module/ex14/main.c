#include <stdio.h>
#include "duplicates.h"

short int *ptrvec;
short int x = 16;
int num = 12;

int main(void){
	
	short int vec[] = {16, 20, 0, 14, 8, 8, 9, 3, 12, 3, 16, 3};
	
	ptrvec = vec;
	
	int has_duplicates = exists();
	
	if(has_duplicates == 1){
		printf("O número %d tem duplicados no vetor.\n", x);
	}
	else{
		printf("O número %d não tem duplicados no vetor.\n", x);
	}
	
	int no_duplicates = vec_diff();
	
	printf("O número de elementos no vetor que não tem duplicados é igual a %d.\n", no_duplicates);
	
	return 0;
}
