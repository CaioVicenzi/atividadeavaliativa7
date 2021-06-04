// 16. Ler um vetor A e B, cada um com 10 elementos. Gerar uma matriz C onde cada elemento corresponde a
//A + B. Pesquise um dado fornecido pelo usuário no vetor C.

#include<stdio.h>
#include<locale.h>


int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int contador;
	int a[10], b[10], c[10][10];
	
	printf("==== PREENCHENDO O VETOR A =====\n\n");
	for(contador = 0; contador < 10; contador++){
		printf("Digite a posição %i do vetor a: ", contador);
		scanf("%i", &a[contador]);
	}
	printf("\n\n");
	
	printf("==== PREENCHENDO O VETOR B =====\n\n");
	for(contador = 0; contador < 10; contador++){
		printf("Digite a posição %i do vetor b: ", contador);
		scanf("%i", &b[contador]);
	}
	printf("\n\n");		
	
	for(int i = 0; i<10; i++){
		for(int j = 0; j<10; j++){
			c[i][j] = a[i] + b[j];
		}
	}
	
	int linha, coluna;
	
	printf("==== APRESENTANDO O VETOR C ====\n\n");
	for(linha = 0; linha < 10; linha++){
		printf("[");
		for(coluna = 0; coluna<9; coluna++){
			printf("%3i, ", c[linha][coluna]);
		}
		printf("%3i]\n", c[linha][9]);
	}
	
	int valor, posicaoLinha, posicaoColuna;
	printf("\n\n");
	printf("Pesquise um valor: ");
	scanf("%i", &valor);
	
	for(linha = 0; linha < 10; linha++){
		for(coluna = 0; coluna<10; coluna++){
			if(c[linha][coluna] == valor){
				printf("O valor digitado aparece na linha %i e na coluna %i\n", linha, coluna);
			}
		}
	}
	
}
