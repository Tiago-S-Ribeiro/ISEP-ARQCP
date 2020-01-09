#include <stdio.h>
#include "getArea.h"

int base;
int height;
int area;

int main(void){
	
	printf("Base: %d\n", base);
	printf("Altura: %d\n", height);
	area = getArea();
	printf("Área do triângulo = %d\n", area);
	
	return 0;
}
