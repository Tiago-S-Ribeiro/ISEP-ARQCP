#include <stdio.h>
#include "vec_add_one.h"

int* ptrvec;
int num = 5;

int main(void){
	
	int i, int_array[] = {1,2,-3,4,5};
	ptrvec = int_array;
	
	printf("Array: ");
	for(i = 0; i < num; i++){
		if(i == num - 1){
			printf("%d\n", int_array[i]);
		}
		else{
			printf("%d, ", int_array[i]);
		}
	}
	
	vec_add_one();
	
	printf("Array alterado: ");
	for(i = 0; i < num; i++){
		if(i == num - 1){
			printf("%d\n", int_array[i]);
		}
		else{
			printf("%d, ", int_array[i]);
		}
	}
	
	return 0;
}
