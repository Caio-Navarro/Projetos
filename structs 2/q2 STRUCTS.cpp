/*2. Crie uma STRUCT chamada Pessoa com os campos nome, idade e altura. Em seguida,
escreva um programa em C que solicita ao usuário que insira os dados de duas pessoas e os
exiba na tela.*/

#include <stdio.h>
#include <stdlib.h>

struct Pessoa{
	char nome[50];
	int idade;
	float altura;
};

int main(){
	struct Pessoa pessoas[2];
		
	for(int i = 0; i < 2; i++){
		system("cls");
		printf("Pessoa %d", i+1);
		fflush(stdin);
		printf("\nInforme seu nome: ");
		gets(pessoas[i].nome);
		
		printf("\nInforme sua idade: ");
		scanf("%d", &pessoas[i].idade);
		
		printf("\nInforme sua altura: ");
		scanf("%f", &pessoas[i].altura);
	}
	system("cls");
	for(int i = 0; i < 2; i++){
		printf("\n\nPessoa %d", i+1);
		printf("\nNome: %s", pessoas[i].nome);
		
		printf("\nIdade: %d", pessoas[i].idade);
		
		printf("\nAltura: %.2f", pessoas[i].altura);
	}
}
