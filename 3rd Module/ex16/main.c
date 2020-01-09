#include <stdio.h>
#include "swap.h"

char *ptr1;
char *ptr2;
int num = 11;

int main(void){
	
	char vec1[] = "As palavras";
	char vec2[] = "Sao silabas";
	
	ptr1 = vec1;
	ptr2 = vec2;
	
	printf("Primeiro array: %s\n", vec1);
	printf("Segundo array: %s\n\n", vec2);
	
	swap();
	printf("------(((SWAP)))------\n\n");
	
	printf("Primeiro array: %s\n", vec1);
	printf("Segundo array: %s\n", vec2);
	
	return 0;
}
