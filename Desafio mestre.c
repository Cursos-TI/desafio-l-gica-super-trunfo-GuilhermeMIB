#include <stdio.h>

// Função para exibir nome do atributo
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
        case 7: return "Super Poder";
        default: return "Desconhecido";
    }
}

// Função para obter valor do atributo
float obterValor(int atributo, unsigned long int pop, float area, float pib, int pontos, float densidade, float perCapita, float superPoder) {
    switch (atributo) {
        case 1: return (float)pop;
        case 2: return area;
        case 3: return pib;
        case 4: return (float)pontos;
        case 5: return densidade;
        case 6: return perCapita;
        case 7: return superPoder;
        default: return 0;
    }
}

// Função para escolher atributo com menu dinâmico
int escolherAtributo(int excluido) {
    int opcao;
    printf("Escolha um atributo:\n");
    for (int i = 1; i <= 7; i++) {
        if (i != excluido)
            printf("%d - %s\n", i, nomeAtributo(i));
    }
    printf("Digite o número do atributo: ");
    scanf("%d", &opcao);
    if (opcao == excluido || opcao < 1 || opcao > 7) {
        printf("Opção inválida. Tente novamente.\n");
        return escolherAtributo(excluido);
    }
    return opcao;
}

int main() {
    // Dados da Carta 1
    char nomePais1[50], codigo1[4], nomeCidade1[50];
    unsigned long int populacao1;
    float area1, pib1, densidade1, pibPerCapita1, superPoder1;
    int pontosTuristicos1;

    // Dados da Carta 2
    char nomePais2[50], codigo2[4], nomeCidade2[50];
    unsigned long int populacao2;
    float area2, pib2, densidade2, pibPerCapita2, superPoder2;
    int pontosTuristicos2;

    // Cadastro Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("País: "); 
    scanf(" %[^\n]", nomePais1);

    printf("Código (ex: A01): "); 
    scanf(" %s", codigo1);

    printf("Cidade: "); 
    scanf(" %[^\n]", nomeCidade1);

    printf("População: "); 
    scanf(" %lu", &populacao1);

    printf("Área: "); 
    scanf(" %f", &area1);

    printf("PIB: "); 
    scanf(" %f", &pib1);

    printf("Pontos Turísticos: "); 
    scanf(" %d", &pontosTuristicos1);

    // Cadastro Carta 2
    printf("Cadastro da Carta 2:\n");
    printf("País: "); 
    scanf(" %[^\n]", nomePais2);

    printf("Código (ex: B01): "); 
    scanf(" %s", codigo2);

    printf("Cidade: "); 
    scanf(" %[^\n]", nomeCidade2);

    printf("População: "); 
    scanf(" %lu", &populacao2);

    printf("Área: "); 
    scanf(" %f", &area2);

    printf("PIB: "); 
    scanf(" %f", &pib2);

    printf("Pontos Turísticos: "); 
    scanf(" %d", &pontosTuristicos2);

    // Cálculos
    densidade1 = (area1 != 0) ? populacao1 / area1 : 0;
    densidade2 = (area2 != 0) ? populacao2 / area2 : 0;
    pibPerCapita1 = (pib1 * 1000000000.0f) / populacao1;
    pibPerCapita2 = (pib2 * 1000000000.0f) / populacao2;
    superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1.0f / densidade1);
    superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1.0f / densidade2);

    // Escolha dos atributos
    int atributo1 = escolherAtributo(0);
    int atributo2 = escolherAtributo(atributo1);

    // Valores dos atributos
    float valor1_c1 = obterValor(atributo1, populacao1, area1, pib1, pontosTuristicos1, densidade1, pibPerCapita1, superPoder1);
    float valor2_c1 = obterValor(atributo2, populacao1, area1, pib1, pontosTuristicos1, densidade1, pibPerCapita1, superPoder1);
    float valor1_c2 = obterValor(atributo1, populacao2, area2, pib2, pontosTuristicos2, densidade2, pibPerCapita2, superPoder2);
    float valor2_c2 = obterValor(atributo2, populacao2, area2, pib2, pontosTuristicos2, densidade2, pibPerCapita2, superPoder2);

    // Exibição dos resultados
    printf("Resultado da Rodada\n");
    printf("%s (%s):\n  %s: %.2f\n  %s: %.2f\n", nomeCidade1, nomePais1,
           nomeAtributo(atributo1), valor1_c1,
           nomeAtributo(atributo2), valor2_c1);
    printf("%s (%s):\n  %s: %.2f\n  %s: %.2f\n", nomeCidade2, nomePais2,
           nomeAtributo(atributo1), valor1_c2,
           nomeAtributo(atributo2), valor2_c2);

    // Aplicando regra especial da Densidade Populacional
    int densidadeInversa1 = (atributo1 == 5);
    int densidadeInversa2 = (atributo2 == 5);

    float valor1_corrigido_c1 = densidadeInversa1 ? -valor1_c1 : valor1_c1;
    float valor2_corrigido_c1 = densidadeInversa2 ? -valor2_c1 : valor2_c1;
    float valor1_corrigido_c2 = densidadeInversa1 ? -valor1_c2 : valor1_c2;
    float valor2_corrigido_c2 = densidadeInversa2 ? -valor2_c2 : valor2_c2;

    float somaCorrigida1 = valor1_corrigido_c1 + valor2_corrigido_c1;
    float somaCorrigida2 = valor1_corrigido_c2 + valor2_corrigido_c2;

    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", nomeCidade1, somaCorrigida1);
    printf("%s: %.2f\n", nomeCidade2, somaCorrigida2);

    // Resultado final
    printf("Resultado:\n");
    if (somaCorrigida1 == somaCorrigida2)
        printf("Empate!\n");
    else
        printf("Vencedor:%s\n", (somaCorrigida1 > somaCorrigida2) ? nomeCidade1 : nomeCidade2);

    return 0;
}