#include <stdio.h>

int sum_even(int *p, int num){
	int i, count=0;
	for(i=0; i < num; i++){
		if(*(p+i)%2 == 0){
			count+=p[i];
		}
	}
	return count;
}
