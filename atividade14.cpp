#include<stdio.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int notas[80];
	int nota;
	int quantidadeNotas;
	int i;
	
	//Pedindo as notas dos alunos e armazenando elas na vari�vel notas.
	printf("DIGITE UM N�MERO MENOR QUE ZERO PARA FINALIZAR O CADASTRO DE NOTAS\n\n");
	for(i = 0; i<80; i++){
		while(true){
			printf("Digite a nota do aluno n�%i: ", quantidadeNotas + 1);
			scanf("%i", &nota);
			fflush(stdin);
			if(nota > 10) printf("Valor digitado � inv�lido, tente outro valor...\n");
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
		
		// Esse la�o est� procurando o valor da nota em quest�o dentro do vetor de notas j� cadastradas, se ele encontrar,
		// ent�o a nota em quest�o j� existe e n�o precisa ser cadastrada novamente.
		for(int k = 0; k < proximaPosicao; k++)
			if(notaEmQuestao == notasRegistradas[k]) notaJaEstaRegistrada = true;

		// E se a nota em quest�o n�o est� registrada ela deve ser registrada, na mesma posi��o que sua frequ�ncia no outro vetor.
		if(!notaJaEstaRegistrada){
			contador = 0;
			// Conta a frequ�ncia de determinada nota e armazena essa frequ�ncia na vari�vel "contador"
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
	printf("| NOTA | FREQU�NCIA |\n");
	printf("+------+------------+\n");
	// eu escolhi usar a vari�vel proximaPosicao porque ela possui o tamanho do vetor de notasRegistradas e frequenciasRegistradas.
	for(int a = 0; a<proximaPosicao; a++)
		printf("| %4i | %10i |\n", notasRegistradas[a], frequenciasRegistradas[a]);
	printf("+------+------------+\n");
}
