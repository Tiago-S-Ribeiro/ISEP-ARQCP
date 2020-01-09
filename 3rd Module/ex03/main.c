#include <stdio.h>
#include "str_copy_porto2.h"

char *ptr1;
char *ptr2;

int main(void){
	char str1[] = "VR BEST EVER victory by 3 BV";   //array com a string original
	char str2[100];									//array que vai receber a nova string

	ptr1 = str1;
	ptr2 = str2;

	str_copy_porto2();								//função sem retorno(procedimento)

	printf("String inicial = %s\n", str1);
	printf("String final = %s\n", str2);

	return 0;
}
