#include <stdio.h>
#define TAM_MAX 100

int main() {
    // Variáveis - Carta 1
    char estado1, codigo1[5], nomeCidade1[TAM_MAX];
    unsigned long int populacao1;
    float area1, pib1;
    int pontosTuristicos1;

    // Variáveis - Carta 2
    char estado2, codigo2[5], nomeCidade2[TAM_MAX];
    unsigned long int populacao2;
    float area2, pib2;
    int pontosTuristicos2;

    // Entrada dos dados da Carta 1
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Estado (letra): ");
    scanf(" %c", &estado1);
    printf("Código (até 4 caracteres): ");
    scanf("%s", codigo1);
    printf("Nome da Cidade: ");
    getchar(); // limpar buffer
    fgets(nomeCidade1, TAM_MAX, stdin);
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Entrada dos dados da Carta 2
    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Estado (letra): ");
    scanf(" %c", &estado2);
    printf("Código (até 4 caracteres): ");
    scanf("%s", codigo2);
    printf("Nome da Cidade: ");
    getchar(); // limpar buffer
    fgets(nomeCidade2, TAM_MAX, stdin);
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Menu mestre
    int op1, op2;
    float densidade1 = populacao1 / area1;
    float densidade2 = populacao2 / area2;

    do {
        printf("\n=== SUPER TRUNFO - NÍVEL MESTRE ===\n");
        printf("Escolha 2 atributos para comparar:\n");
        printf("1 - População\n");
        printf("2 - Área\n");
        printf("3 - PIB\n");
        printf("4 - Pontos Turísticos\n");
        printf("5 - Densidade Populacional (MENOR VENCE)\n");
        printf("0 - Sair\n");

        printf("Escolha o primeiro atributo: ");
        scanf("%d", &op1);
        if (op1 == 0) break;

        printf("Escolha o segundo atributo: ");
        scanf("%d", &op2);
        if (op2 == 0) break;

        printf("\n> Comparando atributos %d e %d:\n", op1, op2);

        // Função auxiliar de comparação
        int comparar(float v1a, float v2a, int menorVence) {
            return (v1a == v2a) ? 0 : (menorVence ? (v1a < v2a ? 1 : 2) : (v1a > v2a ? 1 : 2));
        }

        // Obter valores
        float valor1a, valor2a, valor1b, valor2b;
        int menorVence1 = 0, menorVence2 = 0;

        // Atributo 1
        switch (op1) {
            case 1: valor1a = populacao1; valor2a = populacao2; break;
            case 2: valor1a = area1; valor2a = area2; break;
            case 3: valor1a = pib1; valor2a = pib2; break;
            case 4: valor1a = pontosTuristicos1; valor2a = pontosTuristicos2; break;
            case 5: valor1a = densidade1; valor2a = densidade2; menorVence1 = 1; break;
            default: printf("Atributo inválido!\n"); continue;
        }

        // Atributo 2
        switch (op2) {
            case 1: valor1b = populacao1; valor2b = populacao2; break;
            case 2: valor1b = area1; valor2b = area2; break;
            case 3: valor1b = pib1; valor2b = pib2; break;
            case 4: valor1b = pontosTuristicos1; valor2b = pontosTuristicos2; break;
            case 5: valor1b = densidade1; valor2b = densidade2; menorVence2 = 1; break;
            default: printf("Atributo inválido!\n"); continue;
        }

        // Comparações usando operadores ternários
        int resultado1 = comparar(valor1a, valor2a, menorVence1);
        int resultado2 = comparar(valor1b, valor2b, menorVence2);

        if (resultado1 == 0 && resultado2 == 0) {
            printf("EMPATE TOTAL! Ambas as cartas são incrivelmente equilibradas!\n");
        } else if (resultado1 == resultado2) {
            printf("Carta %d venceu nos dois critérios!\n", resultado1);
        } else if (resultado1 == 0 || resultado2 == 0) {
            printf("Empate em um critério. Carta %d venceu no outro!\n", resultado1 == 0 ? resultado2 : resultado1);
        } else {
            printf("Cada carta venceu em um critério! Um duelo muito equilibrado!\n");
        }

    } while (1);

    printf("\nEncerrando o programa. Até a próxima partida!\n");
    return 0;
}

