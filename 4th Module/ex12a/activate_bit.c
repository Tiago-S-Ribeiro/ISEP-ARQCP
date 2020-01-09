int activate_bit(int *ptr, int pos){
	int valor;
	int mascara = 1;
	mascara = (mascara << pos);		// shift para a esquerda 'pos' vezes
	valor = mascara & *ptr;		 	// 1 AND *ptr
	*ptr = *ptr | mascara;			// ptr OR mascara (para o número ficar igual, à excepção do bit alterado)

	if(valor == 0){ 				// se o bit menos significativo for 0
		return 1;					// retorna 1 porque o bit foi mudado.
	}
	return 0;
}
