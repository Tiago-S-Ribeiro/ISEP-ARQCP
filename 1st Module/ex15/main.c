#include <stdio.h>
#include "populate.h"
#include "check.h"
#include "inc_nsets.h"
#define VEC_SIZE 100

/*
 * É definido um array de 100 posições com números aleatórios. O progama gera um
 * vetor com números entre 0 e 20 para realizar a função pedida no enunciado. É dado um output
 * do resultado do número de conjuntos com três números consecutivos, fazendo uma chamada do método,
 * que verifica se cada conjunto de três elementos compreendidos nos 100 do array verificão a condição
 * referida no enunciado e do método que incrementa o valor da variável do número de conjuntos que verificam essa mesma condição.
 */

int nSets = 0;

int main(){
	
	int vec[VEC_SIZE], i;
	
	populate(vec, 100, 21);
	
	for(i = 0; i < VEC_SIZE - 2; i++){
		if(check(vec[i], vec[i+1], vec[i+2]) == 1){
			inc_nsets();
		}
	}
	
	printf("Array: ");
	for(i = 0; i < VEC_SIZE; i++){
		if(i != VEC_SIZE - 1){
			printf("%d, ", vec[i]);
		}
		else{
			printf("%d\n", vec[i]);
		}
	}
	
	printf("Number of sets of three consecutive elements: %d.\n", nSets);
	
	return 0;
}
