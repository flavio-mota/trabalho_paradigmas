/* Programa que acha todas as soluções do PROBLEMA DAS N RAINHAS:    */
/* determina todas as formas de dispor n rainhas num tabuleiro nxn   */
/* de modo que quaisquer duas delas não se ataquem.                  */

/*-------------------------------------------------------------------*/
/*   Se você descomentar as linhas com chamadas à função printf,     */
/*   o programa imprimirá toda a sequência de posições tentadas.     */
/*   Olhar essa sequência ajuda a entender a busca exaustiva e o     */
/*   backtracking.                                                   */
/*-------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#define FALSE   0
#define TRUE    1

void mostra_solucao(int n, int col_rainha[]);
void *mallocX(unsigned int nbytes);
void rainhas(int n);

int main(int argc, char *argv[])
{ 
    int n;

    if (argc == 1)  {
        printf("Uso: %s  <num_rainhas>\n", argv[0]);
        return 1;
    }
    n = atoi(argv[1]);
    if (n <= 0) {
        printf("O argumento deve ser um numero maior que zero.\n");
        return 1;
    }
    rainhas(n);
    return 0;
}       

void rainhas(int n)
{
    int *col_rainha;   /* col_rainha[k] e' a coluna da rainha na linha k */

    int *col_livre;    /* (col_livre[k] == TRUE) sse 
                          nao existe rainha na coluna k */

    int *diag_livre;   /* (diag_livre[k] == TRUE) sse 
                          nao existe rainha na diagonal principal k-n+1 */

    int *diag_p_livre; /* (diag_p_livre[k] == TRUE) sse 
                          nao existe rainha na diagonal principal k */

    int *diag_s_livre; /* (diag_s_livre[k] = TRUE) sse 
                          nao existe rainha na diagonal secundaria k */

    int lin, col, k, n_solucoes;
    int acabou;
    int achou_posicao; /* indicador de passagem */

    col_livre = mallocX(n * sizeof(int));
    diag_livre = mallocX((2 * n - 1) * sizeof(int));
    diag_s_livre = mallocX((2 * n - 1) * sizeof(int));
    diag_p_livre = diag_livre + n - 1; /* faz diag_p_livre apontar para o 
                                          meio do vetor diag_livre */
    col_rainha = mallocX(n * sizeof(int));

    for (k = 0; k < n; k++)
        col_livre[k] = TRUE;

    for (k = 0; k < 2 * n - 1; k++)  
        diag_livre[k] = diag_s_livre[k] = TRUE;
  
    lin = 0;  
    col = 0; 
    n_solucoes = 0;  
    acabou = FALSE;
    while (!acabou)   {
        achou_posicao = FALSE;
        while (col < n && !achou_posicao)  { 
            /* verifica se a posicao (lin, col) e' segura */
            if (col_livre[col] && diag_p_livre[lin - col] 
                               && diag_s_livre[lin + col]) {
                col_livre[col] = FALSE;
                diag_p_livre[lin - col] = FALSE;
                diag_s_livre[lin + col] = FALSE;
                col_rainha[lin] = col;
                achou_posicao = TRUE;
                /*printf("rainha em (%d, %d)\n", lin, col);*/
            }
            else {
                /*printf("          (%d, %d): posicao insegura\n", lin, col);*/
                col++;
            }
        }
        if (achou_posicao)  {
            if (lin != n - 1)  { 
                /* vamos tentar posicionar a proxima rainha */
                lin++;
                col = 0;
            }
            else  {  
                /* determinamos mais uma solucao */
                n_solucoes++; 
                mostra_solucao(n, col_rainha);

                /* retira a ultima rainha colocada 
                   para tentar encontrar uma outra solucao */
                col_livre[col] = TRUE;
                diag_p_livre[lin - col] = TRUE;
                diag_s_livre[lin + col] = TRUE;

                /* esta atribuicao forca um backtrack para a linha anterior */
                col = n;
            }
        }
        else  {
            /* coluna e' n */
            /* testamos todas as colunas para linha : fazer backtracking */
            if (lin == 0)  /* testamos todas as possibilidades */
                acabou = TRUE;
            else  {
                /* vamos tentar uma outra posicao 
                   para a rainha na linha anterior */
                lin--;
                /*printf("backtrack: volta para linha %d\n", lin);*/
                col = col_rainha[lin];
                col_livre[col] = TRUE;
                diag_p_livre[lin - col] = TRUE;
                diag_s_livre[lin + col] = TRUE;
                col++;
            }
        }
    }
    if (n_solucoes == 0) {
        printf("Nao ha' solucao para %d rainhas.\n", n);
    }
    free(col_rainha);
    free(col_livre);
    free(diag_livre);
    free(diag_s_livre);
}

void mostra_solucao(int n, int col_rainha[]) 
{
    static int conta = 0;
    int col, lin;

    printf("Solucao %i:\n", ++conta);
    for (lin = 0; lin < n; lin++) {
        for (col = 0; col < n; col++) {
            printf((col_rainha[lin] == col) ? "|R" : "|_");
        }
        printf("|\n");
    }
    printf("\n");
}

/* Funcao extraida das notas de aula do Prof. Paulo Feofillof */
void *mallocX(unsigned int nbytes)
{
    void *p;

    p = malloc(nbytes);
    if (p == NULL)  {
        printf("\nMemoria insuficiente\n");
        exit(EXIT_FAILURE);
    }
    return p;
}
