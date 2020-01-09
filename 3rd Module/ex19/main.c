#include <stdio.h>
#include "frequencies.h"

char *ptrgrades;
int num = 10;
int *ptrfreq;

int main(void){
	
	char grades[] = {13, 14, 7, 9, 0, 9, 6, 6, 4, 1};
	int i, freq[21];
	
	ptrgrades = grades;
	ptrfreq = freq;
	
	frequencies();
	
	printf("Notas: ");
	for (i = 0; i < 10; i++){
		printf("%d ", grades[i]);
	}
	printf("\n");
	
	printf("Frequências: ");
	for (i = 0; i < 20; i++){
		printf("%d ", freq[i]);
	}
	printf("\n");
	
	return 0;
}
