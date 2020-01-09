/*
 * Método utilizado para verificar se um determinado número, já existe no array
 * Se existir, é devolvido 0, se não existir, devolve 1.
 */
int isThere(int *dest, int nElem, int num){
	int i;
	for(i=0; i < nElem; i++){
		if(dest[i] == num){
			return 0;
		}
	}
	return 1;
}
/*
 * Método que ordena um array em ordem crescente, comparando cada elemento aos
 * outros, e trocando a sua posição se necessário.
 */
void sort(int *dest, int nElem){
	int i, j, temporaria;
	
	for(i=0;i < nElem-1;i++){
		for(j=i+1;j < nElem;j++){
			
			if(dest[i] > dest[j]){
				temporaria = dest[i];
				dest[i] = dest[j];
				dest[j] = temporaria;
			}
		}
	}
}
/*
 * Método pretendido pelo enunciando, é percorrido o array inicial, e a cada iteração 
 * no mesmo, é verificado a existência desse elemento no segundo array. Caso não exista,
 * é colocado lá esse elemento, evitando assim repetições. É depois chamado o método
 * acima descrito para ordenar o segundo array, e é devolvido o número de elementos
 * que lá foram colocados
 */
int sort_without_reps(int *src, int n, int *dest){
	int c = 0, i;
	
	for(i=0;i < n;i++){
		if(isThere(dest, n, src[i]) == 1){
			dest[c] = src[i];
			c++;
		}
	}
	sort(dest, c);
	return c;
}

