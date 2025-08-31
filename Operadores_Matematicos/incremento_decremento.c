#include <stdio.h>

int main(){
    /*
    Incremento (++)
    Pré-incremento ++a
    Pós-incremento a++
    Decremento (--)
    Pré-decremento --a
    Pós-decremento a--
    */
      
    int numero1 = 1, resultado;
    
    printf("Antes Incremento: %d\n", numero1);

    //Numero1 = numero1 +1;
    //Combinando operador de atribuição com aritmético: numero1 += 1;
    
    //Pós incremento:
    //resultado = numero1;
    //numero++;
           
    //numero1++;
    //printf("Após incremento: %d\n", numero1);

    resultado = numero1++;
    printf("Após pós-incremento - numero 1: %d - resultado: %d\n", numero1, resultado);
    
    resultado = ++numero1;
    printf("Após Pré-incremento - numero 1: %d - resultado: %d\n", numero1, resultado);

    //Numero1 = numero1 -1;
    //Combinando operador de atribuição com aritmético: numero1 -= 1;
    //numero1--;
    //printf("Após decremento: %d\n", numero1);

    resultado = numero1--;
    printf("Após Pós-decremento - numero 1: %d - resultado: %d\n", numero1, resultado);

    resultado = --numero1;
    printf("Após Pré-decremento - numero 1: %d - resultado: %d\n", numero1, resultado);

    return 0;
}