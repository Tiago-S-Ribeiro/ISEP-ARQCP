#include <stdio.h>
#include "sort_without_reps.h"

int main(){
	int array[10]={3,5,7,4,9,2,4,9,12,7}, arraySize, i, j, newSize;
	arraySize = (sizeof(array)/sizeof(array[0]));
	int array2[arraySize];
	
	printf("\nArray antes da ordenação e remoção de elementos repetidos:\nArray = [");
	for(i=0; i < arraySize; i++){
		if(i == arraySize-1){
			printf("%d]\n",*(array+i));
		}else{
			printf("%d, ", *(array+i));
		}
	}
	
	newSize = sort_without_reps(array, arraySize, array2);
	
	printf("\nForam colocados %d elementos no segundo array.\n", newSize);
	printf("\nArray ordenado e sem elementos repetidos:\nArray = [");
	
	for(j=0; j < newSize; j++){
		if(j == newSize-1){
			printf("%d]\n",*(array2+j));
		}else{
			printf("%d, ", *(array2+j));
		}
	}
	return 0;
}
