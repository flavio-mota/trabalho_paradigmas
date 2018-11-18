/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Flavio
 */
public class nRainhas {
  private static int N = 10; //Define a quantidade de rainhas, deve ser maior ou igual a 4
  private static int[] solucao = new int[N]; //gera vetor de inteiros que irá armazenar a solução 
  private static int qtds = 0; //registra a quantidade de soluções possíveis
 
  
//Função que verifica se uma rainha pode ser atacada em uma determinada posição 
  static boolean ataque(int coluna) {
    int x = solucao[coluna]; //armazena a posição em que a rainha será inserida
    for (int i = 1; i <= coluna; i++) {//laço para verificar as posições anteriores  
      int t = solucao[coluna - i];//armazena as posições anteriores
      if (t == x ||
          t == x - i ||
          t == x + i) { //qualquer uma dessas condições indica que a rainha sofrerá um ataque
        return true; //retorna verdadeiro para ataque
      }
    }
 
    return false; //caso nenhuma das condições se satisfaça, a posição é segura, retorna falso para ataque
  }
 
  //Função que imprime uma solução
  public static void imprimeSolucao() {
    System.out.println("\n\nSolução " + (++qtds));
    for (int coluna = 0; coluna < N; coluna++) {
      for (int x = 0; x < N; x++) { //analisa as "colunas"
        System.out.print((solucao[coluna] == x) ? "|Q" : "|_"); //analisa as "linhas"
      }
      System.out.println("|");
    }
  }
 
  public static void main(String[] args) {
    int coluna = 0; //inicia na primeira "coluna" do "tabuleiro", primeira posição do vetor
    solucao[0] = -1; //valor -1 para solução na posição inicial do vetor
    while (coluna >= 0) { //laço utilizado para gerar as soluções
      do {
        solucao[coluna]++; //incrementa o valor armazenado na coluna que está sendo analisada
      } while ((solucao[coluna] < N) && ataque(coluna)); //realiza o incremento anterior enquanto não atingir o valor de N e a rainha sofrer ataques
      if (solucao[coluna] < N) { //testa se o valor encontrado é menor que N, sendo N o número de máximo do problema
        if (coluna < N-1) { //verifica se o valor de coluna está menor que N, sendo N o número de máximo do problema
          solucao[++coluna] = -1; //Se ainda houver soluções a serem geradas, incrementa o valor da coluna e atribui -1 a ele
        } else { 
          imprimeSolucao(); //caso contrário imprime a solução encontrada
        }
      } else { //Se for encontrado um valor de solução igual ao tamanho do problema, decrementa o valor da coluna.
        coluna--;
      }
    } //fim do laço de soluções
  }
}
