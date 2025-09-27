#include <stdio.h>

int main(){

    //int variavel;
    char variavel;

    printf("Digite um valor\n");
    //scanf("%d", &variavel);
    //scanf("%d", &variavel);

    scanf("%c", &variavel);

    switch (variavel) {
    //case 1:
        //printf("Código a ser executado se variável == 1\n");
        //printf("Teste do case 1\n");

    case 'a':    
        printf("Código a ser executado se variável == a\n");
        printf("Teste do case a\n");

    break; // Vai parar a execução
    //case 2:
        //printf("Código a ser executado se variável == 2\n");

    case 'b':
        printf("Código a ser executado se variável == b\n");
        
    break; // Vai parar a execução
    default:
        //printf("Código a ser executado se a variável não for 1 ou 2\n");
        printf("Código a ser executado se a variável não for a ou b\n");
    }
    
    return 0;
}