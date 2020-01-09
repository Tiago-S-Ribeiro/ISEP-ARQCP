int activate_bits(int a, int left, int right) {
	int i;
	
	for(i = left + 1; i < 32; i++){ // percorre os bits de a do bit left (excluindo) até ao último bit
		a |= 1 << i;				// ativa o bit i de a caso o bit não esteja ativo
	}
	
	for(i = 0; i < right; i++){		// percorre os bits de a do primeiro até ao bit right (excluindo)
		a |= 1 << i;				// ativa o bit i de a caso o bit não esteja ativo
	}
	
	return a;						// retorna o novo valor de a
}
