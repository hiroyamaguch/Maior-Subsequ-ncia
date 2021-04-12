#include "funcoes.h"

int main(int argc, char** argv) {
    /* Instaciamento de variáveis */
    size = 5;
    int v1[size], v2[size], v3[size], v4[size], v5[size], v6[size], v7[size], v8[size], v9[size], v10[size],
            r1[size], r2[size], r3[size], r4[size], r5[size], r6[size], r7[size], r8[size], r9[size], r10[size];

    /* Gerando valores aleatórios para os vetores */
    srand(time(NULL));
    geraValoresAleatorios(v1);
    geraValoresAleatorios(v2);
    geraValoresAleatorios(v3);
    geraValoresAleatorios(v4);
    geraValoresAleatorios(v5);
    geraValoresAleatorios(v6);
    geraValoresAleatorios(v7);
    geraValoresAleatorios(v8);
    geraValoresAleatorios(v9);
    geraValoresAleatorios(v10);


    printf("Printando os resultados obtidos com método em Profundidade\n\n");
    printf(">>Vetor de Entrada (V1): ");
    printProfundidade(v1);

    printf(">>Vetor de Entrada (V2): ");
    printProfundidade(v2);

    printf(">>Vetor de Entrada (V3): ");
    printProfundidade(v3);

    printf(">>Vetor de Entrada (V4): ");
    printProfundidade(v4);

    printf(">>Vetor de Entrada (V5): ");
    printProfundidade(v5);

    printf(">>Vetor de Entrada (V6): ");
    printProfundidade(v6);

    printf(">>Vetor de Entrada (V7): ");
    printProfundidade(v7);

    printf(">>Vetor de Entrada (V8): ");
    printProfundidade(v8);

    printf(">>Vetor de Entrada (V9): ");
    printProfundidade(v9);

    printf(">>Vetor de Entrada (V10): ");
    printProfundidade(v10);

    printfTimeProfundidade();

    printf("\n--------------------------------------------------------------------------------\n");

    printf("Printando os resultados obtidos com método Guloso\n\n");
    printf(">>Vetor de Entrada (V1): ");
    printGuloso(v1, r1);

    printf(">>Vetor de Entrada (V2): ");
    printGuloso(v2, r2);

    printf(">>Vetor de Entrada (V3): ");
    printGuloso(v3, r3);

    printf(">>Vetor de Entrada (V4): ");
    printGuloso(v4, r4);

    printf(">>Vetor de Entrada (V5): ");
    printGuloso(v5, r5);

    printf(">>Vetor de Entrada (V6): ");
    printGuloso(v6, r6);

    printf(">>Vetor de Entrada (V7): ");
    printGuloso(v7, r7);

    printf(">>Vetor de Entrada (V8): ");
    printGuloso(v8, r8);

    printf(">>Vetor de Entrada (V9): ");
    printGuloso(v9, r9);

    printf(">>Vetor de Entrada (V10): ");
    printGuloso(v10, r10);

    printfTimeGuloso();

    return 0;
}