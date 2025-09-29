#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int opcao, regras;
    int numeroSecreto, palpite;

    printf("Menu Principal\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Ver Regras\n");
    printf("3. Sair\n");
    printf("Escolha uma opcao: \n");
    scanf("%d", &opcao);

    switch (opcao){
    case 1:
        srand(time(0));
        numeroSecreto = rand() % 10;
        printf("Digite um número de 0 a 9: \n");
        scanf("%d", &palpite);
        if (numeroSecreto == palpite){
            printf("Você Acertou!\n");
        } else {
            printf("Você Errou!\n");
        }                     
        break;
    case 2:
        printf("A explicação das regras!\n");
        printf("Digite a Opção relacionada as regras do jogo!\n");
        scanf("%d", &regras);
        switch (regras){
        case 1:
            printf("Regra 1");
        case 2:
            printf("Regra 2");
        }        
        break;
    case 3:
        printf("Saindo do Jogo!\n");        
        break;
        default:
        printf("Opção Inválida\n");
    }
    return 0;
}