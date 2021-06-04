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
		
		printf("Digite aqui a matrícula do funcionário: ");
		fgets(matriculaDigitada, 50, stdin);
		
		// Essa parte do código valida se existe um funcionário cadastrado com a matrícula digitada pelo usuário.
		for(i = 0; i<contador; i++){
			if(!strcmp(matriculaDigitada, matricula[i])){
				printf("Já existe um funcionário cadastrado com essa matrícula...\n\n");
				jaExisteFuncionario = true;
				break;
			} 
		}
		
		if(jaExisteFuncionario) continue;
		
		// Se o código nunca entrou na condição (matricula digitada = matricula uma das posições) a matrícula é única e pode
		// ser adicionada no vetor de matrículas digitadas.
		strcpy(matricula[contador], matriculaDigitada);
		
		printf("Agora, digite o salário desse funcionário: ");
		scanf("%f", &salario[contador]);
		fflush(stdin);
		if(salario[contador] < menorSalario) menorSalario = salario[contador];
		if(salario[contador] > maiorSalario) maiorSalario = salario[contador];
		
		printf("Deseja continuar cadastrando funcionários? (S -> sim, N -> não): ");
		scanf("%c", &querContinuar);
		fflush(stdin);
		contador++;
	}while(querContinuar == 'S' || contador >100);
	
	// Nesse ponto temos todos os usuários cadastrados em mãos, hora de limpar a tela e imprimir os dados.
	system("CLS");
	printf("+---------------------+\n");
	printf("| SALÁRIO | MATRÍCULA |\n");
	printf("+---------------------+\n");
	
	for(i= 0; i< contador; i++){
		printf("| %7f | %9s |\n", salario[i], matricula[i]);
	}
	printf("+---------------------+\n\n");
	
	printf("O maior salário é: %.2f\n", maiorSalario);
	printf("E o menor salário é: %.2f", menorSalario);
	
	//PS: Eu não separei por funções porque você não deixa usar coisas que você não ensinou em aula nas atividades.
	
}
