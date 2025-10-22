#include <stdio.h>

int main() {
    int board[10][10];
    int i, j;

    // Inicializa o tabuleiro com 0 (água)
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            board[i][j] = 0;
        }
    }

    // Vetores para representar os navios (tamanho 3)
    int navioHorizontal[3] = {3, 3, 3};
    int navioVertical[3] = {3, 3, 3};

    // Coordenadas iniciais fixas
    int linhaH = 2, colunaH = 3;
    int linhaV = 5, colunaV = 7;

    // Posiciona navio horizontal
    for (i = 0; i < 3; i++) {
        board[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // Posiciona navio vertical
    for (i = 0; i < 3; i++) {
        board[linhaV + i][colunaV] = navioVertical[i];
    }

    // Exibe o tabuleiro
    printf("Tabuleiro de Batalha Naval:\n\n");
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}