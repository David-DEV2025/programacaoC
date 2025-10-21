#include <stdio.h>

/* ==========================================
   Funções recursivas (Torre, Bispo, Rainha)
   ========================================== */

// Torre: move 1 casa por chamada recursiva para a DIREITA
void moverTorreRec(int casas) {
    if (casas <= 0) return;
    printf("Direita\n");
    moverTorreRec(casas - 1);
}

// Bispo: move 1 casa por chamada recursiva na diagonal CIMA + DIREITA
void moverBispoRec(int casas) {
    if (casas <= 0) return;
    printf("Cima Direita\n");
    moverBispoRec(casas - 1);
}

// Rainha: move 1 casa por chamada recursiva para a ESQUERDA
void moverRainhaRec(int casas) {
    if (casas <= 0) return;
    printf("Esquerda\n");
    moverRainhaRec(casas - 1);
}

int main() {
    /* ==========================================
       Parâmetros (definidos no código)
       ========================================== */
    const int TORRE_CASAS = 5;    // Direita
    const int BISPO_CASAS = 5;    // Cima Direita
    const int RAINHA_CASAS = 8;   // Esquerda

    /* ==========================================
       TORRE – Recursividade
       ========================================== */
    printf("Movimento da TORRE (recursivo):\n");
    moverTorreRec(TORRE_CASAS);

    printf("\n");

    /* ==========================================
       BISPO – Recursividade
       ========================================== */
    printf("Movimento do BISPO (recursivo):\n");
    moverBispoRec(BISPO_CASAS);

    printf("\n");

    /* ==========================================
       RAINHA – Recursividade
       ========================================== */
    printf("Movimento da RAINHA (recursivo):\n");
    moverRainhaRec(RAINHA_CASAS);

    printf("\n");

    /* ===================================================================
       CAVALO – Loops aninhados (complexos)
       Objetivo: 2 casas para CIMA e 1 para a DIREITA (movimento em 'L')
       Requisitos: loops aninhados com múltiplas variáveis/condições,
                   uso de continue/break para controle fino.
       =================================================================== */
    printf("Movimento do CAVALO (loops aninhados):\n");

    // Fase 0 => eixo vertical (2 passos para CIMA)
    // Fase 1 => eixo horizontal (1 passo para a DIREITA)
    // Variáveis múltiplas no cabeçalho do for.
    int passosVert = 2;
    int passosHor  = 1;
    int vertConcluidos = 0;

    for (int fase = 0, fasesTotais = 2; fase < fasesTotais; fase++) {
        int limite = (fase == 0) ? passosVert : passosHor;
        int j = 0;

        // While interno percorre os passos de cada fase (vertical/horizontal)
        while (j < limite) {
            // Se estamos na fase horizontal mas ainda não concluímos os 2 passos verticais,
            // usamos 'break' para encerrar a fase cedo (trava de segurança).
            if (fase == 1 && vertConcluidos < passosVert) {
                break; // não deveria acontecer neste fluxo, mas demonstra controle de fluxo
            }

            // Fase vertical: imprime "Cima" duas vezes
            if (fase == 0) {
                // Exemplo de 'continue' para pular qualquer iteração inválida
                // (aqui sempre válida, mas mostra o recurso solicitado).
                if (j < 0) { // condição sempre falsa, apenas ilustrativa
                    j++;
                    continue;
                }
                printf("Cima\n");
                vertConcluidos++;
                j++;
                continue; // vai para a próxima iteração de 'while' dentro da mesma fase
            }

            // Fase horizontal: imprime "Direita" uma vez
            printf("Direita\n");
            j++;
        }
    }

    printf("\n");

    /* ===================================================================
       BISPO – Loops aninhados
       Externo = movimento vertical; Interno = movimento horizontal.
       A cada "casa" na diagonal, realizamos um passo vertical (Cima)
       e um passo horizontal (Direita). Mantemos a saída clara.
       =================================================================== */
    printf("Movimento do BISPO (loops aninhados):\n");
    for (int passoVertical = 0; passoVertical < BISPO_CASAS; passoVertical++) {
        // Passo vertical (Cima)
        printf("Cima\n");

        // Passo horizontal (Direita) — interno ao vertical
        for (int passoHorizontal = 0; passoHorizontal < 1; passoHorizontal++) {
            printf("Direita\n");
        }
    }

    return 0;
}