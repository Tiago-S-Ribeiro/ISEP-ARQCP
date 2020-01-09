#include <stdio.h>
#include "swap.h"
/*
 * São definidos 2 arrays de inteiros aleatórios. É mostrado o output de ambos, antes
 * de ser chamada a função pedida em enunciado. Depois da chamada da função, que vai
 * trocar os valores de um array para o outro, é dado um output dos novos arrays.
 */
int main(){
	int array1[10] = {6,31,35,46,15,6,76,87,55,10}, arraySize,i;
	int array2[10] = {9,12,13,10,99,1,19,46,51,20};
	arraySize = (sizeof(array1)/sizeof(array1[0]));
	
	printf("\nAntes da troca:\nArray1 = [");
	for(i=0; i < arraySize; i++){
		if(i == arraySize-1){
			printf("%d]\n",*(array1+i));
		}else{
			printf("%d, ", *(array1+i));
		}
	}
	printf("Array2 = [");
	for(i=0; i < arraySize; i++){
		if(i == arraySize-1){
			printf("%d]\n",*(array2+i));
		}else{
			printf("%d, ", *(array2+i));
		}
	}
	
	swap(array1,array2,10);
	
	printf("\nDepois da troca:\nArray1 = [");
	for(i=0; i < arraySize; i++){
		if(i == arraySize-1){
			printf("%d]\n",*(array1+i));
		}else{
			printf("%d, ", *(array1+i));
		}
	}
	printf("Array2 = [");
	for(i=0; i < arraySize; i++){
		if(i == arraySize-1){
			printf("%d]\n",*(array2+i));
		}else{
			printf("%d, ", *(array2+i));
		}
	}
	return 0;
}
