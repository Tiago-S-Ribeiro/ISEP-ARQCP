void power_ref(int *x, int y){
	int i, power = *x;
	if(y == 0){
		*x = 1;
	}else if(y < 0){
		*x = 0;
	}else{
		for(i = 1; i < y; i++){
			power *= *x;
		}
	*x = power;
	}
}
