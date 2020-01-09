#include <stdio.h>
#include "power_ref.h"
/*
 * ex06- É pedido um input ao utilizador para x e y, é chamado o método pedido pelo
 * enunciado, que calcula a potência y de x, fazendo as verificações necessárias, sendo negativa
 * o resultado é 0, sendo nula o resultado é 1. É depois dado um output do resultado 
 * ao utilizador.
 */
int main(){
	int x, y;
	printf("\nInsira um valor de 'X':");
	scanf("%d", &x);
	printf("\nInsira um valor de 'Y':");
	scanf("%d", &y);
	power_ref(&x,y);
	printf("\nA %dº potência de 'X' é: %d",y,x);
	printf("\n'X' tem agora o seu valor a: %d.\n\n",x);
	return 0;
}
