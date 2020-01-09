void changes(int *ptr){
	char aux = 20;			// 3bytes = 24bits, logo 20 vem de 24 menos os 4 'mais significativos'
	int n, num = *ptr;		// guarda o valor de *ptr
	num >>= aux;			// faz shift do valor de *ptr 20 bits para a direita
	n = num & 15;			// n AND 15 de modo a dar o valor dos 4 bits menos significativos do segundo byte
	if(n > 7) {				// se o valor for maior que 7 inverte os bits
		while ( aux != 24) {		// so faz o ciclo ate ao limite dos 3 bytes
			*(ptr) ^= (1 << aux);	// a funcao XOR altera os bits e
									// posteriormente desloca-se 1 bit para a esquerda para se passar ao proximo
			aux++;					// proximo it a ser lido
		}
	}
}
