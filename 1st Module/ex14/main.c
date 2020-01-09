#include <stdio.h>
#include "frequencies.h"

int main(){
	
	int n, i;
	int arr_freq[21];
	int *freq = arr_freq;
	
	printf("How many students are in this class?");
	scanf("%d", &n);
	
	while(n <= 0){
		printf("The number of students must be a positive number!\n");
		printf("How many students are in this class?");
		scanf("%d", &n);
	}
	
	float arr_grades[n];
	float *grades = arr_grades;
	
	for(i = 0; i < n; i++){
		printf("What is the grade of the %dº student?", i+1);
		scanf("%f", &arr_grades[i]);
		while(!(arr_grades[i] > 0.0) && !(arr_grades[i] < 20.0)){
			printf("Invalid grade! Grades are between 0 and 20.");
			printf("What is the grade of the %dº student?", i+1);
			scanf("%f", &arr_grades[i]);
		}
	}
	
	frequencies(grades, n, freq);
	
	printf("The frequencie of grades is: \n");
	for(i = 0; i <=20; i++){
		if(i == 20){
			printf("%d\n", arr_freq[i]);
		}
		else{
			printf("%d, ", arr_freq[i]);
		}
	}
	
	return 0;
}
