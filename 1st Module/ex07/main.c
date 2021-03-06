#include <stdio.h>
#include "array_sort1.h"
/*
 * É definido um array de 10 posições com números aleatórios. O progama aceita qualquer
 * vetor com quaisquer números para realizar a função pedida no enunciado. É dado um output
 * do vetor antes de este ser ordenado. É chamada a função que ordena o vetor em ordem crescente.
 * Finalmente, é dado um output com o vetor, depois de ser ordenado.
 */
int main(){
	int array[10] = {9,12,1,6,31,10,2,17,3,23}, arraySize, i, j;
	arraySize = (sizeof(array)/sizeof(array[0]));
	
	printf("\nArray antes da ordenação:\nArray = [");
	for(i=0; i < arraySize; i++){
		if(i == arraySize-1){
			printf("%d]\n",*(array+i));
		}else{
			printf("%d, ", *(array+i));
		}
	}
	printf("\nArray depois da ordenação:\nArray = [");
	array_sort1(array,arraySize);
	
	for(j=0; j < arraySize; j++){
		if(j == arraySize-1){
			printf("%d]\n",*(array+j));
		}else{
			printf("%d, ", *(array+j));
		}
	}
	return 0;
}
