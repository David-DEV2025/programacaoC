#include <stdio.h>

int main() {
    // ==================================
    // TORRE - usando estrutura FOR
    // ==================================
    printf("Movimento da TORRE:\n"); // Título do bloco
    // A Torre move-se em linha reta (horizontal ou vertical).
    // Neste exemplo, ela vai andar 5 casas para a direita.
    for (int i = 0; i < 5; i++) {
        printf("Direita\n"); // Imprime a direção do movimento
    }

    printf("\n"); // Linha em branco para separar as saídas

    // ==================================
    // BISPO - usando estrutura WHILE
    // ==================================
    printf("Movimento do BISPO:\n"); // Título do bloco
    // O Bispo move-se na diagonal. Aqui ele vai andar 5 casas
    // para cima e à direita (diagonal superior direita).
    int contadorBispo = 0;
    while (contadorBispo < 5) {
        printf("Cima Direita\n"); // Combinação de duas direções
        contadorBispo++;          // Incrementa o contador
    }

    printf("\n"); // Linha em branco para separar as saídas

    // ==================================
    // RAINHA - usando estrutura DO-WHILE
    // ==================================
    printf("Movimento da RAINHA:\n"); // Título do bloco
    // A Rainha move-se em todas as direções. Aqui ela vai andar
    // 8 casas para a esquerda.
    int contadorRainha = 0;
    do {
        printf("Esquerda\n"); // Imprime a direção do movimento
        contadorRainha++;     // Incrementa o contador
    } while (contadorRainha < 8);

    printf("\n"); // Linha em branco para separar as saídas

    // ==============================
    // CAVALO - usando loops ANINHADOS
    // ==============================
    printf("Movimento do CAVALO:\n"); // Título do bloco
    // O Cavalo move-se em 'L':
    // - duas casas em uma direção (aqui: para BAIXO)
    // - depois uma casa perpendicular (aqui: para a ESQUERDA)
    // Usaremos um loop while externo e um loop for interno

    int movimentoCompleto = 1; // Controla a execução do movimento em L

    while (movimentoCompleto--) {
        // Movimento vertical: duas casas para baixo
        for (int i = 0; i < 2; i++) {
            printf("Baixo\n");
        }

        // Movimento horizontal: uma casa para a esquerda
        printf("Esquerda\n");
    }

    return 0;
}