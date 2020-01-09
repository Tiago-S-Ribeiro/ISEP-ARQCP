void upper1(char *str){
	
	int i;
	
	for(i = 0; str[i] != '\0'; i++){
		if((*(str + i) >= 'a') && (*(str + i) <= 'z')){
			*(str + i) = *(str + i) - ('a' - 'A');
		}
	}

}
