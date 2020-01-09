void upper2(char *str){

	char *ptr = str;
	
	while(*ptr != '\0'){
		if((*ptr >= 'a') && (*ptr <= 'z')){
			*ptr = *ptr - ('a' - 'A');
		}
		ptr++;
	}

}
