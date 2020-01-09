#include <stdio.h>
#include "swapBytes.h"
short s = 0xAABB;

int main(){
	
	printf("%#X\n", s);	
	s = swapBytes();	
	printf("%#X\n", s);
	
	return 0;
}
