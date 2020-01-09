int where_is (char *str, char c, int *p){
	int i, length = strlen(str), contador=0;
	//se o array inicial estiver vazio, devolve 0
	if(str[0] == '\0'){
		return 0;
	}
	/*
	 * Percorre o array1, e verifica em cada posicao, se o seu elemento é igual
	 * ao caracter c passado como argumento da função. Se for igual, adiciona o seu
	 * index ao array2. No fim, retorna o número de vezes que efetuou essa operação.
	 */
	for(i=0; i < length; i++){
		if(*(str+i) == c){
			*(p+contador) = i;
			contador++;
		}
	}
	return contador;
}
