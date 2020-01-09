#include <stdio.h>
#include "sum_even.h"
/*
 * É definido um array de 8 posições com números aleatórios. O progama aceita qualquer
 * vetor com quaisquer números para realizar a função pedida no enunciado. É dado um output
 * do resultado da soma dos elementos pares do vetor, fazendo uma chamada do método
 * que verifica a paridade de cada elemento.
 */
int main(){
	int array[8]={48, 12, 13, 2, 42, 1, 3, 10},*p, num = 8;
	p=array;
	
	printf("A soma dos números pares no vetor dá um total de: %d.\n", sum_even(p,num));
	return 0;
}
