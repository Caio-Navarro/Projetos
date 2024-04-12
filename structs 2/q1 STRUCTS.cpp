/*1. Criar uma STRUCT com os seguintes elementos:

? Nome
? Idade
? Tel
? E-mail
? Usuário
? Senha
a. Permitir cadastro apenas maiores de idade
b. Verificar se usuário e senha possuem 8 dígitos
c. Lista as informações cadastradas*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define MAX_NOME 50
#define MAX_TELEFONE 12
#define MAX_EMAIL 50
#define MAX_USUARIO 30
#define MAX_SENHA 30

struct Cadastro{
	char nome[MAX_NOME], email[MAX_EMAIL], usuario[MAX_USUARIO], senha[MAX_SENHA];
	int idade, telefone[MAX_TELEFONE];
	
} cadastros;

bool menorIdade(){
	if(cadastros.idade < 18){
		return true;
	}else{
		return false;
	}
}
void tentarDnv();

bool usuarioSenha(){
	int contarDigitosUsuario(strlen(cadastros.usuario));
	int contarDigitosSenha(strlen(cadastros.senha));
	
	if(contarDigitosUsuario <8){
		return true;
	}else if(contarDigitosSenha <8){
		return true;
	}else{ 
		return false;
	}
}

void cadastroUsuario(){
	char tentarNovamente;
	
	do{
		fflush(stdin);
		printf("Escolha um nome de usuário (MAX 20 CARACTERES): ");
		gets(cadastros.usuario);
		
		printf("\nEscolha uma senha: (MAX 20 CARACTERES): ");
		gets(cadastros.senha);
		
		if(usuarioSenha()){
			printf("\nSeu usuario e senha precisam ter no min 8 caracteres!");
			fflush(stdin);
			tentarDnv();
		}
	}while(tentarNovamente == 's' || tentarNovamente == 'S');
}

void tentarDnv(){
	char repetir;
	
	fflush(stdin);
	printf("\nDeseja tentar novamente? [S/N]: ");
	scanf("%c", &repetir);
	if(repetir == 's'){
		system("cls");
		fflush(stdin);
		cadastroUsuario();
	}
}

void listarInformacoes(){
	system("cls");
	printf("Informações cadastradas: \n");
	printf("\nNome: %s", cadastros.nome);
	printf("\nIdade: %d", cadastros.idade);
	printf("\nTelefone: %d", cadastros.telefone);
	printf("\nEmail: %s", cadastros.email);
	printf("\nUsuario: %s", cadastros.usuario);
	printf("\nSenha: %s", cadastros.senha);
}

void cadastroPrincipal(){
	
	printf("### Cadastro ###\n\n");
	printf("Informe seu nome: ");
	gets(cadastros.nome);
	
	printf("\nInforme sua idade: ");
	scanf("%d", &cadastros.idade);
	
	if(menorIdade()){
		printf("\nVocê precisa ter mais de 18 anos para realizar seu cadastro!");
		abort();
	}
	
	printf("\nInforme seu telefone (ex: 75123456789): ");
	scanf("%d", &cadastros.telefone);
	
	fflush(stdin);
	printf("\nInforme seu email: ");
	gets(cadastros.email);
	
	system("cls");
	printf("Tudo certo por enquanto!\n");
	system("pause");
	
	system("cls");
	
	cadastroUsuario();
	system("pause");
	listarInformacoes();
}

int main(){
	setlocale(LC_ALL, "");
	cadastroPrincipal();
}