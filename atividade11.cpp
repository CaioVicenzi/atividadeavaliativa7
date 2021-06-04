//11. Elabore um algoritmo que armazene o código funcional inteiro e respectivo salário real de todos os
//funcionários de uma empresa. Após a leitura de todos os dados apresente o maior e o menor salário entre
//todos funcionários da empresa, usando um subprograma para encontrar o maior e outro para encontrar o
//menor. Por fim, acione uma outra função para calcular a média salarial paga por esta empresa. O maior e
//menor salário deverão ser apresentados por um procedimento acionado pelo algoritmo principal. A média
//salarial deverá ser apresentada por um procedimento acionado pela função que calcula a média.

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
		
		printf("Digite a matrícula do funcionário: ");
		scanf("%i", &matricula);		
		fflush(stdin);
		
		if(matricula == 0) break;
		
		for(int j = 0; j < quantidadeFuncionarios; j++)
			if(matricula == codigoFuncional[j]) mesmaMatricula = true;
			
		printf("Agora, digite o salário do funcionário: ");
		scanf("%d", &salario);		
		fflush(stdin);

		if(!mesmaMatricula){
			salarios[quantidadeFuncionarios] = salario;
			codigoFuncional[quantidadeFuncionarios] = matricula;
			quantidadeFuncionarios++;
			if(salario > maiorSalario) maiorSalario = salario;
			if(salario < menorSalario) menorSalario = salario;
			somaSalarios = somaSalarios + salario;
		} else printf("ERRO: Não consegui adicionar o funcionário pois sua matrícula já está cadastrada...\n\n");
	}
	
	double mediaSalarial = somaSalarios / quantidadeFuncionarios;
	
	printf("O maior salário é %d\n", maiorSalario);
	printf("E o menor salário é %d\n", menorSalario);
	printf("A media salarial da empresa é igual a %d", mediaSalarial);
}
