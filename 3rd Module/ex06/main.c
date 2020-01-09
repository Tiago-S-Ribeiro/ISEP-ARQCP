#include <stdio.h>
#include "encrypt.h"

char *ptr1;

int main(void){
	char str1[] = "Toda a gente limpa o carro.";
	
	ptr1 = str1;
	
	printf("A frase é: %s\n", str1);
	
	int numChangedCharacters = encrypt();
	
	printf("O número de caracteres que foram mudados é igual a %d\n", numChangedCharacters);
	
	return 0;
}
