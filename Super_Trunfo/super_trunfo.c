#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código implementa a comparação entre duas cartas
// usando estruturas de decisão if e else.
// Atributo escolhido: PIB per Capita (maior vence)
// OBS: não há tratamento para empate (se os valores forem iguais, a Carta 2 vence)

#define ATRIBUTO_PIB_PER_CAPITA 1

int main() {
    // Declaração de variáveis das cartas (Novato e Aventureiro)
    char estado1, estado2;
    char codigo1[5], codigo2[5];
    char cidade1[30], cidade2[30];
    //int populacao1, populacao2; // movido do nível Novato para Nível Mestre
    int pontos1, pontos2;
    double area1, area2;
    double pib1, pib2; // entrada em bilhões

    // Declaração de variáveis das cartas (Mestre)
    unsigned long int populacao1, populacao2;
    
    // Nível Aventureiro
    double densidade1, densidade2;
    double pib_per_capita1, pib_per_capita2;

    // Nível Mestre
    double super1, super2;
            
    // Entrada de dados - carta 1
    printf("Cadastro da Carta 01\n");

    printf("Digite o Estado (uma letra de 'A' a 'H'): ");
    scanf(" %c", &estado1);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%4s", codigo1);

    printf("Digite o nome da Cidade (sem espaços): ");
    scanf("%29s", cidade1);
    
    printf("Digite o número de habitantes: ");
    scanf("%lu", &populacao1); // %lu para unsigned long int

    printf("Digite a área da cidade em km2: ");
    scanf("%lf", &area1);

    printf("Digite o PIB da Cidade (em bilhões de reais): ");
    scanf("%lf", &pib1);

    printf("Digite o número de pontos turísticos na cidade: ");
    scanf("%d", &pontos1);

    // Cálculos dos atributos derivados - Carta 1
    if (area1 > 0.0) {
        densidade1 = (double)populacao1 / area1;
    } else {
        densidade1 = 0.0;
    }

    if (populacao1 > 0) {
        pib_per_capita1 = (pib1 * 1000000000.0) / (double)populacao1;
    } else {
        pib_per_capita1 = 0.0;
    }

    if (densidade1 > 0.0) {
        super1 = (double)populacao1
               + area1
               + (pib1 * 1000000000.0)
               + (double)pontos1
               + pib_per_capita1
               + (1.0 / densidade1);
    } else {
        super1 = (double)populacao1
               + area1
               + (pib1 * 1000000000.0)
               + (double)pontos1
               + pib_per_capita1;
    }

    // Entrada de dados - carta 2
    printf("\nCadastro da Carta 02\n");

    printf("Digite o Estado (uma letra de 'A' a 'H'): ");
    scanf(" %c", &estado2);

    printf("Digite o código da carta (ex: B02): ");
    scanf("%4s", codigo2);

    printf("Digite o nome da Cidade (sem espaços): ");
    scanf("%29s", cidade2);

    printf("Digite o número de habitantes: ");
    scanf("%lu", &populacao2); // %lu para unsigned long int

    printf("Digite a área da cidade em km2: ");
    scanf("%lf", &area2);

    printf("Digite o PIB da Cidade (em bilhões de reais): ");
    scanf("%lf", &pib2);

    printf("Digite o número de pontos turísticos na cidade: ");
    scanf("%d", &pontos2);

    // Cálculos dos atributos derivados - Carta 2
    if (area2 > 0.0) {
        densidade2 = (double)populacao2 / area2;
    } else {
        densidade2 = 0.0;
    }

    if (populacao2 > 0) {
        pib_per_capita2 = (pib2 * 1000000000.0) / (double)populacao2;
    } else {
        pib_per_capita2 = 0.0;
    }

    if (densidade2 > 0.0) {
        super2 = (double)populacao2
               + area2
               + (pib2 * 1000000000.0)
               + (double)pontos2
               + pib_per_capita2
               + (1.0 / densidade2);
    } else {
        super2 = (double)populacao2
               + area2
               + (pib2 * 1000000000.0)
               + (double)pontos2
               + pib_per_capita2;
    }

    // Saída de dados - carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1);
    printf("Área: %.2f km2\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos1);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade1);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita1);
    printf("Super Poder: %.2f\n", super1); 

    // Saída de dados - carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %lu\n", populacao2);
    printf("Área: %.2f km2\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super2);

    // Comparacao Nível Novato
    // Atributo escolhido: PIB per Capita (maior vence)
    printf("\nComparacao de Cartas (Atributo: PIB per Capita)\n\n");
    printf("Carta 1 (%s): %.2f reais\n", cidade1, pib_per_capita1);
    printf("Carta 2 (%s): %.2f reais\n", cidade2, pib_per_capita2);

    if (pib_per_capita1 > pib_per_capita2) {
        printf("Resultado: Carta 1 (%s) venceu!\n", cidade1);
    } else {
        printf("Resultado: Carta 2 (%s) venceu!\n", cidade2);
    }
      
    return 0;
}