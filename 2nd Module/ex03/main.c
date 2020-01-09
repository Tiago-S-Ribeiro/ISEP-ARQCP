#include <stdio.h>
#include "asm.h"
#include "sum_v2.h"

int op1=0, op2=0, res=0, res2=0;

int main(void) {
	printf("Valor op1:");
	scanf("%d",&op1);
	printf("Valor op2:");
	scanf("%d",&op2);
	
	res = sum();
	res2 = sum_v2();
	
	printf("sum = %d:0x%x\n", res,res);
	printf("sum_v2 = (15-%d) - (15-%d) = %d\n", op1,op2,res2); 
	return 0;
}
