#include <stdio.h>
#include "odd_sum.h"

int main(){
	
	int elements, i;
	
	printf("How many numbers you want to put in the array?");
	scanf("%d", &elements);
	
	while(elements <= 0){
		printf("Sorry, the number of elements in this array have to be more than zero.");
		printf("How many numbers you want to put in the array?");
		scanf("%d", &elements);
	}
	
	int numbers[elements + 1];
	numbers[0] = elements;
	
	for(i = 1; i <= elements; i++){
		printf("Please choose the value of the %dº element: ", i);
		scanf("%d", &numbers[i]);
	}
	
	printf("The sum of all the odd numbers in your array is: %d\n", odd_sum(numbers));
	
	return 0;
}
