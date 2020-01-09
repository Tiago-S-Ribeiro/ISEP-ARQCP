#include <string.h>
/*
 * A função troca os valores dos dois arrays, recorrendo ao uso de um array
 * temporário.
 */ 
void swap(int* vec1, int* vec2, int size){
	int i, temporario[size];
	
	for(i=0; i < size; i++){
		*(temporario+i) = *(vec1+i);
		*(vec1+i) = *(vec2+i);
		*(vec2+i) = *(temporario+i);
	}
}
