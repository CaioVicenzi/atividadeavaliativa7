#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	float reais[30];
	
	for(int i = 0; i < 30; i++){
		printf("Digite a nota do aluno nº%i: ", i+1);
		scanf("%d", &reais[i]);
		fflush(stdin);
	}
	
	printf("\n\nNotas recebidas!");
	
}
