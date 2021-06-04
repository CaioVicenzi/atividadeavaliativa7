#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int notas[80];
	int nota;
	int quantidadeNotas;
	int i;
	
	//Pedindo as notas dos alunos e armazenando elas na variável notas.
	printf("DIGITE UM NÚMERO MENOR QUE ZERO PARA FINALIZAR O CADASTRO DE NOTAS\n\n");
	for(i = 0; i<80; i++){
		while(true){
			printf("Digite a nota do aluno nº%i: ", quantidadeNotas + 1);
			scanf("%i", &nota);
			fflush(stdin);
			if(nota > 10) printf("Valor digitado é inválido, tente outro valor...\n");
				else break;
		}
		if(nota < 0) break;
		else if(nota <= 10){
			notas[i] = nota;
			quantidadeNotas++;
		}
	}
	
	int notasRegistradas[quantidadeNotas];
	int frequenciasRegistradas[quantidadeNotas];
		
	int contador;
	int notaEmQuestao;
	bool notaJaEstaRegistrada;
	int proximaPosicao =0;
	
	for(i = 0; i<quantidadeNotas; i++){
		notaJaEstaRegistrada = false;
		notaEmQuestao = notas[i];
		
		// Esse laço está procurando o valor da nota em questão dentro do vetor de notas já cadastradas, se ele encontrar,
		// então a nota em questão já existe e não precisa ser cadastrada novamente.
		for(int k = 0; k < proximaPosicao; k++)
			if(notaEmQuestao == notasRegistradas[k]) notaJaEstaRegistrada = true;

		// E se a nota em questão não está registrada ela deve ser registrada, na mesma posição que sua frequência no outro vetor.
		if(!notaJaEstaRegistrada){
			contador = 0;
			// Conta a frequência de determinada nota e armazena essa frequência na variável "contador"
			for(int j = 0; j < quantidadeNotas; j++)
				if(notaEmQuestao == notas[j]) contador++;
				
			notasRegistradas[proximaPosicao] = notaEmQuestao;
			frequenciasRegistradas[proximaPosicao] = contador;
			proximaPosicao++;
		}
	}
	
	// Imprimindo os resultados.
	printf("\n\n");
	printf("+------+------------+\n");
	printf("| NOTA | FREQUÊNCIA |\n");
	printf("+------+------------+\n");
	// eu escolhi usar a variável proximaPosicao porque ela possui o tamanho do vetor de notasRegistradas e frequenciasRegistradas.
	for(int a = 0; a<proximaPosicao; a++)
		printf("| %4i | %10i |\n", notasRegistradas[a], frequenciasRegistradas[a]);
	printf("+------+------------+\n");
}
