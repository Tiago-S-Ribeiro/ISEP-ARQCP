#include <stdlib.h>
char* where_exists(char *str1, char *str2){

	char *p;

	int i, j=0, k;
  
	for(i = 0; str2[i]; i++){
		if(str2[i] == str1[j]){
			p = (str2 + i);
			for(k=i, j=0; str2[k] && str1[j]; j++, k++){
				if(str2[k] != str1[j]){
					break;
				}
			}
			if(!str1[j]){
				return p;
			}
		}
	}
	return NULL;
}
