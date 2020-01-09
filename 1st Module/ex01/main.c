#include <stdio.h>

int main(){
	
	int x = 5;
	int* xPtr = &x;
	float y = *xPtr + 3;
	int vec[] = {10, 11, 12, 13};
	
	// a)
	printf("Valor de 'x' = %d\n", x);
	printf("Valor de 'y' = %f\n", y);
	printf("Endereço de 'x' em Hexadecimal = %X\n",(unsigned int)&x);
	printf("Endereço de 'xPtr' em Hexadecimal = %X\n", (unsigned int)&xPtr);
	printf("Valor apontado por 'xPtr' = %d\n", *xPtr);
	printf("Endereço de 'vec' = %p\n", vec);
	printf("Valor de vec[0] = %d\n", vec[0]);
	printf("Valor de vec[1] = %d\n", vec[1]);
	printf("Valor de vec[2] = %d\n", vec[2]);
	printf("Valor de vec[3] = %d\n", vec[3]);
	printf("Endereço de vec[0] = %p\n", &vec[0]);
	printf("Endereço de vec[1] = %p\n", &vec[1]);
	printf("Endereço de vec[2] = %p\n", &vec[2]);
	printf("Endereço de vec[3] = %p\n", &vec[3]);
	
	/* b)
	 Os endereços dos elementos de vec, têm entre si 4 bits de distância, 
	 pois cada int ocupa 4 bits.*/
	 
	 /* c)
	  Será esperado um resultado diferente, pois o endereço depende da arquitetura
	  e memória a ser utilizada, logo, se o programa for executado numa máquina
	  de 64bits, o endereço deverá ser diferente do que a execução em 32bits.
	  */
	return 0;
}
