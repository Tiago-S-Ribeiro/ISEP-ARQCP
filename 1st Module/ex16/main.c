#include <stdio.h>
#include <stdlib.h>
#include "where_exists.h"

int main(){
	
	char str1[100], str2[100];
	
	printf("Write a sentence: ");
	scanf("%[^\n]s", str1);
	
	while ((getchar()) != '\n'); // // to flush the input buffer
	
	printf("Write another sentence: ");
	scanf("%[^\n]s", str2);
	
	if(where_exists(str1, str2) == NULL){
		printf("The first sentence is not within the second.\n");
	}
	else{
		printf("The first sentence is within the second.\n");
	}
	
	return 0;
}
