#include <stdio.h>

int main(){

    int nota;

    printf("Digite a sua nota: ");
    scanf("%d", &nota);

    // A >= 90
    // B >= 80
    // C >= 70
    // D >= 60
    // E >= 50
    // F

    if (nota >= 90){
        printf("O conceito A!\n");
    } else if (nota >= 80){
        printf("O conceito é B!\n");
    } else if (nota >= 70){
        printf("O conceito é C!\n");
    } else if (nota >= 60){
        printf("O conceito é D!\n");
    } else if (nota >= 50){
        printf("O conceito é E!\n");
    } else {
        printf("O conceito é F!\n");
    }
}