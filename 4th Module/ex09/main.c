#include <stdio.h>
#include "calculate.h"

void print_result(char op, int o1, int o2, int res){
	printf("%d %c %d = %d\n", o1, op, o2, res);
}

int main(void){
	
	int a = 2;
	int b = 13;
	
	int result = calculate(a, b);
	
	printf("O resultado de (a+b)-(a*b) é igual a %d\n", result);
	
	return 0;
}
