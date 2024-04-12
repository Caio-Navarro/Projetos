/*Crie uma STRUCT chamada Data com os campos dia, mes e ano. Escreva um programa em C
que solicita ao usuário que insira duas datas e determine qual delas ocorreu primeiro.*/

#include <stdio.h>

struct Data{
	int dia, mes, ano;
};

int verificaData(Data dt1, Data dt2){
	if(dt1.ano > dt2.ano){
		return -1;
	}else if(dt1.ano < dt2.ano){
		return 1;
	}else if(dt1.mes > dt2.mes){
		return -1;
	}else if(dt1.mes < dt2.mes){
		return 1;
	}else if(dt1.dia > dt2.dia){
		return -1;
	}else if(dt1.dia < dt2.dia){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	Data dt1, dt2;
	printf("Informe dia, mes e ano: ");
	scanf("%d/%d/%d", &dt1.dia, &dt1.mes, &dt1.ano);
	
	printf("\nInforme dia, mes e ano: ");
	scanf("%d/%d/%d", &dt2.dia, &dt2.mes, &dt2.ano);
	
	int result = verificaData(dt1, dt2);
	if(result == 0){
		printf("As datas sao iguais");
	}else if(result == -1){
		printf("A data 1 eh maior");
	}else{
		printf("A data 2 eh maior");
	}
}
