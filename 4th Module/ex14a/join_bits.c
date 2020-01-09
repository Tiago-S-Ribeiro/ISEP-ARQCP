#include <stdio.h>

int join_bits(int a, int b, int pos){

	int aux=0, aux2=0;

	aux2=(1<<pos)-1;		// move o numero 'pos' vezes para a esquerda e retira 1
							// dando uma mascara com '1's ate pos-1 e depois 0s
	aux2=(aux2<<1)+1;		// faz shift um bit para a esquerda da mascara e adiciona 1
							// ficando entao com '1's de 0 ate pos e depois 0

	a = (a& aux2);			// a AND mascara - guarda os bits de 0 ate pos do numero a
	b = (b& (~aux2));		// b AND NOT mascara - inverte a mascara - fica com 0 de 0 ate pos e depois 1
							// guardando entao os bits de b de pos+1 ate ao fim
	aux = (a|b);			// junta as duas metades dos numeros

	return aux;
}
