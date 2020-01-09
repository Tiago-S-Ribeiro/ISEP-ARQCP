#include <stdio.h>
#include "test_equal.h"
 
int main(void){
	
	char *a;
	char *b;
	char string1[] = "Say hello";
	char string2[] = "to heaven";
	int resultado;
	
	a = string1;
	b = string2;
	resultado = test_equal(a,b);
	if(resultado == 1){
		printf("As strings são iguais.");
	}else{
		printf("As strings são diferentes.");
	}
	
	return 0;
}
