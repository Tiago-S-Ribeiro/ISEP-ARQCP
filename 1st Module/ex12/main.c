#include <stdio.h>
#include "capitalize.h"
/*
 * ex12- É pedido um input ao utilizador de uma frase, é chamado o método pedido pelo
 * enunciado, que passa todas as iniciais minúsculas de cada palavra para maiúsculas, fazendo as verificações necessárias.
 * É depois dado um output do resultado ao utilizador.
 */

int main(){
	
	char *str;
	char sentence[100];
	
	printf("Write a sentence: ");
	scanf("%[^\n]s", sentence);
	
	str = sentence;
	
	capitalize(str);
	
	printf("The sentece you wrote is now capitalized: ");
	printf("%s\n", sentence);
	
	return 0;
}
