#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>

#define CARROS 7

char carro[20];
int carroEscolhido;

void menu();
void escolherCarro();

void corrigirAcentuacao(){
	setlocale(LC_ALL, "");
}

struct Tabela{
	int celta = 450;
	int classic = 450;
	int clio= 550;
	int sandero = 600;
	int gol = 600;
	int voyage = 600;
	int gas = 150;
} carros;

struct Pessoa{
	char nome[50];
	int cpf;
	int dia, mes, ano;
	int tempo = 1;
} info;

bool semInfo(){
	if(strcmp(info.nome, "")==0){
		return true;
	}else{
		return false;
	}
}

bool semCarro(){
	if(carroEscolhido == 0){
		return true;
	}else{
		return false;
	}
}

void informacoes(){
	fflush(stdin);
	printf("Informe seu nome completo: ");
	gets(info.nome);
	
	printf("\nInforme seu cpf: ");
	scanf("%d", &info.cpf);
	
	printf("\nInforme sua data de nascimento (dd mm aa): ");
	scanf("%d %d %d", &info.dia, &info.mes, &info.ano);
	
	if(info.ano > 2006){
		printf("\nVocê tem menos de 18 anos!\n");
		system("pause");
		system("cls");
		menu();
	}
}

void escolherCarro(){
	char gnv, alugar;
	bool encontrou = false;
	
	informacoes();
	system("cls");
	
	printf("Escolha um carro: ");
	scanf(" %s", carro);
	
	if(strcmp(carro, "celta")==0 || strcmp(carro, "classic")==0){
		system("cls");
		encontrou = true;
		carroEscolhido = carros.celta;
		
		printf("Nome do carro: %s\n", carro);
		printf("Preço: R$%d\n", carros.celta);
	}else if(strcmp(carro, "clio")==0){
		system("cls");
		encontrou = true;
		carroEscolhido = carros.clio;
		
		printf("Nome do carro: %s\n", carro);
		printf("Preço: R$%d\n", carros.clio);
	}else if(strcmp(carro, "sandero")==0 || strcmp(carro, "gol")==0 || strcmp(carro, "voyage")==0){
		system("cls");
		encontrou = true;
		carroEscolhido = carros.sandero;
		
		printf("Nome do carro: %s\n", carro);
		printf("Preço: R$%d\n", carros.sandero);
	}
	
	printf("Deseja alugar esse carro com GNV? [S/N]: ");
	scanf(" %c", &gnv);
	
	if(gnv == 'S' || gnv == 's'){
		carroEscolhido += carros.gas;
		printf("Preço final: R$%d\n", carroEscolhido);
	}else{
		carroEscolhido = carroEscolhido;
		printf("Preço final: R$%d\n", carroEscolhido);
	}
	
	printf("\nAlugar carro? [S/N]: ");
		scanf(" %c", &alugar);
		
		if(alugar == 'S' || alugar == 's'){
			printf("Carro alugado!\n");
			system("pause");
			system("cls");
			menu();
		}else{
			system("cls");
			printf("Operação cancelada.");
			system("pause");
			menu();
		}
	
	if(!encontrou){
		printf("Carro não encontrado! Escreva em minusculo e NÃO informe a marca!\n\n");
		escolherCarro();
	}
}

void tabelaPrecos(){
	printf("1- Chevrolet Celta - R$ 450/Semana\n\n");
	printf("2- Chevrolet Classic - R$ 450/Semana\n\n");
	printf("3- Renault Clio - R$ 550/Semana\n\n");
	printf("4- Renault Sandero - R$ 600/Semana\n\n");
	printf("5- Volkswagen Gol - R$ 600/Semana\n\n");
	printf("6- Volkswagen Voyage - R$ 600/Semana\n\n");
	printf("*Obs: Carro com gás + 150R$/Semana\n\n");
	system("pause");
}

void minhasInfo(){
	
	if(semInfo()){
		printf("\nSem informações!\n");
		system("pause");
		system("cls");
		menu();
	}else{
		printf("Nome: %s\n", info.nome);
		printf("CPF: %d\n", info.cpf);
		printf("Data de nascimento: %d/%d/%d\n", info.dia, info.mes, info.ano);
		printf("Carro alugado: %s\n", carro);
		printf("Tempo com carro: %d Semana(s)\n", info.tempo);
		system("pause");
	}
	
}

int calculoValor(int tempo){
	int valor;
	
	valor = tempo*carroEscolhido;
	return valor;
}

void devolverCarro(){
	char devolver;
	
	if(semCarro()){
		printf("\nVocê não tem um carro!\n");
		system("pause");
		system("cls");
		menu();
	}else{
		printf("Tempo com o carro: %d Semanas\n", info.tempo);
		printf("Valor a ser pago: R$%d\n", calculoValor(info.tempo));
		
		fflush(stdin);
		printf("Deseja devolver o carro? [S/N]: ");
		scanf(" %c", &devolver);
		
		if(devolver == 'S' || devolver == 's'){
			system("cls");
			printf("Carro devolvido!\n");
			carroEscolhido = 0;
			info.tempo = 0;
			carro[20] = ' ';
		}else{
			system("cls");
			menu();
		}
		
	}
}

void passarTempo(){
	int sair;
	
	if(semInfo()){
		printf("\nVocê precisa escolher um carro primeiro!\n");
		system("pause");
		system("cls");
		menu();
	}else{
		while(sair != 0){
			printf("1- Passar tempo / 0- Sair");
			printf("\nEscolha uma opção: ");
			scanf("%d", &sair);
			
			system("cls");
			printf("Tempo passado: %d Semanas\n", info.tempo);
			info.tempo++;
			
			if(sair == 0){
				info.tempo--;
				info.tempo--;
				system("cls");
				menu();
			}
		}
	}
	
}

void controleMenu(int opcao){
	switch(opcao){
		case 1:
			escolherCarro();
			break;
		case 2:
			devolverCarro();
			break;
		case 3:
			tabelaPrecos();
			break;
		case 4:
			minhasInfo();
			break;
		case 5:
			passarTempo();
			break;
		default:
			printf("Opção invalida!\n");
			menu();
	}
}

void menu(){
	int opcao;
	
	printf("---- Aluguel de Carros ----\n\n");
	printf("|1- Escolher carro\n");
	printf("|2- Devolver carro\n");
	printf("|3- Tabela de preços\n");
	printf("|4- Minhas informações\n");
	printf("|5- Passar o tempo\n");
	printf("|Escolha uma opção: ");
	scanf("%d", &opcao);
		
	system("cls");
	controleMenu(opcao);
}

int main(){
	corrigirAcentuacao();
		
	while(1){
		system("cls");
		fflush(stdin);
		menu();
	}	
}