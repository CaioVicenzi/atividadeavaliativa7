#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	float reais[50];
	int quantidadeAlunos;
	
	printf("Digite o número de alunos: ");
	scanf("%i", &quantidadeAlunos);
	
	if(quantidadeAlunos > 50 || quantidadeAlunos <= 0){
		printf("Valor inválido!");
		return 0;
	} 
	
	for(int i = 0; i < quantidadeAlunos; i++){
		printf("Digite a nota do aluno nº%i: ", i+1);
		scanf("%d", &reais[i]);
		fflush(stdin);		
	}
	
	printf("\n\nNotas recebidas!");
	
}
