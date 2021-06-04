#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	int dados[100];
	
	for(int i = 0; i<100; i++){
		printf("Digite o próximo número: ");
		scanf("%i", &dados[i]);
	}
	
	int somatorio = 0;
	for(int j =0; j<100; j++){
		somatorio = somatorio + dados[j];
	}
	
	system("CLS");
	printf("A soma dos valores digitados é igual a %i", somatorio);
}

