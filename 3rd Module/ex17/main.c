#include <stdio.h>
#include "array_sort.h"

int *ptrvec;
int num = 5;

int main(void){
	int i;
	int array[] = {1,2,3,4,5};
	ptrvec = array;
	
	printf("\nArray inicial:\n");
	for(i = 0; i < num; i++){
		printf("Array [%d] = %d\n",i,*(ptrvec+i));
	}
	
	array_sort();
	
	printf("\nArray ordenado em ordem decrescente:\n");
	for(i = 0; i < num; i++){
		printf("Array [%d] = %d\n",i,*(ptrvec+i));
	}
	
	return 0;
}
