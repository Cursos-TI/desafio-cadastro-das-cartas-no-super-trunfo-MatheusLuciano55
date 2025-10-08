#include <stdio.h>
#include <string.h>

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

// --- Função para calcular métricas derivadas (reutilizada) ---
void calcular_metricas(CartaSuperTrunfo *carta) {
    // População em milhões / Área em milhares de km²
    if (carta->area > 0) {
        carta->densidade_demografica = (float)carta->populacao / carta->area;
    } else {
        carta->densidade_demografica = 0.0;
    }

    // PIB em trilhões / População em milhões
    if (carta->populacao > 0) {
        carta->pib_per_capita = carta->pib / (float)carta->populacao;
    } else {
        carta->pib_per_capita = 0.0;
    }
}

// --- Função para exibir o menu e obter a escolha do usuário ---
int exibir_menu() {
    int escolha;
    printf("\n========================================\n");
    printf("        Escolha o Atributo (Super Trunfo)     \n");
    printf("========================================\n");
    printf("1. População (Maior vence)\n");
    printf("2. Área (Maior vence)\n");
    printf("3. PIB (Maior vence)\n");
    printf("4. Número de Pontos Turísticos (Maior vence)\n");
    printf("5. Densidade Demográfica (Menor vence)\n");
    printf("6. PIB Per Capita (Maior vence)\n");
    printf("7. Sair do Jogo\n");
    printf("----------------------------------------\n");
    printf("Digite sua escolha (1-7): ");
    
    // Verifica se a leitura da entrada foi bem-sucedida
    if (scanf("%d", &escolha) != 1) {
        // Limpa o buffer de entrada em caso de erro (caractere não numérico)
        while (getchar() != '\n');
        return 0; // Retorna uma opção inválida
    }
    
    return escolha;
}

// --- Função principal do programa ---
int main() {
    // ----------------------------------------------------
    // 1. DADOS DAS DUAS CARTAS (PRÉ-DEFINIDAS)
    // Usando dados simulados e convertidos para facilitar os cálculos (Milhões/Trilhões)
    // ----------------------------------------------------

    // Carta 1: Brasil
    CartaSuperTrunfo carta1 = {
        .nome_pais = "Brasil",
        .codigo_carta = "CTBR",
        .populacao = 217,           // População em milhões
        .area = 8515,               // Área em milhares de km²
        .pib = 2.1,                 // PIB em trilhões de dólares (simulado)
        .pontos_turisticos = 50
    };

    // Carta 2: Índia
    CartaSuperTrunfo carta2 = {
        .nome_pais = "Índia",
        .codigo_carta = "CTIN",
        .populacao = 1441,          // População em milhões
        .area = 3287,               // Área em milhares de km²
        .pib = 3.9,                 // PIB em trilhões de dólares (simulado)
        .pontos_turisticos = 75
    };

    // Cálculo inicial de métricas derivadas
    calcular_metricas(&carta1);
    calcular_metricas(&carta2);

    int escolha;
    // Loop principal para interatividade
    do {
        escolha = exibir_menu();

        // Variáveis para armazenar o valor e o nome do atributo selecionado
        float valor1, valor2;
        char *atributo_nome = NULL;
        // 0 = Maior vence (Padrão); 1 = Menor vence (Densidade Demográfica)
        int regra_menor_vence = 0;

        // ----------------------------------------------------
        // 2. ESTRUTURA SWITCH PARA SELECIONAR O ATRIBUTO
        // ----------------------------------------------------
        switch (escolha) {
            case 1: // População
                valor1 = (float)carta1.populacao;
                valor2 = (float)carta2.populacao;
                atributo_nome = "População (em milhões)";
                break;
            case 2: // Área
                valor1 = carta1.area;
                valor2 = carta2.area;
                atributo_nome = "Área (em milhares de km²)";
                break;
            case 3: // PIB
                valor1 = carta1.pib;
                valor2 = carta2.pib;
                atributo_nome = "PIB (em trilhões)";
                break;
            case 4: // Pontos Turísticos
                valor1 = (float)carta1.pontos_turisticos;
                valor2 = (float)carta2.pontos_turisticos;
                atributo_nome = "Número de Pontos Turísticos";
                break;
            case 5: // Densidade Demográfica (Regra especial: Menor vence)
                valor1 = carta1.densidade_demografica;
                valor2 = carta2.densidade_demografica;
                atributo_nome = "Densidade Demográfica";
                regra_menor_vence = 1; // Inverte a regra
                break;
            case 6: // PIB Per Capita
                valor1 = carta1.pib_per_capita;
                valor2 = carta2.pib_per_capita;
                atributo_nome = "PIB Per Capita";
                break;
            case 7: // Sair do Jogo
                printf("\nObrigado por jogar! Fim do programa.\n");
                return 0;
            default:
                // Tratamento de entrada inválida (requisito não funcional)
                if (escolha != 7) {
                    printf("\nOpção inválida. Por favor, escolha um número de 1 a 7.\n");
                }
                continue; // Volta para o início do loop
        }

        // ----------------------------------------------------
        // 3. EXIBIÇÃO E LÓGICA DE COMPARAÇÃO ANINHADA (IF-ELSE)
        // ----------------------------------------------------
        printf("\n--- Comparação de Cartas ---\n");
        printf("Atributo Escolhido: %s\n", atributo_nome);
        printf("Carta 1 - %s: %.2f\n", carta1.nome_pais, valor1);
        printf("Carta 2 - %s: %.2f\n", carta2.nome_pais, valor2);
        printf("---------------------------\n");

        if (regra_menor_vence == 1) {
            // Lógica ANINHADA para Densidade Demográfica (Menor valor vence)
            if (valor1 < valor2) {
                printf("Resultado: Carta 1 (%s) venceu (Menor valor)!\n", carta1.nome_pais);
            } else if (valor2 < valor1) {
                printf("Resultado: Carta 2 (%s) venceu (Menor valor)!\n", carta2.nome_pais);
            } else {
                printf("Resultado: Empate!\n");
            }
        } else {
            // Lógica Padrão (Maior valor vence)
            if (valor1 > valor2) {
                printf("Resultado: Carta 1 (%s) venceu (Maior valor)!\n", carta1.nome_pais);
            } else if (valor2 > valor1) {
                printf("Resultado: Carta 2 (%s) venceu (Maior valor)!\n", carta2.nome_pais);
            } else {
                printf("Resultado: Empate!\n");
            }
        }

    } while (escolha != 7); // Continua o loop até o usuário escolher Sair

    return 0;
}
