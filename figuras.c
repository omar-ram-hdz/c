#include <stdlib.h>
#include <stdio.h>
#define PI 3.1416

float perimetro_cuadrado(int n) {
	return n * 4;
}

float area_cuadrado(int n) {
	return n * n;
}

float perimetro_rectangulo(int b, int h) {
	return (b*2) + (h* 2);
}

float area_rectangulo(int b, int h) {
	return b * h;
}

float perimetro_triangulo(int n) {
	return n * 3;
} 

float area_triangulo(int b, int h) {
	return (b*h);
}



float perimetro_circulo(int d) {
	return (PI*d);
}

float area_circulo(int r) {
	int res = (PI * r);
	
	return res * res;
}



float perimetro_poligono(int n, int l) {
	return n * l;
}

float area_poligono(int n, int l, int a) {
	float p = perimetro_poligono(n,l);
	return (p*a)/2;
}



float area_trapecio(int B, int b, int h) {
	return (h * (B * b)) / 2;
}

float perimetro_trapecio(int B, int b, int l) {
	return B + b + (l*2);
}



void main() {
	printf("\a");
	printf("*********** INICIO DEL PROGRAMA *********** \n");
	printf("Al entrar a el programa tienes que tener en cuenta que...\n");
	printf("1. No se manejan unidades de medida, solo numeros, es decir 4m pasa a ser 4 etc.\n");
	printf("2. El programa no se hace responsable de errores del usuario\n");
	system("pause");
	system("cls");
	
	
	int option, operation;
	do{
		printf("Catalogo:\n");
		printf("\t 1. Cuadrado\n");
		printf("\t 2. Rectangulo\n");
		printf("\t 3. Triangulo\n");
		printf("\t 4. Trapecio\n");
		printf("\t 5. Circulo\n");
		printf("\t 6. Poligono (mas de 4 lados)\n");
		printf("Selecciona la opcion que quieres: ");
		scanf("%d", &option);
		printf("Que operacion deseas realizar\n");
		printf("\t 1. Area \n");
		printf("\t 2. Perimetro \n");
		scanf("%d",&operation);
		if(operation >= 3 && operation <= 0) {
			printf("Datos incorrectos, vuelve a intentarlo");
			break;
		}
		switch(option) {
			case 1 : {
				int l;
				printf("Ingresa el valor de uno de sus lados: \t");
				scanf("%d",&l);
				if(operation == 1) {
					printf("Area: %f.2",area_cuadrado(l));
				}else{
					printf("Perimetro %f.2",perimetro_cuadrado(l));
				}
				break;
			}
			case 2 : {
				int b, h;
				printf("Ingresa el valor de la base: \t");
				scanf("%d",&b);
				printf("Ingresa el valor de la altura: \t");
				scanf("%d",&h);
				if(operation == 1) {
					printf("Area: %f.2", area_rectangulo(b,h));
				}else{
					printf("Perimetro: %f.2", perimetro_rectangulo(b,h));
				}
				break;
			}
			case 3 : {
				if(operation == 1) {
					int b, h;
					printf("Ingresa la base: \t");
					scanf("%d",&b);
					printf("Ingresa la altura: \t");
					scanf("%d",&h);
					printf("Area: %f.2",area_triangulo(b,h));
				}else{
					int l;
					printf("Ingresa el valor del lado: \t");
					scanf("%d", &l);
					printf("Perimetro: %f.2",perimetro_triangulo(l));
				}
				break;
			}
			case 4 : {
				int B,b;
				printf("Ingresa el valor de la base menor: \t");
				scanf("%d",&b);
				printf("Ingresa el valor de la base mayor: \t");
				scanf("%d",&B);
				if(operation == 1) {
					int h;
					printf("Ingresa la altura: \t");
					scanf("%d",&h);
					printf("Area: %f.2",area_trapecio(B,b,h));
				}else{
					int l;
					printf("Ingresa el valor del lado: \t");
					scanf("%d",&l);
					printf("Perimetro: %f.2", perimetro_trapecio(B,b,l));
				}
				break;
			}
			case 5 : {
				int r;
				printf("Ingresa el radio: \t");
				scanf("%d",&r);
				if(operation == 1) {
					printf("Area: %f.2",area_circulo(r));
				}else{
					printf("Perimetro: %f.2",perimetro_circulo((r*2)));
				}
				break;
			}
			case 6 : {
				int l,v;
				printf("Ingresa el numero de lados del poligono: \t");
				scanf("%d",&l);
				printf("Ingresa el valor de sus lados: \t");
				scanf("%d",&v);
				if(operation == 1) {
					int a;
					printf("Ingresa el valor del apotema: \t");
					scanf("%d",&a);
					printf("Area: %f.2", area_poligono(l,v,a));
				}else{
					printf("Perimetro: %f.2", perimetro_poligono(l,v));
				}
				break;
			}
			default : {
				printf("Opcion incorrecta... intentalo denuevo");
				break;
			}
			printf("\n");
		}
		int res = 0;
		printf("Deseas volver a calcular\n 1. Si \n 2. No \n");
		scanf("%d",&res);
		if(res != 1 ) {
			break;
		}
	}while(1 == 1);
}