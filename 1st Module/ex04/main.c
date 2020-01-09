#include <stdio.h>
#include "upper1.h"
/*
 * ex04- É pedido um input ao utilizador para uma palavra, é chamado o método pedido pelo
 * enunciado, que passa todas as letras minúsculas da palavra para maiúsculas, fazendo as verificações necessárias.
 * É depois dado um output do resultado ao utilizador.
 */

int main(){
	
	char *str;
	char word[50];
	
	printf("Write a word: ");
	scanf("%s", word);
	
	str = word;
	
	upper1(str);
	
	printf("The word you wrote is now in uppercases: ");
	printf("%s\n", word);
	
	return 0;
}
