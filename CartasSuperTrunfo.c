#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Para a função exit()

// Definição da estrutura para representar uma Carta de País
typedef struct {
    char nome_pais[50];
    char codigo_carta[10];
    int populacao; // Em milhões
    float area; // Em milhares de km²
    float pib; // Em trilhões
    int pontos_turisticos;
    float densidade_demografica; // População / Área
    float pib_per_capita; // PIB / População
} CartaSuperTrunfo;

// Array global de strings para o nome dos atributos
const char *ATRIBUTOS[] = {
    "Nenhum", // Índice 0 (vazio)
    "População (em Milhões)",
    "Área (em Milhares de km²)",
    "PIB (em Trilhões)",
    "Pontos Turísticos",
    "Densidade Demográfica", // Menor vence
    "PIB Per Capita"
};
#define NUM_ATRIBUTOS 6 // População (1) a PIB Per Capita (6)

// --- Função para calcular métricas derivadas (reutilizada) ---
void calcular_metricas(CartaSuperTrunfo *carta) {
    if (carta->area > 0) {
        carta->densidade_demografica = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_demografica = 0.0;
    }

    if (carta->populacao > 0) {
        // PIB em trilhões / População em milhões
        carta->pib_per_capita = carta->pib / (float)carta->populacao;
    } else {
        carta->pib_per_capita = 0.0;
    }
}

// --- Função para retornar o valor do atributo da carta com base no índice ---
float obter_valor_atributo(const CartaSuperTrunfo *carta, int indice) {
    switch (indice) {
        case 1: return (float)carta->populacao;
        case 2: return carta->area;
        case 3: return carta->pib;
        case 4: return (float)carta->pontos_turisticos;
        case 5: return carta->densidade_demografica;
        case 6: return carta->pib_per_capita;
        default: return 0.0; // Opção de segurança
    }
}

// --- Função para exibir o menu dinâmico e obter a escolha do usuário ---
// 'excluir_indice' garante que o atributo escolhido não apareça novamente.
int exibir_menu_dinamico(int excluir_indice) {
    int escolha;
    int i;
    printf("\n========================================\n");
    printf("        Escolha um Atributo (1 a %d)     \n", NUM_ATRIBUTOS);
    printf("========================================\n");

    for (i = 1; i <= NUM_ATRIBUTOS; i++) {
        if (i != excluir_indice) {
            // Usa o operador ternário para exibir a regra de comparação
            const char *regra = (i == 5) ? "(Menor vence)" : "(Maior vence)";
            printf("%d. %s %s\n", i, ATRIBUTOS[i], regra);
        }
    }
    printf("----------------------------------------\n");
    printf("Digite sua escolha: ");

    if (scanf("%d", &escolha) != 1) {
        while (getchar() != '\n'); // Limpa o buffer de entrada
        return 0; // Opção inválida
    }

    // Lógica para garantir que a opção é válida e não é o índice excluído
    if (escolha < 1 || escolha > NUM_ATRIBUTOS || escolha == excluir_indice) {
        return 0;
    }

    return escolha;
}

