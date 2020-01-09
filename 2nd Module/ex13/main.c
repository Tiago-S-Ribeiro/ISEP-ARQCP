#include <stdio.h>
#include "getArea.h"

int base = 5;
int height = 4;

int main(void){
	
	int area;
	
	printf("A altura do triângulo é %d, e a base é %d\n", height, base);
	area = getArea();
	
	printf("A área do triâgulo é igual a %d\n", area);
	
	return 0;
}
