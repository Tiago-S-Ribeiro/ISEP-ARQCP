#include <stdio.h>
#include <stdlib.h>
#include "find_word.h"

int main(){

	char str[100];
	char word[100];
	char *initial_addr = &str[0];
	
	printf("Write a sentence please: ");
	scanf("%[^\n]s", str);
	
	while ((getchar()) != '\n'); // to flush the input buffer
	
	printf("Now write a word please: ");
	scanf("%s", word);
	
	if(find_word(str, word, initial_addr) != NULL){
		printf("The word was found on the sentence\n");
	}
	else{
		printf("The word was not found on the sentence\n");
	}

	return 0;
}
