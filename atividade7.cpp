//	7. Desenvolva um algoritmo que cadastre os pre�os de at� 100 diferentes CDs em uma loja. Ap�s este
//cadastro, o algoritmo dever� possibilitar a execu��o de uma de duas fun��es para aumento dos pre�os
//cadastrados, sendo a primeira de 10% para todos os CDs, enquanto a segunda aumenta o percentual
//informado pelo vendedor para todos os CDs. Ser� o vendedor que escolher� o tipo de aumento desejado.
//Ap�s os c�lculos dever� ser apresentado o percentual de aumento e, para cada CD, o valor sem aumento e o
//valor com aumento.

#include<stdio.h>
#include<locale.h>
#include<stdlib.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	float precos[100];
	float precosAumentados[100];
	char desejaContinuar;
	float percentual;
	float preco;
	int quantidadeElementos = 0;
	
	printf("DIGITE UM N�MERO MENOR QUE ZERO PARA FINALIZAR O CADASTRO DE CDs \n\n");
	for(int i = 0; i<100; i++){
		printf("Digite o pre�o do CD: ");
		scanf("%f", &preco);
		fflush(stdin);
		
		if(preco < 0) break;
		else {
			precos[i] = preco;
			quantidadeElementos++;
		}
	}
	
	int opcao;
	
	system("CLS");
	printf("----- Menu Principal ------\n\n");
	printf("1 - Aumento de 10%% no pre�o de todos os discos\n");
	printf("2 - Aumento da porcentagem personalizada do pre�o de todos os discos\n");
	printf("3 - Sair do programa.\n\n");
	printf("Digite a sua op��o: ");
	scanf("%i", &opcao);
	printf("\n\n");
	
	if(opcao == 1)
		percentual = 10.00;
	else if(opcao == 2){
		printf("Digite o percentual que voc� quer aumentar no pre�o dos discos: ");
		scanf("%f", &percentual);
	} else if(opcao == 3) return 0;
	else printf("Op��o n�o identificada.");
	
	printf("\n\n");
	for(int contador = 0; contador < quantidadeElementos; contador++){
		precosAumentados[contador] = ((precos[contador] * percentual)/100) + precos[contador]; 
	}
	
	printf("-------- RESULTADO --------\n");
	printf("Percentual de aumento: %.2f%%\n\n", percentual);
	printf("Tabela de aumento:\n\n");
	
	printf("________________________________________\n");
	printf("| Pre�o inicial | Pre�o ap�s o aumento |\n");
	for(int j = 0; j<quantidadeElementos; j++){
		printf("| %13.2f | %20.2f |\n", precos[j], precosAumentados[j]);
	}
	printf("|_______________|______________________|");
}
