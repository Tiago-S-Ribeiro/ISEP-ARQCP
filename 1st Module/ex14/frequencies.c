void frequencies(float *grades, int n, int *freq){
	
	int i, j;
	
	for(i = 0; i <= 20; i++){
		*(freq + i) = 0;
	}
  
	for(i = 0; i < n; i++){
		j = (int) (*(grades + i));
		(*(freq + j))++;
	}

}
