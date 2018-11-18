#include <stdio.h>
#include <stdlib.h>
//expressão que verifica se uma rainha estará sob ataque
#define ataque(i, j) (solucao[j] == i || abs(solucao[j] - i) == col - j)

int count = 0; //contador de soluções
void resolver(int n, int col, int *solucao) //funcão para resolver o problema das n-rainhas
{
    int i, j;
	if (col == n) { //caso base -> se o númedo de colunas for igual ao tamanho (n) do problema, então mostra a solução
		printf("\nSolucao no. %d\n-----\n", ++count);

        //laços alinhados para mostrar a solução no 'formato' do tabuleiro
		for (i = 0; i < n; i++, putchar('\n'))
			for (j = 0; j < n; j++)
				putchar(j == solucao[i] ? 'R' : ((i + j) & 1) ? '.' : '.');

		return;
	}

    //laços alinhados que tentam dispor as rainhas no tabuleiro através da verificação de ataque
	for (i = 0, j = 0; i < n; i++) {
		for (j = 0; j < col && !ataque(i, j); j++); //verifica se a rainha sofrerá ataque através da análise das colunas
		if (j < col) continue; //se o valor de j for menor que as colunas analisadas siginifica que a rainha está segura
                                //então sai do for e devolve para a chamada anterior

		solucao[col] = i; //atribui o valor de i no vetor de soluções. Esse valor representa em qual a linha rainha está sendo posicionada
		resolver(n, col + 1, solucao); //chamada recursiva da função resolver para iterar entre as colunas e verificar as soluções possíveis.
	}
}

int main(int n, char **argv)
{
	if (n <= 1 || (n = atoi(argv[1])) <= 0) n = 10; //verifica se algum número de rainhas (n) foi passado na chamada do programa, caso contrário assume valor 4
	int solucao[n]; //cria o vetor de soluções
	resolver(n, 0, solucao); //inicia solução
}
