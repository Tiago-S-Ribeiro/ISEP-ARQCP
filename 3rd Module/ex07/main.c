#include <stdio.h>
#include "encrypt.h"
#include "decrypt.h"

char *ptr1;

int main(void){
	
	char str1[] = "Sheets of empty canvas";
	ptr1 = str1;
	printf("\n\nA frase é: %s\n\n", str1);
	
	int numChangedCharacters = encrypt();
	printf("O número de caracteres que foram mudados é igual a %d\n", numChangedCharacters);
	
	int desencriptados = decrypt();
	printf("Foram %d carateres desencriptados.\n", desencriptados);
	
	return 0;
}
