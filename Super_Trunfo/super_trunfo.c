#include <stdio.h>

int main() {
    // Declaração de variáveis da carta (sintaxe tipo_nome)    
    char Estado[15], Código_da_carta[5], Nome_da_cidade[15];
    int População, Número_de_pontos_turísticos;
    float Área_em_Km², PIB;

    // Entrada de dados
    printf("♣️♦️♠️ Cadastro da Carta ♣️♦️♠️\n");

    printf("Digite o nome do Estado: ");
    scanf("%s", Estado);

    printf("Digite o código da carta: ");
    scanf("%s", Código_da_carta);

    printf("Digite o nome da Cidade: ");
    scanf("%s", Nome_da_cidade);

    printf("Digite o número de habitantes: ");
    scanf("%d", &População);

    printf("Digite a área da cidade em km²: ");
    scanf("%f", &Área_em_Km²);

    printf("Digite o Produto Interno Brupo da Cidade: ");
    scanf("%f", &PIB);

    printf("Digite a quantidade de pontos turísticos na cidade: ");
    scanf("%d", &Número_de_pontos_turísticos);

    // Saída de dados
    printf("\n ♣️♦️♠️ Informações da Carta ♣️♦️♠️\n");    
    printf("Estado: %s\n", Estado);
    printf("Código da carta: %s\n", Código_da_carta);
    printf("Cidade: %s\n", Nome_da_cidade);
    printf("População: %d\n", População);
    printf("Área (em km²): %f\n", Área_em_Km²);
    printf("PIB da Cidade: %f\n", PIB);
    printf("Número de Pontos Turísticos: %d\n", Número_de_pontos_turísticos);
    
    return 0;
}