#include <stdio.h>
#include "count_bits_zero.h"
#include "vec_count_bits_zero.h"

int main(void){
	int *ptr; 
	int resultado, num = 3;
	int array[] = {9, 46, 12};
	ptr = array;
	
	resultado = vec_count_bits_zero(ptr, num);
	printf("A quantidade de bits inativos = %d\n", resultado);
	
	return 0;
}
