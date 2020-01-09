int rotate_left(int num, int nbits){

	return (num << nbits)|(num >> (32 - nbits));	// retorna o número que resulta de rodar nbits bits para a esquera do número inicial (num), (num << nbits) se o número estiver guardado em 8 bits ou (num >> (32 - nbits)) se estiver guardado em 16 ou 32 bits
}


int rotate_right(int num, int nbits){
	
	return (num >> nbits)|(num << (32 - nbits));	// retorna o número que resulta de rodar nbits bits para a direita do número inicial (num), (num >> nbits) se o número estiver guardado em 8 bits ou (num << (32 - nbits)) se estiver guardado em 16 ou 32 bits
}

