int count_bits_zero(int x){
	
	int i;							// bit da iteração
	int auxiliar;					// carry
	int contador = 0;				// contador de bits inativos
	for (i = 1; i <= 32; i++){		// 32 iteracoes (32 bits)
    	auxiliar = x >> i;			// shift à direita
    	if (auxiliar & 1){			// se 'AND' booleano com 1 for true
									// continua
    	}
    	else{
      		contador++;				// se for false, quer dizer que o bit é 0, incrementa o contador		
    	}
  	}
  	return contador;				//devolve a quantidade de bits inativos
}
