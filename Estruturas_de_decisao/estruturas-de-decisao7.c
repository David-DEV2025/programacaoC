#include <stdio.h>

int main() {
    int numero;

    printf("Digite um número: \n");
    scanf("%d", &numero);

    if (numero > 0) {
        if (numero % 2 == 0) {
            printf("Número par\n");
        } else {
            printf("Número ímpar\n");
        }
    } else if (numero == 0) {
        printf("Número zero\n");
    } else {
        printf("Número negativo\n");
    }    
    return 0;
}