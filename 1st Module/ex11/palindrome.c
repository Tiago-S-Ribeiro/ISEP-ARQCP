#include <string.h> 

int palindrome(char *str){
	int i = 0, length = strlen(str)-1;
	// verificação se o array passado está vazio
	if(str[0] == '\0'){
		return 0;
	}
	/*
	 * Verificação de palindrome:
	 * A função começa por verificar o primeiro e ultimo elemento da string
	 * passando à frente o elemento a ser avaliado caso ele seja um espaço, uma
	 * vírgula ou um ponto final. Se um elemento a ser avaliado for diferente 
	 * do seu'espelhado' correspondente, devolve 0, sendo não palindrome.
	 * A iteração prossegue até ao 'meio' da string, e devolve 1, se passar todas
	 * as condições anteriores.
	 */
	while(length > i){
		if(str[i]==',' || str[i]==' ' || str[i]=='.'){
			i++;
		}else if(str[length]==',' || str[length]==' ' || str[length]=='.'){
			length--;
		}else if(toupper(str[i]) != toupper(str[length])){
			return 0;
		}else{
			i++;
			length--;	
		}
	}
	return 1;
}
