#include <stdio.h>

int main() {
    // ==================================
    // TORRE - usando estrutura FOR
    // ==================================
    // A Torre move-se em linha reta (horizontal ou vertical).
    // Neste exemplo, ela vai andar 5 casas para a direita.
    for (int i = 0; i < 5; i++) {
        printf("Direita\n"); // Imprime a direção do movimento
    }

    printf("\n"); // Linha em branco para separar as saídas

    // ==================================
    // BISPO - usando estrutura WHILE
    // ==================================
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
    // A Rainha move-se em todas as direções. Aqui ela vai andar
    // 8 casas para a esquerda.
    int contadorRainha = 0;
    do {
        printf("Esquerda\n"); // Imprime a direção do movimento
        contadorRainha++;     // Incrementa o contador
    } while (contadorRainha < 8);

    return 0;
}