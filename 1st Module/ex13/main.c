#include <stdio.h>
#include "where_is.h"
/*
 * É definido um array de carateres aleatórios e criado de seguida um array vazio
 * com o mesmo tamanho. É pedido um input ao utilizador de um caracter que deseje procurar.
 * É chamada de seguida a função 'where_is' para contar as ocorrências do caracter escolhido
 * pelo utilizador, e guardar os index's onde os mesmos foram encontrados.
 */
int main(){
	char array1[10]={'A','.','s',',','5','@','A','=','.',' '}, target;
	int size = (sizeof(array1)/sizeof(array1[0])), timesFound, i;
	int array2[size];
	
	printf("\nInsira o caracter que deseja procurar no array:\n");
	scanf("%c", &target);
	
	timesFound = where_is(array1, target, array2);
	if(timesFound != 0){
		printf("\nO caracter '%c', foi encontrado %d vezes no array.\n",target,timesFound);
		printf("\nArray com os index's onde '%c' foi encontrado = ",target);
	    printf("[");
		for(i=0; i < timesFound; i++){
			if(i == timesFound-1){
			printf("%d]\n",*(array2+i));
		}else{
			printf("%d, ", *(array2+i));
		}
		}
	}else{
		printf("\nO caracter não existe no array.\n");
	}
	return 0;
}
