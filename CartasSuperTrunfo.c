#include <stdio.h>
#include <string.h>

// Definição da estrutura para representar uma Carta
typedef struct {
    char estado[3]; // Ex: "SP"
    char codigo[10]; // Ex: "CT001"
    char nome_cidade[50];
    int populacao; // int para População (milhares ou milhões)
    float area; // km² (float para precisão)
    float pib; // em bilhões (float para precisão)
    int pontos_turisticos;
    float densidade_populacional; // Calculado: Populacao / Area
    float pib_per_capita; // Calculado: PIB / Populacao
} CartaSuperTrunfo;

// --- Função para calcular métricas derivadas ---
void calcular_metricas(CartaSuperTrunfo *carta) {
    // Cálculo da Densidade Populacional: População / Área
    // É importante verificar se a área não é zero para evitar divisão por zero
    if (carta->area > 0) {
        carta->densidade_populacional = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_populacional = 0.0;
    }

    // Cálculo do PIB per capita: PIB / População
    // É importante verificar se a população não é zero
    if (carta->populacao > 0) {
        // Multiplicar o PIB (em bilhões) por 1.000.000.000 para converter
        // para o valor real antes de dividir pela população.
        // Simplificando, podemos dividir o PIB em "bilhões" pela população
        // para ter um valor comparativo (que é o suficiente para o jogo)
        carta->pib_per_capita = carta->pib / (float)carta->populacao;
    } else {
        carta->pib_per_capita = 0.0;
    }
}

// --- Função principal para realizar o jogo ---
int main() {
    // ----------------------------------------------------
    // 1. RECEBIMENTO/CADASTRO DAS DUAS CARTAS (PRÉ-DEFINIDAS)
    // ----------------------------------------------------

    // Carta 1: São Paulo (Dados simulados para o exemplo)
    CartaSuperTrunfo carta1 = {
        .estado = "SP",
        .codigo = "CT001",
        .nome_cidade = "Sao Paulo",
        .populacao = 12396372,      // ~12.39 milhões
        .area = 1521.1,             // km²
        .pib = 763.8,               // em bilhões de R$ (simulado)
        .pontos_turisticos = 20
    };

    // Carta 2: Rio de Janeiro (Dados simulados para o exemplo)
    CartaSuperTrunfo carta2 = {
        .estado = "RJ",
        .codigo = "CT002",
        .nome_cidade = "Rio de Janeiro",
        .populacao = 6775561,       // ~6.77 milhões
        .area = 1200.3,             // km²
        .pib = 370.0,               // em bilhões de R$ (simulado)
        .pontos_turisticos = 35
    };

    printf("--- Cadastro das Cartas ---\n");
    printf("Carta 1: %s (%s) - Pop: %d\n", carta1.nome_cidade, carta1.estado, carta1.populacao);
    printf("Carta 2: %s (%s) - Pop: %d\n\n", carta2.nome_cidade, carta2.estado, carta2.populacao);

    // ----------------------------------------------------
    // 2. CÁLCULO DAS MÉTRICAS DERIVADAS
    // ----------------------------------------------------
    calcular_metricas(&carta1);
    calcular_metricas(&carta2);

    // ----------------------------------------------------
    // 3. DEFINIÇÃO E COMPARAÇÃO DO ATRIBUTO ESCOLHIDO
    // ----------------------------------------------------

    // Escolha do atributo para comparação (Diretamente no código - Requisito Simplificado)
    // Exemplo: PIB Per Capita. A variável armazenará os valores para comparação.
    float valor1 = carta1.pib_per_capita;
    float valor2 = carta2.pib_per_capita;

    // Define o nome do atributo para exibição
    char *atributo_nome = "PIB Per Capita (PIB / Pop)";

    // Define se o maior valor vence (true/1) ou se o menor valor vence (false/0)
    // Regra: Maior valor vence, exceto para Densidade Populacional.
    int maior_vence = 1; // 1 (true) para PIB Per Capita

    printf("--- Comparacao de Cartas ---\n");
    printf("Atributo: %s\n", atributo_nome);
    printf("Carta 1 - %s (%s): %.4f\n", carta1.nome_cidade, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.4f\n", carta2.nome_cidade, carta2.estado, valor2);
    printf("---------------------------\n");


    // ----------------------------------------------------
    // 4. LÓGICA DE DECISÃO (IF / IF-ELSE)
    // ----------------------------------------------------
    printf("Resultado: ");

    if (maior_vence) {
        // Lógica: Maior valor vence (População, Área, PIB, PIB Per Capita)
        if (valor1 > valor2) {
            printf("Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        } else if (valor2 > valor1) {
            printf("Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        } else {
            printf("Empate!\n");
        }
    } else {
        // Lógica: Menor valor vence (Densidade Populacional)
        // Nota: Para testar esta lógica, troque "atributo_nome" para "Densidade Populacional"
        // e mude a variável "maior_vence" para 0.
        if (valor1 < valor2) {
            printf("Carta 1 (%s) venceu!\n", carta1.nome_cidade);
        } else if (valor2 < valor1) {
            printf("Carta 2 (%s) venceu!\n", carta2.nome_cidade);
        } else {
            printf("Empate!\n");
        }
    }

    printf("\n--- Detalhes das Cartas ---\n");
    printf("Pop. (1): %d / Pop. (2): %d\n", carta1.populacao, carta2.populacao);
    printf("Area (1): %.2f / Area (2): %.2f\n", carta1.area, carta2.area);
    printf("Dens. Pop. (1): %.2f / Dens. Pop. (2): %.2f\n", carta1.densidade_populacional, carta2.densidade_populacional);

    return 0;
}
