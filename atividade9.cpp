#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int idade;
	int idades[100];
	int somaIdades = 0, quantidadeIdades=0;
	float mediaIdades;
	int maiorIdade = 0;
	
	// Recebendo as idades, caso o usu�rio digite uma idade negativa, o programa para de pedir as idades e exibe o resultado
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
	
	// Esse la�o tenta conseguir duas informa��es: quantidade de vezes que a maior idade se repete e em quais posi��es
	for(int contador2 = 0; contador2 < quantidadeIdades; contador2++){
		// se a posi��o em quest�o tiver o mesmo valor de maiorIdade, ele salva essa posi��o no vetor vezesMaiorSeRepete
		// e ainda aumenta um numero na quantidade de vezes que o maior n�mero se repete.
		if(idades[contador2] == maiorIdade) {
			vezesMaiorSeRepete[quantidadeMaiorSeRepete] = contador2;
			quantidadeMaiorSeRepete++;
		}
	}
	
	mediaIdades = somaIdades / quantidadeIdades;
	
	// exibindo o resultado
	printf("+------ Resultado -------+\n\n");
	printf("M�dia das idades: %.2f\n", mediaIdades);
	printf("Maior idade: %i\n", maiorIdade);
	printf("A maior idade aparece nas posi��es: ");
	
	for(int j = 0; j<quantidadeMaiorSeRepete; j++)
		printf("%i, ", vezesMaiorSeRepete[j]);
	
}
