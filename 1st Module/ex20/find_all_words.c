#include <stdio.h>
#include <stdlib.h>
#include "find_word.h"

void find_all_words(char* str, char* word, char** addrs){
	
	int word_size = 0;
	int i;
	for (i = 0; word[i] != '\0'; i++) {
		word_size++;
	}
	
	char *ptr;
	
	char *initialAddress = str;
	
	while(*str != '\0'){
		ptr = find_word(str, word, initialAddress);
		if(ptr != NULL){
			*addrs = ptr;
			addrs++;
			initialAddress = ptr + word_size;
			str = ptr + word_size;
		}
		else{
			str++;
		}
	}
	
}
