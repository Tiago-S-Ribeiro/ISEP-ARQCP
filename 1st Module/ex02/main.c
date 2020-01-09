#include <stdio.h>
#include "copy_vec.h"

int main(){

	int *vec1, *vec2, n, i, elements;
	
	printf("How many elements the first array has?");
	scanf("%d", &elements);
	
	int a_vec1[elements], a_vec2[elements];
	
	vec1 = a_vec1;
	vec2 = a_vec2;
	
	for(i = 0; i < elements; i++){
		printf("Value of element %d: \n", i+1);
		scanf("%d", &vec1[i]);
	}
	
	printf("How many elements are going to be copied from vec1 to vec2?");
	scanf("%d", &n);
	while(n > elements){
		printf("Number of elements has to be smaller than array size.\n");
		printf("How many elements are going to be copied from vec1 to vec2?");
		scanf("%d", &n);
	}
	
	copy_vec(vec1, vec2, n);
	
	printf("Vec2: ");
	for(i = 0; i < n; i++){
		printf("%d", *(vec2 + i));
	}
	printf("\n");
	
	return 0;
}
