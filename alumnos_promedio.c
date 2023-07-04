#include <stdio.h>
#include <stdlib.h>
void main() { 
	float calificaciones[5][3], promedios[5];
	char nombre_alumnos[5][50];
	printf("\a");
	printf("*********** INICIO DEL PROGRAMA *********** \n");
	printf("Este programa fue diseniado para calcular el promedio de 5 alumnos \n de los 3 parciales correspondientes a la materia de matematicas \n");
	int i = 0, j = 0;
	for (i=0;i<5;i++) {
		printf("\a");
		printf("Ingresa tu nombre alumno numero %d:\t",(i+1));
		scanf("%s", &nombre_alumnos[i]);
		for (j=0; j<3; j++) {
			printf("%s ingresa la calificacion del parcial %d correspondiente a la materia de matematicas:\n\t\t",nombre_alumnos[i],(j+1));
			scanf("%f", &calificaciones[i][j]);
		}
		system("pause");
		system("cls");
	}
	float suma;
	for (i=0; i<5; i++) {
		suma = 0;
		for (j=0; j<3; j++) {
			suma = suma + calificaciones[i][j];
		}
		promedios[i] = suma / 3;
	}
	printf("\a");
	printf("*********** RESULTADOS *********** \n");
	system("pause");
	system("cls");
	for(i=0; i<5; i++) {
		printf("Alumno numero: %d \n",(i+1));
		printf("\t Nombre del alumno: %s \n",nombre_alumnos[i]);
		printf("\t Calificaciones: \n");
		for(j=0; j<3; j++) {
			printf("\t\t Parcial %d : %f \n", (j+1), calificaciones[i][j]);
		}
		printf("\t Promedio final: %f.2 \n \n \n", promedios[i]);
	}
}