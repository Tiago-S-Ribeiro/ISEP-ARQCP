#include <stdio.h>
#include "changes.h"
#include "changes_vec.h"

int main(void)
{
	int vec[] = {4, 6, 9, 3, 1};
	int *ptrvec;
	int num = 5;
	
	ptrvec = vec;
	changes_vec(ptrvec, num);

	return 0;
}
