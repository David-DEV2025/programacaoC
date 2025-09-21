#include <stdio.h>

int main(){

    int a = 5;
    int b = 10;
    int c = 1;

    //if (a > 0 && b > 0)    
    //if (a || 0 && b > 0)   
    //if (!a)//(!(a > 0)
    //if (!(a > 0))

    // a > 0 => Verdadeiro
    // b < 0 => Falso
    // Verdadeiro && Falso => Falso
    // Falso || c == 0
    // Falso || Falso => Falso
        
        if (a > 0 && b < 0 || c == 0){
        printf("A Condição é verdadeira.\n");
    } else {
        printf("A condição é falsa.\n");        
    }
}