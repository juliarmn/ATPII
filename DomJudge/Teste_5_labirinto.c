#include <stdio.h>
#include <stdlib.h>
#define m 25
//Primeiro fiz um como as n rainhas, com solucao, etc, entao adaptei
int matriz[m][m];
int primeira = 0;
// int solucao[m][m];
// é como as n rainhas
// void inicia_solucao() {
//   int i, j;
//   for (i = 0; i < m; i++) {
//     for (j = 0; j < m; j++) {
//       solucao[i][j] = 0;
//     }
//   }
// }

int valido(int N, int linha, int coluna) {
  if (linha >= 0 && coluna >= 0 && linha < N && coluna < N && matriz[linha][coluna] == 0) {
    return 1;
  }
  return 0;
}
void acha_solucao(int linha, int coluna, int quantos_passos, int N, int C) {
  if (linha == N - 1 && coluna == C && matriz[linha][coluna] == 0) {
    // solucao[linha][coluna] = 1;
    printf("%d\n", quantos_passos);
    exit(0);//Eu tive que perguntar pra alguem esse pedaco, o meu printava 2x, me falaram para usar exit(0)
  }
  if (!valido(N, linha, coluna)) {
    return;
  }
  // solucao[linha][coluna] = 1;
  matriz[linha][coluna] = 1;
  acha_solucao(linha + 1, coluna, quantos_passos + 1, N, C);
  acha_solucao(linha, coluna + 1, quantos_passos + 1, N, C);
  // acha_solucao(linha - 1, coluna, quantos_passos + 1, N, C);
  acha_solucao(linha, coluna - 1, quantos_passos + 1, N, C);
  // solucao[linha][coluna] = 0;
  return;
}

int main() {
  int N, I, C, i, passos = 0;
  // Nao consegui alocar dinamicamente
  scanf("%d", &N);
  scanf("%d", &I);
  scanf("%d", &C);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      scanf("%d", &matriz[i][j]);
    }
  }
  // inicia_solucao();
  acha_solucao(0, I, passos, N, C);
  printf("-1\n");
  return 0;
}
