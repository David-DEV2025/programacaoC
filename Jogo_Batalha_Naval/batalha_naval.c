#include <stdio.h>

int main() {
    // Tabuleiro 5x5 (Novato)
    int tabuleiro[5][5];
    int i, j;

    // Inicializa com 0 (água)
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Tamanho fixo dos navios no Novato
    int tamanho = 3;

    // Coordenadas iniciais (ajuste conforme quiser testar)
    // Navio horizontal ocupa: (linhaH, colunaH), (linhaH, colunaH+1), (linhaH, colunaH+2)
    // Navio vertical   ocupa: (linhaV, colunaV), (linhaV+1, colunaV), (linhaV+2, colunaV)
    int linhaH = 1, colunaH = 1; // exemplo -> (1,1),(1,2),(1,3)
    int linhaV = 0, colunaV = 4; // exemplo -> (0,4),(1,4),(2,4)

    // ---- Valida limites ----
    // Horizontal cabe na linha?
    if (linhaH < 0 || linhaH >= 5 || colunaH < 0 || (colunaH + tamanho - 1) >= 5) {
        printf("Falha: navio horizontal sai do limite.\n");
        return 1;
    }
    // Vertical cabe na coluna?
    if (colunaV < 0 || colunaV >= 5 || linhaV < 0 || (linhaV + tamanho - 1) >= 5) {
        printf("Falha: navio vertical sai do limite.\n");
        return 1;
    }

    // ---- Verifica sobreposição antes de posicionar ----
    for (i = 0; i < tamanho; i++) {
        if (tabuleiro[linhaH][colunaH + i] != 0) {
            printf("Falha: sobreposição no navio horizontal.\n");
            return 1;
        }
        if (tabuleiro[linhaV + i][colunaV] != 0) {
            printf("Falha: sobreposição no navio vertical.\n");
            return 1;
        }
    }

    // ---- Posiciona para garantir checagem de sobreposição (interno ao Novato) ----
    for (i = 0; i < tamanho; i++) {
        tabuleiro[linhaH][colunaH + i] = 3; // marca internamente; saída oficial é em coordenadas
    }
    for (i = 0; i < tamanho; i++) {
        tabuleiro[linhaV + i][colunaV] = 3;
    }

    // ---- Saída oficial do Novato: coordenadas dos navios ----
    printf("Coordenadas do navio horizontal (tamanho %d):\n", tamanho);
    for (i = 0; i < tamanho; i++) {
        printf("(%d,%d)\n", linhaH, colunaH + i);
    }

    printf("\nCoordenadas do navio vertical (tamanho %d):\n", tamanho);
    for (i = 0; i < tamanho; i++) {
        printf("(%d,%d)\n", linhaV + i, colunaV);
    }

    return 0;
}