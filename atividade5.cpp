#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int vetor[80];
	
	printf("Digite os valores que conter�o no vetor: ");
	for(int i = 0; i<80; i++)
		scanf("%i", &vetor[i]);
	
	system("CLS");
	printf("Qual n�mero voc� quer saber se cont�m na tabela? ");
	int numeroPerguntado;
	scanf("%i", &numeroPerguntado);
	int quantidadeVezesNumeroRepete = 0;
	
	for(int contador = 0; contador < 80; contador++)
		if(vetor[contador] == numeroPerguntado) quantidadeVezesNumeroRepete++;
	
	
	if(quantidadeVezesNumeroRepete == 0) printf("Esse n�mero n�o se repete.");
		else printf("Esse n�mero se repete %i vezes dentro desse vetor.", quantidadeVezesNumeroRepete);
	
	
}
