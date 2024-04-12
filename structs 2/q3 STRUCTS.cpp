/*Crie uma STRUCT chamada Retangulo com os campos largura e altura. Em seguida, escreva
um programa em C que calcule e exiba a área de um retângulo com base nos valores
fornecidos pelo usuário.*/

#include <stdio.h>
#include <stdlib.h>

struct Retangulo{
	float largura, altura;
} retangulo;

int main(){
	float calculoArea;
	
	printf("Informe a largura do triangulo: ");
	scanf("%f", &retangulo.largura);
	
	printf("\nInforme a altura do triangulo: ");
	scanf("%f", &retangulo.altura);
	
	system("cls");
	
	calculoArea = retangulo.largura*retangulo.altura;
	
	printf("Area do triangulo: %.2f", calculoArea);
}
