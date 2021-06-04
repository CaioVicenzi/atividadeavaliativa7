#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int idade;
	int idades[100];
	int somaIdades = 0, quantidadeIdades=0;
	float mediaIdades;
	int maiorIdade = 0;
	
	// Recebendo as idades, caso o usuário digite uma idade negativa, o programa para de pedir as idades e exibe o resultado
	printf("DIGITE UMA IDADE MENOR OU IGUAL A ZERO PARA FINALIZAR O CADASTRO DE IDADES \n\n");
	for(int i = 0; i<100; i++){
		printf("Digite a idade: ");
		scanf("%i", &idade);
		fflush(stdin);
		
		if(idade > 200){
			printf("Idade muito alta, tente outro valor...\n\n");
			continue;
		}
		if(idade <= 0) break;
		else {
			idades[i] = idade;
			quantidadeIdades++;
			somaIdades = somaIdades + idade;
			if(idade > maiorIdade) maiorIdade = idade;
		}
	}
	
	int vezesMaiorSeRepete [quantidadeIdades];	
	int quantidadeMaiorSeRepete = 0;
	
	// Esse laço tenta conseguir duas informações: quantidade de vezes que a maior idade se repete e em quais posições
	for(int contador2 = 0; contador2 < quantidadeIdades; contador2++){
		// se a posição em questão tiver o mesmo valor de maiorIdade, ele salva essa posição no vetor vezesMaiorSeRepete
		// e ainda aumenta um numero na quantidade de vezes que o maior número se repete.
		if(idades[contador2] == maiorIdade) {
			vezesMaiorSeRepete[quantidadeMaiorSeRepete] = contador2;
			quantidadeMaiorSeRepete++;
		}
	}
	
	mediaIdades = somaIdades / quantidadeIdades;
	
	// exibindo o resultado
	printf("+------ Resultado -------+\n\n");
	printf("Média das idades: %.2f\n", mediaIdades);
	printf("Maior idade: %i\n", maiorIdade);
	printf("A maior idade aparece nas posições: ");
	
	for(int j = 0; j<quantidadeMaiorSeRepete; j++)
		printf("%i, ", vezesMaiorSeRepete[j]);
	
}
