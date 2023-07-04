#include <stdio.h>
#include <stdlib.h>
int main(){
	int numero, resultado=8,i, aux=8;
	do{
		printf("Ingresa el exponencial\n");
		scanf("%d",&numero);
		for(i=0;i<numero;i++){
			resultado = resultado * aux;
			printf("\t%d\n",resultado);
		}
		resultado=8;
	}while(1>0);
}