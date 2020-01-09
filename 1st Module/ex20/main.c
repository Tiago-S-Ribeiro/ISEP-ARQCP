#include <stdio.h>
#include <stdlib.h>
#include "find_all_words.h"

int main(){

	char str[100];
	char word[100];
	char *words[50] = {NULL};
	int count = 0, i = 0;
	
	printf("Write a sentence please: ");
	scanf("%[^\n]s", str);
	
	while ((getchar()) != '\n');
	
	printf("Now write a word please: ");
	scanf("%s", word);
	
	find_all_words(str, word, words);
	
	for(i = 0; words[i] != NULL; i++){
		count++;
	}
	
	printf("The number of times that the word that you wrote appears in the sentence is: %d\n", count);
	printf("Addresses for the begining of the word: \n");
	for(i = 0; words[i] != NULL; i++){
		printf("%s\n", words[i]);
	}

	return 0;
}
