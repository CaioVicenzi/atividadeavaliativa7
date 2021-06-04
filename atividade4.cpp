#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	char letras[30];
	char letra;
	int contadorLetras = 0;

	printf("Digite o proximo caracter (aperte '.' para terminar): ");
	for(int i = 0; i<30; i++){
		
		scanf("%c", &letra);
		contadorLetras++;
		if(letra == '.') break;
			else letras[i] = letra;
		
		printf("-> ");
		
	}
	
	printf("\n\n");
	for(int j = contadorLetras; j>=0; j--)
		printf("%c", letras[j]);
	
}
