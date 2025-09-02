#include <stdio.h>

int main() {
    // Dados da primeira carta
    char estado1;
    char codigo1[4]; 
    char cidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidade_populacional1;
    float pib_per_capita1;
    float super_poder1;
    
    // Dados da segunda carta
    char estado2;
    char codigo2[4];
    char cidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade_populacional2;
    float pib_per_capita2;
    float super_poder2;

    // Leitura da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado1);

    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%3s", codigo1);

    printf("Digite o Nome da Cidade: ");
    scanf(" %49[^\n]", cidade1);

    printf("Digite a População: ");
    scanf("%lu", &populacao1);

    printf("Digite a Área (em km²): ");
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Leitura da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &estado2);

    printf("Digite o Código da Carta (ex: B02): ");
    scanf("%3s", codigo2);

    printf("Digite o Nome da Cidade: ");
    scanf(" %49[^\n]", cidade2);

    printf("Digite a População: ");
    scanf("%lu", &populacao2);

    printf("Digite a Área (em km²): ");
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos2);

    // Cálculos (com proteção contra divisão por zero)
    densidade_populacional1 = (area1 > 0) ? (populacao1 / area1) : 0;
    densidade_populacional2 = (area2 > 0) ? (populacao2 / area2) : 0;

    pib_per_capita1 = (populacao1 > 0) ? (pib1 * 1000000000.0f / populacao1) : 0;
    pib_per_capita2 = (populacao2 > 0) ? (pib2 * 1000000000.0f / populacao2) : 0;

    // Super Poder (float com soma de atributos numéricos)
    super_poder1 = (float)populacao1 + area1 + (pib1 * 1000000000.0f) +
                   pontosTuristicos1 + pib_per_capita1 +
                   ((densidade_populacional1 > 0) ? (1.0f / densidade_populacional1) : 0);

    super_poder2 = (float)populacao2 + area2 + (pib2 * 1000000000.0f) +
                   pontosTuristicos2 + pib_per_capita2 +
                   ((densidade_populacional2 > 0) ? (1.0f / densidade_populacional2) : 0);

    // Exibição dos dados
    printf("\nCarta 1:\n");
    printf("Estado: %c | Código: %s | Cidade: %s\n", estado1, codigo1, cidade1);
    printf("População: %lu | Área: %.2f km² | PIB: %.2f bilhões\n", populacao1, area1, pib1);
    printf("Pontos Turísticos: %d | Densidade Populacional: %.2f | PIB per capita: %.2f\n", 
           pontosTuristicos1, densidade_populacional1, pib_per_capita1);
    printf("Super Poder: %.2f\n", super_poder1);

    printf("\nCarta 2:\n");
    printf("Estado: %c | Código: %s | Cidade: %s\n", estado2, codigo2, cidade2);
    printf("População: %lu | Área: %.2f km² | PIB: %.2f bilhões\n", populacao2, area2, pib2);
    printf("Pontos Turísticos: %d | Densidade Populacional: %.2f | PIB per capita: %.2f\n", 
           pontosTuristicos2, densidade_populacional2, pib_per_capita2);
    printf("Super Poder: %.2f\n", super_poder2);

    // Comparação das cartas
    printf("\nComparação de Cartas:\n");

    printf("População: Carta 1 venceu (%d)\n", populacao1 > populacao2);
    printf("Área: Carta 1 venceu (%d)\n", area1 > area2);
    printf("PIB: Carta 1 venceu (%d)\n", pib1 > pib2);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", pontosTuristicos1 > pontosTuristicos2);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", densidade_populacional1 < densidade_populacional2);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", pib_per_capita1 > pib_per_capita2);
    printf("Super Poder: Carta 1 venceu (%d)\n", super_poder1 > super_poder2);

    return 0;
}
