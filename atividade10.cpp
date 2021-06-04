#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	char nome[100];
	char letra;
	int quantidadeLetras = 0;
	
	printf("DIGITE '#' QUANDO ACABAR O NOME.\n");
	for(int i = 0; i < 100; i++){
		printf("Digite a %iª letra do nome: ", 1+i);
		scanf("%c", &letra);
		fflush(stdin);
		if(letra == '#') break;
		else{
			nome[i] = letra;
			quantidadeLetras++;
		}
	}
	
	printf("\n\n");
	for(int j = 0; j < quantidadeLetras; j++){
		printf("%c", nome[j]);	
	}
}
