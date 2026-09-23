#include <stdio.h>

int main() {
    float limiteTemp;
    float tempAtual;
    float somaTemp = 0.0;
    float maiorTemp = 0.0;
    float menorTemp = 0.0;
    
    int totalLeituras = 0;
    int consecutivasAcima = 0;
    int totalAcima = 0;
    
    printf("=== SISTEMA DE MONITORAMENTO DE TEMPERATURA ===\n\n");

    // verificacão do limite de temperatura usando do while
   
    do {
        printf("Digite o limite de temperatura permitido (-50 a 150 C): ");
        scanf("%f", &limiteTemp);

        if (limiteTemp < -50.0 || limiteTemp > 150.0) {
            printf("Valor invalido! Digite um limite valido.\n");
        }
    } while (limiteTemp < -50.0 || limiteTemp > 150.0);

    printf("\nLimite definido em: %.2f C\n", limiteTemp);
    printf("Iniciando leituras... (3 temperaturas consecutivas acima do limite encerram o programa)\n\n");

    // Laco principal de leitura usando while
    
    while (consecutivasAcima < 3) {
        printf("digite a temperatura %d: ", totalLeituras + 1);
        scanf("%f", &tempAtual);

        // Validação de entrada para leituras acima de 200
        if (tempAtual < -100.0 || tempAtual > 200.0) {
            printf("Entrada invalida! Temperatura ignorada. Tente novamente.\n");
            continue; // Pula o resto da repetição e pede novamente
        }

        // se for a primeira leitura, inicializa o maior e menor com o valor atual
        if (totalLeituras == 0) {
            maiorTemp = tempAtual;
            menorTemp = tempAtual;
        } else {
            // Atualiza qual foi a maior ou menor temperatura do progama 
            if (tempAtual > maiorTemp) {
                maiorTemp = tempAtual;
            }
            if (tempAtual < menorTemp) {
                menorTemp = tempAtual;
            }
        }

        // atualiza acumuladores gerais
        somaTemp = somaTemp + tempAtual;
        totalLeituras++;

        // verifica se a temperatura esta acima do limite e emite o alerta 
        if (tempAtual > limiteTemp) {
            consecutivasAcima++;
            totalAcima++;
            printf("--> ALERTA: Temperatura acima do limite! (%d/3 consecutivas)\n", consecutivasAcima);
        } else {
            // else para se a temperatura voltar ao normal, reinicia a contagem de consecutivas do progama 
            consecutivasAcima = 0;
            printf("--> Temperatura normal.\n");
        }
    }

    // Contas para fazer o relatorio final 
    float media = somaTemp / totalLeituras;
    float percentualAcima = ((float)totalAcima / totalLeituras) * 100.0;

    // relatorio Final
    printf("     RELATORIO DE MONITORAMENTO     \n");
    printf("====================================\n");
    printf("Alerta: 3 temperaturas consecutivas acima do limite atingidas!\n");
    printf("Total de leituras realizadas: %d\n", totalLeituras);
    printf("Media das temperaturas: %.2f C\n", media);
    printf("Maior temperatura registrada: %.2f C\n", maiorTemp);
    printf("Menor temperatura registrada: %.2f C\n", menorTemp);
    printf("Quantidade de leituras acima do limite: %d\n", totalAcima);
    printf("Percentual acima do limite: %.2f%%\n", percentualAcima);
    printf("====================================\n");

    return 0;
}
