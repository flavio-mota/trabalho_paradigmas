#include <stdio.h>
#include <stdlib.h>
//express�o que verifica se uma rainha estar� sob ataque
#define ataque(i, j) (solucao[j] == i || abs(solucao[j] - i) == col - j)

int count = 0; //contador de solu��es
void resolver(int n, int col, int *solucao) //func�o para resolver o problema das n-rainhas
{
    int i, j;
	if (col == n) { //caso base -> se o n�medo de colunas for igual ao tamanho (n) do problema, ent�o mostra a solu��o
		printf("\nSolucao no. %d\n-----\n", ++count);

        //la�os alinhados para mostrar a solu��o no 'formato' do tabuleiro
		for (i = 0; i < n; i++, putchar('\n'))
			for (j = 0; j < n; j++)
				putchar(j == solucao[i] ? 'R' : ((i + j) & 1) ? '.' : '.');

		return;
	}

    //la�os alinhados que tentam dispor as rainhas no tabuleiro atrav�s da verifica��o de ataque
	for (i = 0, j = 0; i < n; i++) {
		for (j = 0; j < col && !ataque(i, j); j++); //verifica se a rainha sofrer� ataque atrav�s da an�lise das colunas
		if (j < col) continue; //se o valor de j for menor que as colunas analisadas siginifica que a rainha est� segura
                                //ent�o sai do for e devolve para a chamada anterior

		solucao[col] = i; //atribui o valor de i no vetor de solu��es. Esse valor representa em qual a linha rainha est� sendo posicionada
		resolver(n, col + 1, solucao); //chamada recursiva da fun��o resolver para iterar entre as colunas e verificar as solu��es poss�veis.
	}
}

int main(int n, char **argv)
{
	if (n <= 1 || (n = atoi(argv[1])) <= 0) n = 10; //verifica se algum n�mero de rainhas (n) foi passado na chamada do programa, caso contr�rio assume valor 4
	int solucao[n]; //cria o vetor de solu��es
	resolver(n, 0, solucao); //inicia solu��o
}
