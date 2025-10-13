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
    super1 = (double)populacao1
           + area1
           + (pib1 * 1000000000.0)
           + (double)pontos1
           + pib_per_capita1
           + ((densidade1 > 0.0) ? 1.0/densidade1 : 0.0);

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
    super2 = (double)populacao2
           + area2
           + (pib2 * 1000000000.0)
           + (double)pontos2
           + pib_per_capita2
           + ((densidade2 > 0.0) ? 1.0/densidade2 : 0.0);

    // ====================== EXIBE CARTAS ======================
    printf("\n=== CARTA 1 ===\n");
    printf("Cidade: %s | Pop: %lu | Area: %.2f | PIB: %.2f | Pontos: %d | Densidade: %.2f | PIB per Capita: %.2f\n",
           cidade1, populacao1, area1, pib1, pontos1, densidade1, pib_per_capita1);

    printf("\n=== CARTA 2 ===\n");
    printf("Cidade: %s | Pop: %lu | Area: %.2f | PIB: %.2f | Pontos: %d | Densidade: %.2f | PIB per Capita: %.2f\n",
           cidade2, populacao2, area2, pib2, pontos2, densidade2, pib_per_capita2);

    // ====================== MENU MESTRE (ESCOLHA 2 ATRIBUTOS) ======================
    int primeiraEscolha, segundaEscolha;

    // valores brutos por atributo (sem inversão)
    double a1_c1 = 0.0, a1_c2 = 0.0;
    double a2_c1 = 0.0, a2_c2 = 0.0;

    // valores ajustados para a soma (densidade entra como 1/densidade)
    double s1_c1 = 0.0, s1_c2 = 0.0;
    double s2_c1 = 0.0, s2_c2 = 0.0;

    // ===== Menu 1 (switch) =====
    printf("\n=== Escolha o PRIMEIRO atributo ===\n");
    printf("1 - Populacao (maior vence)\n");
    printf("2 - Area (maior vence)\n");
    printf("3 - PIB (bilhoes) (maior vence)\n");
    printf("4 - Pontos Turisticos (maior vence)\n");
    printf("5 - Densidade Demografica (MENOR vence)\n");
    printf("6 - PIB per Capita (maior vence)\n");
    printf("Opcao: ");
    scanf("%d", &primeiraEscolha);

    switch (primeiraEscolha) {
        case 1: a1_c1 = (double)populacao1; a1_c2 = (double)populacao2; break;
        case 2: a1_c1 = area1;               a1_c2 = area2;               break;
        case 3: a1_c1 = pib1;                a1_c2 = pib2;                break;
        case 4: a1_c1 = (double)pontos1;     a1_c2 = (double)pontos2;     break;
        case 5: a1_c1 = densidade1;          a1_c2 = densidade2;          break;
        case 6: a1_c1 = pib_per_capita1;     a1_c2 = pib_per_capita2;     break;
        default:
            printf("\nOpcao invalida.\n");
            return 0;
    }

    // ===== Menu 2 (dinâmico) — esconder a primeira escolha =====
    printf("\n=== Escolha o SEGUNDO atributo (diferente do primeiro) ===\n");
    if (primeiraEscolha != 1) printf("1 - Populacao (maior vence)\n");
    if (primeiraEscolha != 2) printf("2 - Area (maior vence)\n");
    if (primeiraEscolha != 3) printf("3 - PIB (bilhoes) (maior vence)\n");
    if (primeiraEscolha != 4) printf("4 - Pontos Turisticos (maior vence)\n");
    if (primeiraEscolha != 5) printf("5 - Densidade Demografica (MENOR vence)\n");
    if (primeiraEscolha != 6) printf("6 - PIB per Capita (maior vence)\n");
    printf("Opcao: ");
    scanf("%d", &segundaEscolha);

    // validar diferente
    if (segundaEscolha == primeiraEscolha) {
        printf("\nOpcao invalida: o segundo atributo deve ser diferente do primeiro.\n");
        return 0;
    }

    switch (segundaEscolha) {
        case 1: a2_c1 = (double)populacao1; a2_c2 = (double)populacao2; break;
        case 2: a2_c1 = area1;               a2_c2 = area2;               break;
        case 3: a2_c1 = pib1;                a2_c2 = pib2;                break;
        case 4: a2_c1 = (double)pontos1;     a2_c2 = (double)pontos2;     break;
        case 5: a2_c1 = densidade1;          a2_c2 = densidade2;          break;
        case 6: a2_c1 = pib_per_capita1;     a2_c2 = pib_per_capita2;     break;
        default:
            printf("\nOpcao invalida.\n");
            return 0;
    }

    printf("\n=== RESULTADO DO NIVEL MESTRE ===\n");

    // ===== Comparacao do 1º atributo (imprime vencedor por atributo) =====
    printf("\n[Atributo 1]\n");
    // rótulo textual do atributo 1
    if (primeiraEscolha == 1) printf("Populacao\n");
    if (primeiraEscolha == 2) printf("Area (km2)\n");
    if (primeiraEscolha == 3) printf("PIB (bilhoes)\n");
    if (primeiraEscolha == 4) printf("Pontos Turisticos\n");
    if (primeiraEscolha == 5) printf("Densidade (hab/km2)\n");
    if (primeiraEscolha == 6) printf("PIB per Capita (R$)\n");

    printf("%s: %.2f  |  %s: %.2f\n", cidade1, a1_c1, cidade2, a1_c2);

    if (primeiraEscolha == 5) { // densidade: MENOR vence
        if (a1_c1 < a1_c2)      printf("Vencedor no Atributo 1: %s (densidade menor)\n", cidade1);
        else if (a1_c2 < a1_c1) printf("Vencedor no Atributo 1: %s (densidade menor)\n", cidade2);
        else                    printf("Atributo 1: Empate!\n");
        s1_c1 = (densidade1 > 0.0) ? 1.0/densidade1 : 0.0;
        s1_c2 = (densidade2 > 0.0) ? 1.0/densidade2 : 0.0;
    } else { // demais: MAIOR vence
        if (a1_c1 > a1_c2)      printf("Vencedor no Atributo 1: %s\n", cidade1);
        else if (a1_c2 > a1_c1) printf("Vencedor no Atributo 1: %s\n", cidade2);
        else                    printf("Atributo 1: Empate!\n");
        s1_c1 = a1_c1;
        s1_c2 = a1_c2;
    }

    // ===== Comparacao do 2º atributo (imprime vencedor por atributo) =====
    printf("\n[Atributo 2]\n");
    // rótulo textual do atributo 2
    if (segundaEscolha == 1) printf("Populacao\n");
    if (segundaEscolha == 2) printf("Area (km2)\n");
    if (segundaEscolha == 3) printf("PIB (bilhoes)\n");
    if (segundaEscolha == 4) printf("Pontos Turisticos\n");
    if (segundaEscolha == 5) printf("Densidade (hab/km2)\n");
    if (segundaEscolha == 6) printf("PIB per Capita (R$)\n");

    printf("%s: %.2f  |  %s: %.2f\n", cidade1, a2_c1, cidade2, a2_c2);

    if (segundaEscolha == 5) { // densidade: MENOR vence
        if (a2_c1 < a2_c2)      printf("Vencedor no Atributo 2: %s (densidade menor)\n", cidade1);
        else if (a2_c2 < a2_c1) printf("Vencedor no Atributo 2: %s (densidade menor)\n", cidade2);
        else                    printf("Atributo 2: Empate!\n");
        s2_c1 = (densidade1 > 0.0) ? 1.0/densidade1 : 0.0;
        s2_c2 = (densidade2 > 0.0) ? 1.0/densidade2 : 0.0;
    } else { // demais: MAIOR vence
        if (a2_c1 > a2_c2)      printf("Vencedor no Atributo 2: %s\n", cidade1);
        else if (a2_c2 > a2_c1) printf("Vencedor no Atributo 2: %s\n", cidade2);
        else                    printf("Atributo 2: Empate!\n");
        s2_c1 = a2_c1;
        s2_c2 = a2_c2;
    }

    // ===== Soma ajustada (densidade entra como 1/densidade) =====
    {
        double soma1 = s1_c1 + s2_c1;
        double soma2 = s1_c2 + s2_c2;

        printf("\nSoma dos atributos (ajustada):\n");
        printf("%s = %.2f  |  %s = %.2f\n", cidade1, soma1, cidade2, soma2);

        if (soma1 > soma2) {
            printf("\nRESULTADO FINAL: Carta 1 (%s) venceu!\n", cidade1);
        } else if (soma2 > soma1) {
            printf("\nRESULTADO FINAL: Carta 2 (%s) venceu!\n", cidade2);
        } else {
            printf("\nRESULTADO FINAL: Empate!\n");
        }
    }

    return 0;
}