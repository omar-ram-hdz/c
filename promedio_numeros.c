#include <stdlib.h>
#include <stdio.h>
void main() {
	int numeros;
	printf("\a");
	printf("*********** INICIO DEL PROGRAMA *********** \n");
	printf("Ingresa la cantidad de numeros de la cual deseas sacar un promedio: \n\t\t\t\t\t");
	scanf("%d",&numeros);
	int matriz[numeros], i = 0;
	
	for(i=0; i<numeros; i++) {
		printf("Ingresa el numero %d:  ",(i+1));
		scanf("%d",&matriz[i]);
	}
	
	int suma = 0;
	for(i=0; i<numeros; i++) {
		suma = suma + matriz[i];
	}
	
	float promedio = suma / numeros;
	
	
	printf("\a");
	printf("*********** RESULTADOS *********** \n");
	printf("Promedio: %.2f", promedio);
}