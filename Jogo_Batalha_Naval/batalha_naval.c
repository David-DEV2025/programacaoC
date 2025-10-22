#include <stdio.h>

// -----------------------------------------------------------------------------
// DEFINIÇÕES GERAIS
// -----------------------------------------------------------------------------

#define TAM              10   // Tamanho do tabuleiro principal (10x10)
#define TAM_HAB           5   // Tamanho das matrizes de habilidade (5x5)
#define TAM_NAVIO         3   // Tamanho fixo dos navios (3 posições)

#define AGUA              0   // Célula vazia (sem navio nem habilidade)
#define NAVIO             3   // Célula com navio
#define AFETADO           5   // Célula afetada por habilidade

// Define se a habilidade sobrescreve navios
// 0 = preserva navio (mantém o valor 3)
// 1 = sobrescreve (substitui 3 por 5)
#define SOBREPOE_NAVIO    0

// -----------------------------------------------------------------------------
// FUNÇÃO: inicializar_tabuleiro
// Objetivo: preencher todo o tabuleiro com 0 (representando água).
// -----------------------------------------------------------------------------
void inicializar_tabuleiro(int tab[TAM][TAM]) {
    int i, j;
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            tab[i][j] = AGUA;
        }
    }
}

// -----------------------------------------------------------------------------
// FUNÇÃO: pode_posicionar
// Objetivo: verificar se é possível posicionar um navio no tabuleiro,
//           sem ultrapassar limites ou colidir com outro navio.
// Parâmetros:
//    tab[TAM][TAM] - matriz do tabuleiro
//    linha, coluna - posição inicial do navio
//    orientacao    - 'H' = horizontal, 'V' = vertical,
//                    'D' = diagonal principal ↘, 'I' = diagonal inversa ↙
// Retorno: 1 (pode posicionar), 0 (não pode)
// -----------------------------------------------------------------------------
int pode_posicionar(int tab[TAM][TAM], int linha, int coluna, char orientacao) {
    int i;
    for (i = 0; i < TAM_NAVIO; i++) {
        int li = linha;
        int co = coluna;

        // Define o deslocamento conforme a orientação
        if (orientacao == 'H') { 
            co = coluna + i;             // move horizontalmente →
        } else if (orientacao == 'V') { 
            li = linha + i;              // move verticalmente ↓
        } else if (orientacao == 'D') { 
            li = linha + i;              // diagonal ↘
            co = coluna + i;
        } else if (orientacao == 'I') { 
            li = linha + i;              // diagonal inversa ↙
            co = coluna - i;
        } else { 
            return 0;                    // orientação inválida
        }

        // Verifica se está dentro dos limites do tabuleiro
        if (li < 0 || li >= TAM || co < 0 || co >= TAM)
            return 0;

        // Verifica se a célula já está ocupada
        if (tab[li][co] != AGUA)
            return 0;
    }
    return 1;
}

// -----------------------------------------------------------------------------
// FUNÇÃO: posicionar_navio
// Objetivo: preencher no tabuleiro as posições do navio (valor = 3),
//           considerando que o posicionamento foi validado anteriormente.
// -----------------------------------------------------------------------------
void posicionar_navio(int tab[TAM][TAM], int linha, int coluna, char orientacao) {
    int i;
    for (i = 0; i < TAM_NAVIO; i++) {
        int li = linha;
        int co = coluna;

        if (orientacao == 'H') { 
            co = coluna + i; 
        } else if (orientacao == 'V') { 
            li = linha + i; 
        } else if (orientacao == 'D') { 
            li = linha + i; 
            co = coluna + i; 
        } else if (orientacao == 'I') { 
            li = linha + i; 
            co = coluna - i; 
        }

        tab[li][co] = NAVIO; // marca navio
    }
}

// -----------------------------------------------------------------------------
// FUNÇÃO: construir_hab_cone
// Objetivo: criar uma matriz 5x5 representando a forma de um CONE.
// Lógica: conforme a linha avança, a área (1) aumenta nas laterais.
// -----------------------------------------------------------------------------
void construir_hab_cone(int hab[TAM_HAB][TAM_HAB]) {
    int i, j, centro = TAM_HAB / 2;
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (j >= centro - i && j <= centro + i)
                hab[i][j] = 1;  // dentro da área do cone
            else
                hab[i][j] = 0;  // fora da área
        }
    }
}

// -----------------------------------------------------------------------------
// FUNÇÃO: construir_hab_cruz
// Objetivo: criar uma matriz 5x5 em forma de CRUZ (linha e coluna centrais).
// -----------------------------------------------------------------------------
void construir_hab_cruz(int hab[TAM_HAB][TAM_HAB]) {
    int i, j, centro = TAM_HAB / 2;
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (i == centro || j == centro)
                hab[i][j] = 1;  // forma a cruz
            else
                hab[i][j] = 0;
        }
    }
}

// -----------------------------------------------------------------------------
// FUNÇÃO: construir_hab_octaedro
// Objetivo: criar uma matriz 5x5 com formato de OCTAEDRO (ou losango).
// Lógica: distância de Manhattan (|i-c| + |j-c|) <= raio
// -----------------------------------------------------------------------------
void construir_hab_octaedro(int hab[TAM_HAB][TAM_HAB]) {
    int i, j, c = TAM_HAB / 2, raio = c;
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            int di = i - c; if (di < 0) di = -di;
            int dj = j - c; if (dj < 0) dj = -dj;

            if (di + dj <= raio)
                hab[i][j] = 1; // dentro do losango
            else
                hab[i][j] = 0; // fora
        }
    }
}

