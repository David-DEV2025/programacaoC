/*
    Desafio Super Trunfo Países - Nível Novato (Etapa 1)
    ---------------------------------------------
    Objetivo / Tema 1:
    - Cadastrar duas cartas do jogo "Super Trunfo de Países" lendo os dados do usuário
      e exibir as informações formatadas na tela.

    Para cada carta, o programa lê:
    - Estado: uma letra de 'A' a 'H' (char)
    - Código da Carta: ex. A01, B03 (string)
    - Nome da Cidade: nome da cidade (string)
    - População: número de habitantes (int)
    - Área (em km²): área da cidade (float)
    - PIB: Produto Interno Bruto (float)
    - Número de Pontos Turísticos: quantidade (int)

    Regras desta etapa:
    - Sem estruturas de repetição (for/while) e sem decisões (if/else).
    - Sequência simples de leitura e exibição.
    - Saída clara, uma informação por linha, para cada carta.

    Observação:
    - Este código foca apenas em entrada e saída de dados, sem comparações entre cartas.
*/

#include <stdio.h>

int main() {
    // Declaração de variáveis das cartas (Novato e Aventureiro)
    char estado1, estado2;
    char codigo1[5], codigo2[5];
    char cidade1[30], cidade2[30];
    //int populacao1, populacao2; // movido do nível Novato para Nível Mestre
    int pontos1, pontos2;
    float area1, area2;
    float pib1, pib2; //entrada em bilhões

    //Declaração de variáveis das cartas (Mestre)
    unsigned long int populacao1, populacao2;
    
    // Nível Aventureiro
    float densidade1, densidade2;
    float pib_per_capita1, pib_per_capita2;

    // Nível Mestre
    float super1, super2;
            
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
    scanf("%f", &area1);

    printf("Digite o PIB da Cidade (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Digite o número de pontos turísticos na cidade: ");
    scanf("%d", &pontos1);

    // Cálculos dos atributos derivados - Carta 1
    densidade1 = (float)populacao1 / area1; // hab/km²
    pib_per_capita1 = (pib1*1000000000.0f) / (float)populacao1; // R$/hab
    super1 = (float)populacao1
           + area1
           + (pib1 * 1000000000.0f)
           + (float)pontos1
           + pib_per_capita1
           + (1.0f / densidade1);  // menor densidade => maior termo

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
    scanf("%f", &area2);

    printf("Digite o PIB da Cidade (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Digite o número de pontos turísticos na cidade: ");
    scanf("%d", &pontos2);

    // Cálculos dos atributos derivados - Carta 2
    densidade2 = (float)populacao2 / area2; // hab/km²
    pib_per_capita2 = (pib2*1000000000.0f) / (float)populacao2; // reais por habitante
    super2 = (float)populacao2
           + area2
           + (pib2 * 1000000000.0f)
           + (float)pontos2
           + pib_per_capita2
           + (1.0f / densidade2);

    // Saída de dados - carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %lu\n", populacao1); // %lu para unsigned long int
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
    printf("População: %lu\n", populacao2); // %lu para unsigned long int
    printf("Área: %.2f km2\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos2);
    printf("Densidade Populacional: %.2f hab/km2\n", densidade2);
    printf("PIB per Capita: %.2f reais\n", pib_per_capita2);
    printf("Super Poder: %.2f\n", super2);

    // Comparacoes (1 = Carta 1 venceu; 0 = Carta 2 venceu)
    // Regra: densidade -> menor vence; demais -> maior vence
    {
        int v_pop   = (populacao1 > populacao2);
        int v_area  = (area1 > area2);
        int v_pib   = (pib1 > pib2);                        // ambos em bilhoes
        int v_pts   = (pontos1 > pontos2);
        int v_dens  = (densidade1 < densidade2);            // menor vence
        int v_pcap  = (pib_per_capita1 > pib_per_capita2);
        int v_super = (super1 > super2);

        printf("\nComparacao de Cartas:\n\n");
        printf("Populacao: Carta %d venceu (%d)\n", v_pop ? 1 : 2, v_pop);
        printf("Area: Carta %d venceu (%d)\n", v_area ? 1 : 2, v_area);
        printf("PIB: Carta %d venceu (%d)\n", v_pib ? 1 : 2, v_pib);
        printf("Pontos Turisticos: Carta %d venceu (%d)\n", v_pts ? 1 : 2, v_pts);
        printf("Densidade Populacional: Carta %d venceu (%d)\n", v_dens ? 1 : 2, v_dens);
        printf("PIB per Capita: Carta %d venceu (%d)\n", v_pcap ? 1 : 2, v_pcap);
        printf("Super Poder: Carta %d venceu (%d)\n", v_super ? 1 : 2, v_super);
    }
      
    return 0;
}