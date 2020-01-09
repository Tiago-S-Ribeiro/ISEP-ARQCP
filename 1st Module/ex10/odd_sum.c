int odd_sum(int *p){

	int i, sum = 0;
	
	for(i = 1; i <= p[0]; i++){
		if(!(p[i] % 2 == 0)){
			sum = sum + p[i];
		}
	}

	return sum;
}
