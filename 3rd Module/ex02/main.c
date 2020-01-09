#include <stdio.h>
#include "str_copy_porto.h"

char* ptr1;
char* ptr2;

int main(void){
	
	char str1[] = "eddie vedder";
	char str2[50];
	
	ptr1 = str1;
	ptr2 = str2;
	
	str_copy_porto();
	
	printf("Frase original: %s\n", str1);
	printf("Frase alterada: %s\n", str2);
	
	return 0;
}
