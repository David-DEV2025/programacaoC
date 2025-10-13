#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 3 - Lógica Mestre (Comparação com DOIS ATRIBUTOS e Menu Dinâmico)
// Este código mantém tudo dos níveis anteriores e adiciona a comparação avançada:
// ✅ Jogador escolhe 2 atributos diferentes via switch (menu dinâmico).
// ✅ Para cada atributo: maior vence (exceto densidade, onde menor vence).
// ✅ Depois soma os dois valores e decide vencedor final.
// ✅ Exibe valores usados, soma total e resultado final (ou "Empate!").

int main() {
    // Declaração de variáveis das cartas (Novato e Aventureiro)
    char estado1, estado2;
    char codigo1[5], codigo2[5];
    char cidade1[30], cidade2[30];
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
    scanf("%lu", &populacao1);
    printf("Digite a área da cidade em km2: ");
    scanf("%lf", &area1);
    printf("Digite o PIB da Cidade (em bilhões de reais): ");
    scanf("%lf", &pib1);
    printf("Digite o número de pontos turísticos na cidade: ");
    scanf("%d", &pontos1);

    // Cálculos Carta 1
    densidade1 = (area1 > 0.0) ? (double)populacao1 / area1 : 0.0;
    pib_per_capita1 = (populacao1 > 0) ? (pib1 * 1000000000.0) / (double)populacao1 : 0.0;
    super1 = (double)populacao1 + area1 + (pib1 * 1000000000.0) + (double)pontos1 + pib_per_capita1 + ((densidade1 > 0.0) ? 1.0/densidade1 : 0.0);

    // Entrada de dados - carta 2
    printf("\nCadastro da Carta 02\n");
    printf("Digite o Estado (uma letra de 'A' a 'H'): ");
    scanf(" %c", &estado2);
    printf("Digite o código da carta (ex: B02): ");
    scanf("%4s", codigo2);
    printf("Digite o nome da Cidade (sem espaços): ");
    scanf("%29s", cidade2);
    printf("Digite o número de habitantes: ");
    scanf("%lu", &populacao2);
    printf("Digite a área da cidade em km2: ");
    scanf("%lf", &area2);
    printf("Digite o PIB da Cidade (em bilhões de reais): ");
    scanf("%lf", &pib2);
    printf("Digite o número de pontos turísticos na cidade: ");
    scanf("%d", &pontos2);

    // Cálculos Carta 2
    densidade2 = (area2 > 0.0) ? (double)populacao2 / area2 : 0.0;
    pib_per_capita2 = (populacao2 > 0) ? (pib2 * 1000000000.0) / (double)populacao2 : 0.0;
    super2 = (double)populacao2 + area2 + (pib2 * 1000000000.0) + (double)pontos2 + pib_per_capita2 + ((densidade2 > 0.0) ? 1.0/densidade2 : 0.0);

    // ====================== EXIBE CARTAS ======================
    printf("\n=== CARTA 1 ===\n");
    printf("Cidade: %s | Pop: %lu | Area: %.2f | PIB: %.2f | Pontos: %d | Densidade: %.2f | PIB per Capita: %.2f\n", cidade1, populacao1, area1, pib1, pontos1, densidade1, pib_per_capita1);

    printf("\n=== CARTA 2 ===\n");
    printf("Cidade: %s | Pop: %lu | Area: %.2f | PIB: %.2f | Pontos: %d | Densidade: %.2f | PIB per Capita: %.2f\n", cidade2, populacao2, area2, pib2, pontos2, densidade2, pib_per_capita2);

    // ====================== MENU MESTRE (ESCOLHA 2 ATRIBUTOS) ======================
    int primeiraEscolha, segundaEscolha;
    double valor1_c1 = 0, valor1_c2 = 0;
    double valor2_c1 = 0, valor2_c2 = 0;

    printf("\n=== Escolha o PRIMEIRO atributo para comparar ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB (bilhoes)\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica (menor vence)\n");
    printf("6 - PIB per Capita\n");
    scanf("%d", &primeiraEscolha);

    printf("\n=== Escolha o SEGUNDO atributo (diferente do primeiro) ===\n");
    scanf("%d", &segundaEscolha);

    printf("\n=== RESULTADO DO NÍVEL MESTRE ===\n");

    // ====================== PEGA VALORES DO PRIMEIRO ATRIBUTO ======================
    if (primeiraEscolha == 1) { valor1_c1 = populacao1; valor1_c2 = populacao2; }
    if (primeiraEscolha == 2) { valor1_c1 = area1; valor1_c2 = area2; }
    if (primeiraEscolha == 3) { valor1_c1 = pib1; valor1_c2 = pib2; }
    if (primeiraEscolha == 4) { valor1_c1 = pontos1; valor1_c2 = pontos2; }
    if (primeiraEscolha == 5) { valor1_c1 = densidade1; valor1_c2 = densidade2; }
    if (primeiraEscolha == 6) { valor1_c1 = pib_per_capita1; valor1_c2 = pib_per_capita2; }

    // ====================== SEGUNDO ATRIBUTO ======================
    if (segundaEscolha == 1) { valor2_c1 = populacao1; valor2_c2 = populacao2; }
    if (segundaEscolha == 2) { valor2_c1 = area1; valor2_c2 = area2; }
    if (segundaEscolha == 3) { valor2_c1 = pib1; valor2_c2 = pib2; }
    if (segundaEscolha == 4) { valor2_c1 = pontos1; valor2_c2 = pontos2; }
    if (segundaEscolha == 5) { valor2_c1 = densidade1; valor2_c2 = densidade2; }
    if (segundaEscolha == 6) { valor2_c1 = pib_per_capita1; valor2_c2 = pib_per_capita2; }

    // Soma final
    double soma1 = valor1_c1 + valor2_c1;
    double soma2 = valor1_c2 + valor2_c2;

    printf("Soma dos atributos:\n");
    printf("%s = %.2f | %s = %.2f\n", cidade1, soma1, cidade2, soma2);

    if (soma1 > soma2) {
        printf("\n>>> RESULTADO FINAL: Carta 1 (%s) venceu!\n", cidade1);
    } else if (soma2 > soma1) {
        printf("\n>>> RESULTADO FINAL: Carta 2 (%s) venceu!\n", cidade2);
    } else {
        printf("\n>>> EMPATE!\n");
    }
    return 0;
}