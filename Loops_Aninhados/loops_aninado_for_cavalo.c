#include <stdio.h>

int main (){

    int movimentoCompleto = 1; // Flag para controlar o movimento em 'L'

    while (movimentoCompleto--){
        for (int i = 0; i < 2; i++){
            printf("Cima\n"); // Imprime "Cima" duas vezes
        }
        printf("Direita\n"); // Imprime "Direita" uma vez
    }

    return 0;
}