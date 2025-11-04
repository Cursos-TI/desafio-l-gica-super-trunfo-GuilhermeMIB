#include <stdio.h>

int main() {
    // Declaração das variáveis da Carta 1
    char estado1;
    char codigo1[4];
    char nomeCidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidade1;
    float pibPerCapita1;
    float superPoder1;

    // Declaração das variáveis da Carta 2
    char estado2;
    char codigo2[4];
    char nomeCidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2;
    float pibPerCapita2;
    float superPoder2;

    // Entrada de dados da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Digite o Estado (A-H): "); 
    scanf(" %c", &estado1);

    printf("Digite o Código da Carta (ex: A01): "); 
    scanf("%s", codigo1);

    printf("Digite o Nome da Cidade: "); 
    scanf(" %[^\n]", nomeCidade1);

    printf("Digite a População: "); 
    scanf("%lu", &populacao1);

    printf("Digite a Área (em km²): "); 
    scanf("%f", &area1);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &pontosTuristicos1);

    // Entrada de dados da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Digite o Estado (A-H): "); 
    scanf(" %c", &estado2);

    printf("Digite o Código da Carta (ex: B02): "); 
    scanf("%s", codigo2);

    printf("Digite o Nome da Cidade: "); 
    scanf(" %[^\n]", nomeCidade2);

    printf("Digite a População: "); 
    scanf("%lu", &populacao2);

    printf("Digite a Área (em km²): "); 
    scanf("%f", &area2);

    printf("Digite o PIB (em bilhões de reais): "); 
    scanf("%f", &pib2);

    printf("Digite o Número de Pontos Turísticos: "); 
    scanf("%d", &pontosTuristicos2);

    // Cálculos
    densidade1 = populacao1 / area1;
    densidade2 = populacao2 / area2;

    pibPerCapita1 = (pib1 * 1000000000.0f) / populacao1;
    pibPerCapita2 = (pib2 * 1000000000.0f) / populacao2;

    superPoder1 = populacao1 + area1 + pib1 + pontosTuristicos1 + pibPerCapita1 + (1.0f / densidade1);
    superPoder2 = populacao2 + area2 + pib2 + pontosTuristicos2 + pibPerCapita2 + (1.0f / densidade2);

    // Exibição dos dados
    printf("\n--- Dados das Cartas ---\n");

    printf("\nCarta 1 - %s (%c):\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos Turísticos: %d\nDensidade: %.2f hab/km²\nPIB per Capita: %.2f R$\nSuper Poder: %.2f\n",
        nomeCidade1, estado1, populacao1, area1, pib1, pontosTuristicos1, densidade1, pibPerCapita1, superPoder1);

    printf("\nCarta 2 - %s (%c):\nPopulação: %lu\nÁrea: %.2f km²\nPIB: %.2f bilhões\nPontos Turísticos: %d\nDensidade: %.2f hab/km²\nPIB per Capita: %.2f R$\nSuper Poder: %.2f\n",
        nomeCidade2, estado2, populacao2, area2, pib2, pontosTuristicos2, densidade2, pibPerCapita2, superPoder2);

    // Escolha do atributo
    int atributo;
    printf("\nEscolha o atributo para comparar:\n");

    printf("1 - População\n 2 - Área\n 3 - PIB\n 4 - Pontos Turísticos\n 5 - Densidade Populacional\n 6 - PIB per Capita\n 7 - Super Poder\n");

    printf("Digite o número do atributo: ");
    scanf("%d", &atributo);

   // Comparação
printf("\n--- Comparação ---\n");

if (atributo == 1) {
    printf("População:\n%s: %lu\n%s: %lu\n", nomeCidade1, populacao1, nomeCidade2, populacao2);
    if (populacao1 > populacao2)
        printf("Vencedora: %s\n", nomeCidade1);
    else if (populacao2 > populacao1)
        printf("Vencedora: %s\n", nomeCidade2);
    else
        printf("Empate!\n");

} else if (atributo == 2) {
    printf("Área:\n%s: %.2f km²\n%s: %.2f km²\n", nomeCidade1, area1, nomeCidade2, area2);
    if (area1 > area2)
        printf("Vencedora: %s\n", nomeCidade1);
    else if (area2 > area1)
        printf("Vencedora: %s\n", nomeCidade2);
    else
        printf("Empate!\n");

} else if (atributo == 3) {
    printf("PIB:\n%s: %.2f bilhões\n%s: %.2f bilhões\n", nomeCidade1, pib1, nomeCidade2, pib2);
    if (pib1 > pib2)
        printf("Vencedora: %s\n", nomeCidade1);
    else if (pib2 > pib1)
        printf("Vencedora: %s\n", nomeCidade2);
    else
        printf("Empate!\n");

} else if (atributo == 4) {
    printf("Pontos Turísticos:\n%s: %d\n%s: %d\n", nomeCidade1, pontosTuristicos1, nomeCidade2, pontosTuristicos2);
    if (pontosTuristicos1 > pontosTuristicos2)
        printf("Vencedora: %s\n", nomeCidade1);
    else if (pontosTuristicos2 > pontosTuristicos1)
        printf("Vencedora: %s\n", nomeCidade2);
    else
        printf("Empate!\n");

} else if (atributo == 5) {
    printf("Densidade Populacional:\n%s: %.2f\n%s: %.2f\n", nomeCidade1, densidade1, nomeCidade2, densidade2);
    if (densidade1 < densidade2)
        printf("Vencedora: %s\n", nomeCidade1);
    else if (densidade2 < densidade1)
        printf("Vencedora: %s\n", nomeCidade2);
    else
        printf("Empate!\n");

} else if (atributo == 6) {
    printf("PIB per Capita:\n%s: %.2f R$\n%s: %.2f R$\n", nomeCidade1, pibPerCapita1, nomeCidade2, pibPerCapita2);
    if (pibPerCapita1 > pibPerCapita2)
        printf("Vencedora: %s\n", nomeCidade1);
    else if (pibPerCapita2 > pibPerCapita1)
        printf("Vencedora: %s\n", nomeCidade2);
    else
        printf("Empate!\n");

} else if (atributo == 7) {
    printf("Super Poder:\n%s: %.2f\n%s: %.2f\n", nomeCidade1, superPoder1, nomeCidade2, superPoder2);
    if (superPoder1 > superPoder2)
        printf("Vencedora: %s\n", nomeCidade1);
    else if (superPoder2 > superPoder1)
        printf("Vencedora: %s\n", nomeCidade2);
    else
        printf("Empate!\n");

    } else {
        printf("Atributo inválido!\n");
    }

    return 0;
}