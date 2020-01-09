#include <stdio.h>
#include "str_cat.h"

char *ptr1;
char *ptr2;
char *ptr3;

int main(void){
	
	char str1[40] = "As coisas da vida às vezes são ";
	char str2[40] = "coisas, outras vezes são cenas.";
	char str3[80];
	
	ptr1 = str1;
	ptr2 = str2;
	ptr3 = str3;
	
	printf("Primeira frase: %s\n", str1);
	printf("Segunda frase: %s\n", str2);
	
	str_cat();
	
	printf("As frases juntas: %s\n", str3);
	
	return 0;
}
