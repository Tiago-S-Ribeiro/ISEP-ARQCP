#include <stdio.h>
#include "concatBytes.h"

char byte1 = 0xbb;
char byte2 = 0xcc;

int main(){
	printf("byte1 = %X\nbyte2 = %X\n",byte1, byte2);
	short concatenado = concatBytes();
	printf("short concatenado = %hx\n", concatenado);
	return 0;
}
