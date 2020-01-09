/*
 * A função começa por declarar um pointer short auxiliar que vai igual ao pointer de 
 * integers que recebe por parâmetro, este que também recebe um cast para estarmos a 
 * trabalhar valores do mesmo tipo. Depois percorre o array original de shorts, adicionando
 * os seus valores ao array auxiliar, que como é integer inicialmente, converte cada
 * 2 shorts para 1 int pois passa de 2 bytes a 4.
 */
void compress_shorts(short* shorts, int n_shorts, int* integers){
	int i;
	
	short *auxiliar = (short *) integers;
	
	for(i=0; i < n_shorts; i++){
		(*(auxiliar+i)) = (*(shorts+i));
	}
}
