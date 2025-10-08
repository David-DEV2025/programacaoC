#include <stdio.h>

int mail (){

    int num1 = 40, num2 = 20;
    int maior;

    num1 > num2 ? (maior = num1) : (maior = num2);

    printf("O número maior é: %d", maior);

    return 0;

}