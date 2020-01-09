#include <stdio.h>
#include "test_flags.h"

int op1;
int op2;

int main(void){

	char result;
	op1 = 0xFFFFFFFF;
	op2 = 0X1;
	result = test_flags();
	
	printf("com op1 = 0x%X e op2 = 0x%X ", op1, op2);
	if(result == 1){
		printf("%s\n", "ativou carry");
	}else{
		if(result == 0){
			printf("%s\n", "nao ativou carry nem overflow");
		}else{
			if(result == 2)
			printf("%s\n", "ativou overflow");
		}
	}

	op1 = 0x7FFFFFFF;
	op2 = 0X1;
	result = test_flags();
	
	printf("com op1 = 0x%X e op2 = 0x%X ", op1, op2);
	if(result == 1){
		printf("%s\n", "ativou carry");
	}else{
		if(result == 0){
			printf("%s\n", "nao ativou carry nem overflow");
		}else{
			if(result == 2)
			printf("%s\n", "ativou overflow");
		}
	}

	op1 = 0x2;
	op2 = 0X1;
	result = test_flags();
	
	printf("com op1 = 0x%X e op2 = 0x%X ", op1, op2);
	if(result == 1){
		printf("%s\n", "ativou carry");
	}else{
		if(result == 0){
			printf("%s\n", "nao ativou carry nem overflow");
		}else{
			if(result == 2)
			printf("%s\n", "ativou overflow");
		}
	}

	return 0;
}
