void capitalize(char *str){

	char *ptr = str;
	
	while(*ptr != '\0'){
		if(*ptr == str[0] || *(ptr - 1) == ' '){
			if((*ptr >= 'a') && (*ptr <= 'z')){
				*ptr = *ptr - ('a' - 'A');
			}
		}
		ptr++;
	}

}
