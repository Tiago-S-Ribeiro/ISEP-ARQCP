#include <stdio.h>
#include "keep_positives.h"

int *ptrvec;
int num = 5;

int main(void){
	int i;
	int array[] = {-4,21,45,-1,8};
	ptrvec = array;
	
	printf("\nArray antes da função:\n");
	for(i = 0; i < num; i++){
		printf("Array [%d] = %d\n",i,*(ptrvec+i));
	}
	
	keep_positives();
	
	printf("\nArray depois da função:\n");
	for(i = 0; i < num; i++){
		printf("Array [%d] = %d\n",i,*(ptrvec+i));
	}
	
	return 0;
}
