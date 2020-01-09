#include <stdlib.h>
#include <time.h>

void populate( int *vec , int num, int limit){
	
	int i;
	
	srand(time(NULL)); // seed generator for pseudo-random numbers
	
	for(i = 0; i < num; i++){
		vec[i] = rand() % limit;
	}
	
}
