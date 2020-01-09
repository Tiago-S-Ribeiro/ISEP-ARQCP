#include <stdio.h>
#include "new_salary.h"

int code = 0;
int currentSalary = 0;

int main(void) {

	int result = 0;
	
	code = 10;
	currentSalary = 600;
	printf("O salário é %d, o código é %d\n", currentSalary, code);
	result = new_salary();
	printf("O salário com o aumento é igual a %d\n\n", result);

	code = 11;
	currentSalary = 500;
	printf("O salário é %d, o código é %d\n", currentSalary, code);
	result = new_salary();
	printf("O salário com o aumento é igual a %d\n\n", result);

	code = 12;
	currentSalary = 400;
	printf("O salário é %d, o código é %d\n", currentSalary, code);
	result = new_salary();
	printf("O salário com o aumento é igual a %d\n\n", result);

	code = 14;
	currentSalary = 300;
	printf("O salário é %d, o código é %d\n", currentSalary, code);
	result = new_salary();
	printf("O salário com o aumento é igual a %d\n\n", result);

	return 0;
}
