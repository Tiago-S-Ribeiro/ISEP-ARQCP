#include <stdio.h>
#include "needed_time.h"

short current = 0;
short desired = 0;

int main(void){
 	
 	int timeElapsed = 0;
	
	current = 25;
	desired = 22;
	timeElapsed = needed_time();

	printf("%s", "A temperatura atual é ");
	printf("%d ºC\n", current);
	printf("%s", "A tempreatura desejada é ");
	printf("%d ºC\n", desired);
	printf("%s", "O tempo que passou para que para que a tempratura mudasse foi ");
	printf("%d segundos\n", timeElapsed);

	current = 18;
	desired = 22;
	timeElapsed = needed_time();

	printf("%s", "A temperatura atual é ");
	printf("%d ºC\n", current);
	printf("%s", "A tempreatura desejada é ");
	printf("%d ºC\n", desired);
	printf("%s", "O tempo que passou para que para que a tempratura mudasse foi ");
	printf("%d segundos\n", timeElapsed);

	current = 22;
	desired = 22;
	timeElapsed = needed_time();

	printf("%s", "A temperatura atual é ");
	printf("%d ºC\n", current);
	printf("%s", "A tempreatura desejada é ");
	printf("%d ºC\n", desired);
	printf("%s", "O tempo que passou para que para que a tempratura mudasse foi ");
	printf("%d segundos\n", timeElapsed);

 	return 0;
}
