#include <stdio.h>
#include <ctype.h>
#include "palindrome.h"
/*
 * É pedido um input de uma string ao utilizador, é depois verificado através da
 * função 'palindrome' que devolve '1' se a string for palindrome, e '0' se não for.
 * É depois dado um output para informar se a string é ou não palindrome então.
 */
int main(){
	char phrase[100], *pString;
	
	printf("\nInsira uma string: ");
	scanf("%[^\n]s", phrase);
	pString = phrase;
	
	if(palindrome(pString) == 1){
		printf("\nA string inserida é palindrome.\n");
	}else{
		printf("\nA string inserida não é palindrome.\n\n");
	}
	return 0;
}
