/* A seguinte função ordena o vetor por ordem crescente da seguinte forma:
 * Começa por comparar elemento na primeira posição, com todos os outros verificando qual o maior.
 * Se o elemento na primeira posição for maior que o elemento a quem se compara, os elementos 
 * são trocados de posição. Isto é feito sucessivamente para o resto do vetor.
 * No fim, o vetor está ordenado pois foram trocados sucessivamente elementos pela sua grandeza.
 */
void array_sort1(int *vec, int n){
	int i,j, temporaria;
	
	for(i=0; i < n; i++){
		for(j=i+1; j < n; j++){
			
			if(vec[i] > vec[j]){
				
				temporaria = vec[i];
				vec[i] = vec[j];
				vec[j] = temporaria;
			}
		}
	}
}
