#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char* find_word(char* str, char* word, char* initial_addr){

	char *p;

	int i, j=0, k, inicio = 0;
	
	for(i=0; str[i]; i++){
		if((str + i) != initial_addr){
			inicio++;
		}
		else
		  break;
	}
  
	for(i=inicio; str[i]; i++){
		if(toupper(str[i]) == toupper(word[j])){
			p = (str + i);
			for(k=i, j=0; str[k] && word[j]; j++, k++){
				if(toupper(str[k]) != toupper(word[j])){
					break;
				}
			}
			if(!word[j]){
				return p;
			}
		}
	}
	return NULL;
}