// -----------------------------------------------------------------------------
// FUNÇÃO: imprimir_habilidade
// Objetivo: exibir na tela a matriz da habilidade (para visualização).
// -----------------------------------------------------------------------------
void imprimir_habilidade(const char *titulo, int hab[TAM_HAB][TAM_HAB]) {
    int i, j;
    printf("%s\n", titulo);
    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            printf("%d ", hab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// -----------------------------------------------------------------------------
// FUNÇÃO: aplicar_habilidade
// Objetivo: sobrepor uma matriz de habilidade (5x5) no tabuleiro principal.
// Lógica: o centro da matriz é posicionado nas coordenadas (origem_l, origem_c).
// -----------------------------------------------------------------------------
void aplicar_habilidade(int tab[TAM][TAM], int hab[TAM_HAB][TAM_HAB],
                        int origem_l, int origem_c) {
    int i, j, centro = TAM_HAB / 2;

    for (i = 0; i < TAM_HAB; i++) {
        for (j = 0; j < TAM_HAB; j++) {
            if (hab[i][j] == 1) {  // apenas células ativas da habilidade
                int li = origem_l + (i - centro);
                int co = origem_c + (j - centro);

                // Garante que está dentro do tabuleiro
                if (li >= 0 && li < TAM && co >= 0 && co < TAM) {
#if SOBREPOE_NAVIO
                    tab[li][co] = AFETADO;           // sobrescreve o navio
#else
                    if (tab[li][co] == AGUA)          // apenas se for água
                        tab[li][co] = AFETADO;
#endif
                }
            }
        }
    }
}

// -----------------------------------------------------------------------------
// FUNÇÃO: imprimir_tabuleiro
// Objetivo: exibir o tabuleiro completo no console.
// -----------------------------------------------------------------------------
void imprimir_tabuleiro(int tab[TAM][TAM]) {
    int i, j;
    printf("Tabuleiro 10x10 (0=água, 3=navio, 5=afetado)\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%d ", tab[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// -----------------------------------------------------------------------------
// FUNÇÃO PRINCIPAL: main
// Responsável por:
// 1. Criar e inicializar o tabuleiro
// 2. Posicionar quatro navios (horizontal, vertical, diagonal e inverso)
// 3. Construir e exibir as 3 habilidades (CONE, CRUZ, OCTAEDRO)
// 4. Aplicar as habilidades em pontos específicos
// 5. Exibir o tabuleiro final
// -----------------------------------------------------------------------------
int main(void) {
    int tab[TAM][TAM];
    inicializar_tabuleiro(tab);

    // --------------------------
    // POSICIONAMENTO DOS NAVIOS
    // --------------------------
    int linhaH = 2, colunaH = 3; // horizontal
    int linhaV = 5, colunaV = 7; // vertical
    int linhaD = 0, colunaD = 6; // diagonal principal ↘
    int linhaI = 0, colunaI = 9; // diagonal inversa ↙

    if (!pode_posicionar(tab, linhaH, colunaH, 'H')) { printf("Falha H\n"); return 1; }
    posicionar_navio(tab, linhaH, colunaH, 'H');

    if (!pode_posicionar(tab, linhaV, colunaV, 'V')) { printf("Falha V\n"); return 1; }
    posicionar_navio(tab, linhaV, colunaV, 'V');

    if (!pode_posicionar(tab, linhaD, colunaD, 'D')) { printf("Falha D\n"); return 1; }
    posicionar_navio(tab, linhaD, colunaD, 'D');

    if (!pode_posicionar(tab, linhaI, colunaI, 'I')) { printf("Falha I\n"); return 1; }
    posicionar_navio(tab, linhaI, colunaI, 'I');

    // ---------------------------
    // CONSTRUÇÃO DAS HABILIDADES
    // ---------------------------
    int cone[TAM_HAB][TAM_HAB];
    int cruz[TAM_HAB][TAM_HAB];
    int octa[TAM_HAB][TAM_HAB];

    construir_hab_cone(cone);
    construir_hab_cruz(cruz);
    construir_hab_octaedro(octa);

    // Exibe as três matrizes de habilidade isoladamente
    imprimir_habilidade("Habilidade CONE (5x5):", cone);
    imprimir_habilidade("Habilidade CRUZ (5x5):", cruz);
    imprimir_habilidade("Habilidade OCTAEDRO (5x5):", octa);

    // ----------------------------------------
    // APLICAÇÃO DAS HABILIDADES NO TABULEIRO
    // ----------------------------------------
    aplicar_habilidade(tab, cone,  4, 2);  // Cone no quadrante superior
    aplicar_habilidade(tab, cruz,  5, 4);  // Cruz no meio
    aplicar_habilidade(tab, octa,  7, 2);  // Octaedro inferior

    // ------------------------------
    // EXIBIÇÃO FINAL DO TABULEIRO
    // ------------------------------
    imprimir_tabuleiro(tab);

    return 0;
}