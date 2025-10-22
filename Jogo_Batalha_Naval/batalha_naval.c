#include <stdio.h>

#define TAM       10   // tamanho do tabuleiro 10x10
#define TAM_NAVIO 3    // navio de tamanho 3
#define AGUA      0    // célula vazia
#define OCUPADO   3    // célula com navio

// Inicializa o tabuleiro com 0 (água)
void inicializar_tabuleiro(int tab[TAM][TAM]) {
    int linha, coluna;
    for (linha = 0; linha < TAM; linha++) {
        for (coluna = 0; coluna < TAM; coluna++) {
            tab[linha][coluna] = AGUA;
        }
    }
}

// Verifica se é possível posicionar um navio (tamanho fixo = 3)
// orientacao: 'H' (horizontal), 'V' (vertical),
//              'D' (diagonal principal ↘), 'I' (diagonal inversa ↙)
int pode_posicionar(int tab[TAM][TAM], int linha, int coluna, char orientacao) {
    int i;
    for (i = 0; i < TAM_NAVIO; i++) {
        int linhaAtual = linha;
        int colunaAtual = coluna;

        if (orientacao == 'H') {
            colunaAtual = coluna + i;
        } else if (orientacao == 'V') {
            linhaAtual = linha + i;
        } else if (orientacao == 'D') {         // ↘ (principal)
            linhaAtual = linha + i;
            colunaAtual = coluna + i;
        } else if (orientacao == 'I') {         // ↙ (inversa)
            linhaAtual = linha + i;
            colunaAtual = coluna - i;
        } else {
            return 0; // orientação inválida
        }

        // Limites
        if (linhaAtual < 0 || linhaAtual >= TAM || colunaAtual < 0 || colunaAtual >= TAM) {
            return 0;
        }
        // Sobreposição
        if (tab[linhaAtual][colunaAtual] != AGUA) {
            return 0;
        }
    }
    return 1; // pode posicionar
}

// Posiciona o navio assumindo que pode_posicionar == 1
void posicionar_navio(int tab[TAM][TAM], int linha, int coluna, char orientacao) {
    int i;
    for (i = 0; i < TAM_NAVIO; i++) {
        int linhaAtual = linha;
        int colunaAtual = coluna;

        if (orientacao == 'H') {
            colunaAtual = coluna + i;
        } else if (orientacao == 'V') {
            linhaAtual = linha + i;
        } else if (orientacao == 'D') {         // ↘
            linhaAtual = linha + i;
            colunaAtual = coluna + i;
        } else if (orientacao == 'I') {         // ↙
            linhaAtual = linha + i;
            colunaAtual = coluna - i;
        }

        tab[linhaAtual][colunaAtual] = OCUPADO;
    }
}

// Imprime o tabuleiro completo (0 = água, 3 = navio)
void imprimir_tabuleiro(int tab[TAM][TAM]) {
    int linha, coluna;
    for (linha = 0; linha < TAM; linha++) {
        for (coluna = 0; coluna < TAM; coluna++) {
            printf("%d ", tab[linha][coluna]); // padrão pedido no repositório
        }
        printf("\n");
    }
}

int main(void) {
    int tabuleiro[TAM][TAM];
    inicializar_tabuleiro(tabuleiro);

    // --- Coordenadas (ajuste livre para testes) ---
    // 1) Horizontal ↔: (2,3) (2,4) (2,5)
    int linhaH = 2, colunaH = 3;

    // 2) Vertical   ↕: (5,7) (6,7) (7,7)
    int linhaV = 5, colunaV = 7;

    // 3) Diagonal ↘ (principal): (0,0) (1,1) (2,2)
    int linhaD = 0, colunaD = 0;

    // 4) Diagonal ↙ (inversa): (0,9) (1,8) (2,7)
    int linhaI = 0, colunaI = 9;

    // --- Validação e posicionamento ---
    if (pode_posicionar(tabuleiro, linhaH, colunaH, 'H') == 0) { printf("Falha H\n"); return 1; }
    posicionar_navio(tabuleiro, linhaH, colunaH, 'H');

    if (pode_posicionar(tabuleiro, linhaV, colunaV, 'V') == 0) { printf("Falha V\n"); return 1; }
    posicionar_navio(tabuleiro, linhaV, colunaV, 'V');

    if (pode_posicionar(tabuleiro, linhaD, colunaD, 'D') == 0) { printf("Falha D\n"); return 1; }
    posicionar_navio(tabuleiro, linhaD, colunaD, 'D');

    if (pode_posicionar(tabuleiro, linhaI, colunaI, 'I') == 0) { printf("Falha I\n"); return 1; }
    posicionar_navio(tabuleiro, linhaI, colunaI, 'I');

    // --- Exibição completa do tabuleiro (0/3) ---
    imprimir_tabuleiro(tabuleiro);

    return 0;
}