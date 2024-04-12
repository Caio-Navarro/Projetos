/*Crie estruturas para armazenar as informações de Alunos e Professores.

Alunos:
Nome, CPF, data de nascimento, email, telefone, celular, estado, cidade, bairro, logradouro, matricula, curso

Professores:
Nome, CPF, data de nascimento, email, telefone, celular, estado, cidade, bairro, logradouro, registro, area*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[100];
	char cpf[15];
	char dataNascimento[12];	
} Pessoa;

typedef struct {
	char email[50];
	char telefone[15];
	char celular[12];	
} Contatos;

typedef struct {
	char estado[30];
	char cidade[50];
	char bairro[50];
	char logradouro[50];
} Endereco;

typedef struct {
	Pessoa dadosPessoais;
    Contatos contatos;
	Endereco endereco;
	char matricula[10];
	char curso[25];
} Aluno;

typedef struct {
	Pessoa dadosPessoais;
    Contatos contatos;
	Endereco endereco;
	char registro[10];
	char areaAtuacao[25];
} Professor;

int main (){
	Professor professores;
	Aluno alunos;
	
	printf(" *** CADASTRO DO ALUNO ***\n");
	printf("\nInfome o nome do aluno: ");
	gets(alunos.dadosPessoais.nome);
	
	printf("\nInfome o CPF do aluno: ");
	scanf("%s", alunos.dadosPessoais.cpf);
	
	printf("\nInfome a data de nasc. do aluno: ");
	scanf("%s", alunos.dadosPessoais.dataNascimento);
	
	fflush(stdin);
	printf("\nInfome o estado do aluno: ");
	gets(alunos.endereco.estado);
	
	printf("\nInfome a cidade do aluno: ");
	gets(alunos.endereco.cidade);
	
	printf("\nInfome o bairro do aluno: ");
	gets(alunos.endereco.bairro);
	
	printf("\nInfome o logradouro do aluno: ");
	gets(alunos.endereco.logradouro);
	
	printf("\nInfome a matricula do aluno: ");
	scanf("%s", alunos.matricula);
	
	printf("\nInfome o curso do aluno: ");
	gets(alunos.curso);
	
	system("cls");
	
	printf(" *** CADASTRO DO PROFESSOR ***\n");
	
	printf("\nInfome o nome do professor: ");
	gets(professores.dadosPessoais.nome);
	
	printf("\nInfome o cpf do professor: ");
	scanf("%s", professores.dadosPessoais.cpf);
	
	fflush(stdin);
	printf("\nInfome a data de nasc. do professor: ");
	gets(professores.dadosPessoais.dataNascimento);
	
	printf("\nInfome o estado do professor: ");
	gets(professores.endereco.estado);
	
	printf("\nInfome a cidade do professor: ");
	gets(professores.endereco.cidade);
	
	printf("\nInfome o bairro do professor: ");
	gets(professores.endereco.bairro);
	
	printf("\nInfome o logradouro do professor: ");
	gets(professores.endereco.logradouro);
	
	printf("\nInfome o registro do professor: ");
	scanf("%s", professores.registro);
	
	printf("\nInfome a area do professor: ");
	scanf("%s", professores.areaAtuacao);
	
	system("cls");
	printf("Obrigado pelo cadastro!!");
}