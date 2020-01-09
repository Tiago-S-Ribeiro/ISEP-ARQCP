#include <stdio.h>
#include "compress_shorts.h"

int main(){
	short array1[6]={1,2,3,4,5,6};
	int array1Size = (sizeof(array1)/sizeof(array1[0]));
	int array2Size = array1Size/2;
	int array2[array2Size], i;
	
	printf("\n[");
	for(i=0; i < array1Size; i++){
		if(i == array1Size-1){
			printf("%d]\n", *(array1+i));
		}
		else{
			printf("%d, ", *(array1 +i));
		}
	}
	
	compress_shorts(array1, array1Size, array2);
	/*
	 * Conforme sugerido pelo professor, o valor é impresso em hexadecimal de forma
	 * a ser possível visualizar os novos valores, onde é possível ver o mais e menos
	 * significativa de forma clara.
	 */
	printf("\n[");
	for(i=0; i < array2Size; i++){
		if(i == array2Size-1){
			printf("%x]\n", *(array2+i));
		}
		else{
			printf("%x, ", *(array2 +i));
		}
	}
	
	return 0;
}
