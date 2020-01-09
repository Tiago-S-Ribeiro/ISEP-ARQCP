#include <stdio.h>
#include "rotate.h"

int main(void){
	
	int num = 10;
	int nbits = 11;
	
	int num_left = rotate_left(num, nbits);
	int num_right = rotate_right(num, nbits);
	
	printf("Ao rodar %d bits para a esquerda, o número fica igual a %d\n", nbits, num_left);
	printf("Ao rodar %d bits para a direita, o número fica igual a %d\n", nbits, num_right);
	
	return 0;
}
