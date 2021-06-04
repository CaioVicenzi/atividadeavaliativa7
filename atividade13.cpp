#include<stdio.h>
#include<locale.h>
#include<string.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	char frase[80];
	int caracteresEmBranco = 0, caracteresA = 0, caracteresa = 0;
	int i;
	char par[2];
	char par2[2];
	
	printf("Escreva a frase: ");
	fgets(frase, 80, stdin);
	int tamanhoFrase = strlen(frase);
	printf("Tamanho da frase: %i\n\n", tamanhoFrase);
	
	//Essa parte conta os caracteres em branco, os caracteres 'A' e os caracteres 'a'
	for(i = 0; i<tamanhoFrase; i++){
		switch(frase[i]){
			case ' ': caracteresEmBranco++; break;
			case 'A': caracteresA++; break;
			case 'a': caracteresa++; break;
		}
	}
	
	// Essa parte inteira serve para calcular o par que mais se repete dentro da string.
	int quantidadeVezesRepetiu = 0;
	int quantidadeDoQueMaisSeRepetiu = 0;
	char parQueMaisSeRepetiu[2];
	
	for(i = 0; i<tamanhoFrase; i++){
		quantidadeVezesRepetiu = 0;
		par[0] = frase[i];
		par[1] = frase[i+1];
		for(int j = 0; j<tamanhoFrase; j++){
			par2[0] = frase[j];
			par2[1] = frase[j+1];
			if(par[0] == par2 [0] && par[1] == par2[1]) quantidadeVezesRepetiu++;
		}
		
		if(quantidadeVezesRepetiu > quantidadeDoQueMaisSeRepetiu) {
			quantidadeDoQueMaisSeRepetiu = quantidadeVezesRepetiu;
			strcpy(parQueMaisSeRepetiu, par);
		}
	}
	
	printf("+----- RESULTADO ------+\n\n");
	printf("Existem, nessa frase:\n"); 
	printf("-> %i caractere(s) em branco\n", caracteresEmBranco);
	printf("-> %i caractere(s) 'A'\n", caracteresA);
	printf("-> %i caractere(s) 'a'\n", caracteresa);
	printf("-> O par de caracteres que mais se repetiu foi %c%c\n", parQueMaisSeRepetiu[0], parQueMaisSeRepetiu[1]);
	printf("|-> esse par se repetiu %i vezes", quantidadeDoQueMaisSeRepetiu);
	
		
}
