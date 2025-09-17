#include <stdio.h>

int main(){
    /* Sintaxe do if em C:
    if (condicao){
        //bloco de codigo a ser executado se a condicao for verdadeira
        comando1
        comando2
    }
    */

    int numero1, numero2;
    
    numero1 = 5;
    numero2 = 5;

    if (numero1 > numero2){
        printf("Numero 1 é maior que Numero 2\n");        
    }

    printf("Fora do if\n");
    
    return 0;
}

