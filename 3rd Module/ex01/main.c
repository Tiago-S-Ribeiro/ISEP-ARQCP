#include <stdio.h>
#include "zero_count.h"

char *ptr1;

int main(){
	char str1[] = "000001Tiago0 0 Ribeiro 07";
	ptr1 = str1;
	int n = zero_count();
	printf("A quantidade de zeros na string é: %d\n", n);
	
	return 0;
}
