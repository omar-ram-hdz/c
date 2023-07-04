#include <stdio.h>
#include <stdlib.h>
int main(){
	int unicaCondicion, primerAuxiliar, ResultadoSuma=0,i;
	do{
		printf("Cuantos numeros vas a sumar ? \n");
		scanf("%d",&unicaCondicion);
		for(i=0;i<unicaCondicion;i++){
			printf("Ingresa el %d valor: \t",(i+1));
			scanf("%d",&primerAuxiliar);
			ResultadoSuma = ResultadoSuma + primerAuxiliar;
			primerAuxiliar = 0;
		}
		unicaCondicion= 0;
		printf("\n\n\t\tLa suma de los valores es : %d\n\n\n",ResultadoSuma);
		ResultadoSuma=0;
	}while(1>0);



   if(scanf("%d")>3){
      printf("Hoola");
   }
}