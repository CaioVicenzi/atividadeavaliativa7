#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	char matricula[100][50];
	float salario[100];
	char querContinuar;
	int contador = 0;
	char matriculaDigitada[50];
	float maiorSalario = 0;
	float menorSalario = 999999999;
	int i;
	bool jaExisteFuncionario;
	
	do{		
		
		printf("Digite aqui a matr�cula do funcion�rio: ");
		fgets(matriculaDigitada, 50, stdin);
		
		// Essa parte do c�digo valida se existe um funcion�rio cadastrado com a matr�cula digitada pelo usu�rio.
		for(i = 0; i<contador; i++){
			if(!strcmp(matriculaDigitada, matricula[i])){
				printf("J� existe um funcion�rio cadastrado com essa matr�cula...\n\n");
				jaExisteFuncionario = true;
				break;
			} 
		}
		
		if(jaExisteFuncionario) continue;
		
		// Se o c�digo nunca entrou na condi��o (matricula digitada = matricula uma das posi��es) a matr�cula � �nica e pode
		// ser adicionada no vetor de matr�culas digitadas.
		strcpy(matricula[contador], matriculaDigitada);
		
		printf("Agora, digite o sal�rio desse funcion�rio: ");
		scanf("%f", &salario[contador]);
		fflush(stdin);
		if(salario[contador] < menorSalario) menorSalario = salario[contador];
		if(salario[contador] > maiorSalario) maiorSalario = salario[contador];
		
		printf("Deseja continuar cadastrando funcion�rios? (S -> sim, N -> n�o): ");
		scanf("%c", &querContinuar);
		fflush(stdin);
		contador++;
	}while(querContinuar == 'S' || contador >100);
	
	// Nesse ponto temos todos os usu�rios cadastrados em m�os, hora de limpar a tela e imprimir os dados.
	system("CLS");
	printf("+---------------------+\n");
	printf("| SAL�RIO | MATR�CULA |\n");
	printf("+---------------------+\n");
	
	for(i= 0; i< contador; i++){
		printf("| %7f | %9s |\n", salario[i], matricula[i]);
	}
	printf("+---------------------+\n\n");
	
	printf("O maior sal�rio �: %.2f\n", maiorSalario);
	printf("E o menor sal�rio �: %.2f", menorSalario);
	
	//PS: Eu n�o separei por fun��es porque voc� n�o deixa usar coisas que voc� n�o ensinou em aula nas atividades.
	
}
