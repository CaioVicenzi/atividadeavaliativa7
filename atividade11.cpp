//11. Elabore um algoritmo que armazene o c�digo funcional inteiro e respectivo sal�rio real de todos os
//funcion�rios de uma empresa. Ap�s a leitura de todos os dados apresente o maior e o menor sal�rio entre
//todos funcion�rios da empresa, usando um subprograma para encontrar o maior e outro para encontrar o
//menor. Por fim, acione uma outra fun��o para calcular a m�dia salarial paga por esta empresa. O maior e
//menor sal�rio dever�o ser apresentados por um procedimento acionado pelo algoritmo principal. A m�dia
//salarial dever� ser apresentada por um procedimento acionado pela fun��o que calcula a m�dia.

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	int codigoFuncional[100];
	double salarios[100];
	int quantidadeFuncionarios = 0, matricula, i;
	bool mesmaMatricula;
	double salario;
	double menorSalario = 900000000;
	double maiorSalario = 0;
	double somaSalarios = 0;
	
	for(i = 0; i<100; i++){
		mesmaMatricula = false;
		
		printf("Digite a matr�cula do funcion�rio: ");
		scanf("%i", &matricula);		
		fflush(stdin);
		
		if(matricula == 0) break;
		
		for(int j = 0; j < quantidadeFuncionarios; j++)
			if(matricula == codigoFuncional[j]) mesmaMatricula = true;
			
		printf("Agora, digite o sal�rio do funcion�rio: ");
		scanf("%d", &salario);		
		fflush(stdin);

		if(!mesmaMatricula){
			salarios[quantidadeFuncionarios] = salario;
			codigoFuncional[quantidadeFuncionarios] = matricula;
			quantidadeFuncionarios++;
			if(salario > maiorSalario) maiorSalario = salario;
			if(salario < menorSalario) menorSalario = salario;
			somaSalarios = somaSalarios + salario;
		} else printf("ERRO: N�o consegui adicionar o funcion�rio pois sua matr�cula j� est� cadastrada...\n\n");
	}
	
	double mediaSalarial = somaSalarios / quantidadeFuncionarios;
	
	printf("O maior sal�rio � %d\n", maiorSalario);
	printf("E o menor sal�rio � %d\n", menorSalario);
	printf("A media salarial da empresa � igual a %d", mediaSalarial);
}
