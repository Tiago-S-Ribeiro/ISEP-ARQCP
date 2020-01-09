#include <stdio.h>
#include "f.h"

int i;
int j;

int main(){
	
	i = 7;
	j = 4;
	
	printf("i = %d\nj = %d\n", i, j);
	
	int h = f();
	printf("resultado de f(): %d\n", h);
	
	h = f2();
	printf("resultado de f2(): %d\n", h);
	
	h = f3();
	printf("resultado de f3(): %d\n", h);
	
	h = f4();
	printf("resultado de f4(): %d\n", h);
	
	return 0;
}