// --- Função principal do programa ---
int main() {
    // ----------------------------------------------------
    // 1. DADOS DAS DUAS CARTAS (PRÉ-DEFINIDAS)
    // ----------------------------------------------------
    CartaSuperTrunfo carta1 = {
        .nome_pais = "Brasil",
        .populacao = 217,
        .area = 8515.7,
        .pib = 2.1,
        .pontos_turisticos = 50
    };

    CartaSuperTrunfo carta2 = {
        .nome_pais = "Índia",
        .populacao = 1441,
        .area = 3287.3,
        .pib = 3.9,
        .pontos_turisticos = 75
    };

    // Cálculo inicial de métricas
    calcular_metricas(&carta1);
    calcular_metricas(&carta2);

    int atributo1 = 0, atributo2 = 0;
    float valor1_c1, valor1_c2, valor2_c1, valor2_c2;
    float soma_c1, soma_c2;

    printf(">>> Jogo Super Trunfo Avançado <<<\n");
    printf("Cartas em Jogo: 1. %s vs 2. %s\n", carta1.nome_pais, carta2.nome_pais);

    // ----------------------------------------------------
    // 2. ESCOLHA DO PRIMEIRO ATRIBUTO
    // ----------------------------------------------------
    do {
        atributo1 = exibir_menu_dinamico(0); // 0 indica que nenhum índice deve ser excluído
        if (atributo1 == 0) {
            printf("\nOpção inválida ou fora do intervalo. Tente novamente.\n");
        }
    } while (atributo1 == 0);

    // ----------------------------------------------------
    // 3. ESCOLHA DO SEGUNDO ATRIBUTO (Dinâmico)
    // ----------------------------------------------------
    printf("\n--- Primeiro Atributo Escolhido: %s ---\n", ATRIBUTOS[atributo1]);

    do {
        printf("\nEscolha o SEGUNDO atributo para comparação (Diferente do primeiro).\n");
        atributo2 = exibir_menu_dinamico(atributo1); // Exclui o primeiro atributo
        if (atributo2 == 0) {
            printf("\nOpção inválida. Escolha um número que não seja o %d.\n", atributo1);
        }
    } while (atributo2 == 0);

    printf("\n--- Segundo Atributo Escolhido: %s ---\n", ATRIBUTOS[atributo2]);

    // ----------------------------------------------------
    // 4. PREPARAÇÃO DOS VALORES E CÁLCULO DA SOMA
    // ----------------------------------------------------
    valor1_c1 = obter_valor_atributo(&carta1, atributo1);
    valor1_c2 = obter_valor_atributo(&carta2, atributo1);
    valor2_c1 = obter_valor_atributo(&carta1, atributo2);
    valor2_c2 = obter_valor_atributo(&carta2, atributo2);

    // Soma dos valores dos dois atributos para cada carta
    soma_c1 = valor1_c1 + valor2_c1;
    soma_c2 = valor1_c2 + valor2_c2;

    // ----------------------------------------------------
    // 5. EXIBIÇÃO CLARA DO RESULTADO E COMPARAÇÃO FINAL
    // ----------------------------------------------------
    printf("\n======================================================\n");
    printf("                RESULTADO DA RODADA                   \n");
    printf("======================================================\n");

    // Detalhe do Atributo 1
    printf("1º Atributo (%s):\n", ATRIBUTOS[atributo1]);
    printf("  %s: %.4f | %s: %.4f\n", carta1.nome_pais, valor1_c1, carta2.nome_pais, valor1_c2);
    // Operador Ternário para determinar o vencedor baseado na regra
    const char *vencedor1 = (atributo1 == 5)
                            ? ((valor1_c1 < valor1_c2) ? carta1.nome_pais : ((valor1_c2 < valor1_c1) ? carta2.nome_pais : "Empate"))
                            : ((valor1_c1 > valor1_c2) ? carta1.nome_pais : ((valor1_c2 > valor1_c1) ? carta2.nome_pais : "Empate"));
    printf("  Vencedor Individual: %s\n", vencedor1);
    
    printf("\n2º Atributo (%s):\n", ATRIBUTOS[atributo2]);
    printf("  %s: %.4f | %s: %.4f\n", carta1.nome_pais, valor2_c1, carta2.nome_pais, valor2_c2);
    // Operador Ternário para determinar o vencedor baseado na regra
    const char *vencedor2 = (atributo2 == 5)
                            ? ((valor2_c1 < valor2_c2) ? carta1.nome_pais : ((valor2_c2 < valor2_c1) ? carta2.nome_pais : "Empate"))
                            : ((valor2_c1 > valor2_c2) ? carta1.nome_pais : ((valor2_c2 > valor2_c1) ? carta2.nome_pais : "Empate"));
    printf("  Vencedor Individual: %s\n", vencedor2);


    printf("\n--- SOMA FINAL ---\n");
    printf("%s (Soma): %.4f\n", carta1.nome_pais, soma_c1);
    printf("%s (Soma): %.4f\n", carta2.nome_pais, soma_c2);
    
    // Comparação final baseada na Soma (Regra: Maior Soma Vence)
    if (soma_c1 > soma_c2) {
        printf("\n>>> VENCEDOR DA RODADA: %s! <<<\n", carta1.nome_pais);
    } else if (soma_c2 > soma_c1) {
        printf("\n>>> VENCEDOR DA RODADA: %s! <<<\n", carta2.nome_pais);
    } else {
        printf("\n>>> EMPATE! A soma dos atributos é igual. <<<\n");
    }

    printf("======================================================\n");

    return 0;
}
