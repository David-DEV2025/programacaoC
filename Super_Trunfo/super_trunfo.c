/*
    Desafio Super Trunfo - Nível Novato (Etapa 1)
    ---------------------------------------------
    Objetivo:
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
    // Declaração de variáveis das cartas
    char Estado1, Estado2;
    char Codigo_da_carta1[5], Codigo_da_carta2[5];
    char Nome_da_cidade1[30], Nome_da_cidade2[30];
    int Populacao1, Populacao2;
    int Numero_de_pontos_turisticos1, Numero_de_pontos_turisticos2;
    float Area_em_Km1, Area_em_Km2;
    float PIB1, PIB2;

    // Entrada de dados - carta 1
    printf("♣️♦️♠️ Cadastro da Carta 01 ♣️♦️♠️\n");

    printf("Digite o Estado (uma letra de 'A' a 'H'): ");
    scanf(" %c", &Estado1);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", Codigo_da_carta1);

    printf("Digite o nome da Cidade: ");
    scanf("%s", Nome_da_cidade1);

    printf("Digite o número de habitantes: ");
    scanf("%d", &Populacao1);

    printf("Digite a área da cidade em km²: ");
    scanf("%f", &Area_em_Km1);

    printf("Digite o Produto Interno Bruto da Cidade: ");
    scanf("%f", &PIB1);

    printf("Digite a quantidade de pontos turísticos na cidade: ");
    scanf("%d", &Numero_de_pontos_turisticos1);

    // Saída de dados - carta 1
    printf("\nCarta 1:\n");
    printf("Estado: %c\n", Estado1);
    printf("Código: %s\n", Codigo_da_carta1);
    printf("Nome da Cidade: %s\n", Nome_da_cidade1);
    printf("População: %d\n", Populacao1);
    printf("Área: %.2f km²\n", Area_em_Km1);
    printf("PIB: %.2f bilhões de reais\n", PIB1);
    printf("Número de Pontos Turísticos: %d\n", Numero_de_pontos_turisticos1);

    // Entrada de dados - carta 2
    printf("\n♣️♦️♠️ Cadastro da Carta 02 ♣️♦️♠️\n");

    printf("Digite o Estado (uma letra de 'A' a 'H'): ");
    scanf(" %c", &Estado2);

    printf("Digite o código da carta (ex: B02): ");
    scanf("%s", Codigo_da_carta2);

    printf("Digite o nome da Cidade: ");
    scanf("%s", Nome_da_cidade2);

    printf("Digite o número de habitantes: ");
    scanf("%d", &Populacao2);

    printf("Digite a área da cidade em km²: ");
    scanf("%f", &Area_em_Km2);

    printf("Digite o Produto Interno Bruto da Cidade: ");
    scanf("%f", &PIB2);

    printf("Digite a quantidade de pontos turísticos na cidade: ");
    scanf("%d", &Numero_de_pontos_turisticos2);

    // Saída de dados - carta 2
    printf("\nCarta 2:\n");
    printf("Estado: %c\n", Estado2);
    printf("Código: %s\n", Codigo_da_carta2);
    printf("Nome da Cidade: %s\n", Nome_da_cidade2);
    printf("População: %d\n", Populacao2);
    printf("Área: %.2f km²\n", Area_em_Km2);
    printf("PIB: %.2f bilhões de reais\n", PIB2);
    printf("Número de Pontos Turísticos: %d\n", Numero_de_pontos_turisticos2);

    return 0;
}