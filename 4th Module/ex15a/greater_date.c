unsigned int greater_date(unsigned int data1, unsigned int data2){
	
	short ano1 = (short) (data1 >> 8)|(data1 << (32 - 8));	// mete o ano da data1 na variável ano1
	short ano2 = (short) (data2 >> 8)|(data2 << (32 - 8));	// mete o ano da data2 na variável ano2
	
	if(ano1 > ano2){
		return data1;
	}
	else if(ano1 < ano2){
		return data2;
	}
	
	char mes1 = (char) (data1 >> 24)|(data1 << (32 - 24));	// mete o mês da data1 na variável mes1
	char mes2 = (char) (data2 >> 24)|(data2 << (32 - 24));	// mete o mês da data2 na variável mes2
	
	if(mes1 > mes2){
		return data1;
	}
	else if(mes1 < mes2){
		return data2;
	}
	
	char dia1 = (char) data1;								// mete o dia da data1 na variável dia1
	char dia2 = (char) data2;								// mete o dia da data2 na variável dia2
	
	if(dia1 > dia2){
		return data1;
	}
	else if(dia1 < dia2){
		return data2;
	}
	
	return data1;
}
