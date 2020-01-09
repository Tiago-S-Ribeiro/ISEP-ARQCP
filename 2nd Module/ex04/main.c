#include <stdio.h>
#include "asm.h"

int op1=0, op2=0, op3, op4,res3=0;
int main(){
	printf("Valor op1:");
	scanf("%d",&op1);
	printf("Valor op2:");
	scanf("%d",&op2);
	
	res3 = sum_v3();
	
	printf("sum_v3 = (%d + %d - %d + %d) = %d\n",op4,op3,op2,op1,res3);
	return 0;
}
