#ifndef FUN_H
#define FUN_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

    int sg = 0, sl = 0, level = 0, maxLevel = 0, size, aux[100];
    float tg[10], tl[10];
    clock_t ti, tf;

    /* Gera valores aleatórios para o vetor */
    void geraValoresAleatorios(int vetor[]) {
        for (int i = 0; i < size; i++)
            vetor[i] = (rand() % 10);
    }

    /* Busca a posicao do maior valor em um vetor */
    int buscaMaiorValor(int vetor[], int posicaoInicial) {
        int maiorValor = 0, posicao = -1;
        for (int i = posicaoInicial; i < size; i++) {
            if (maiorValor < vetor[i]) {
                maiorValor = vetor[i];
                posicao = i;
            }
        }
        if (posicao == -1)
            return posicaoInicial;
        return posicao;
    }

    /* Calcula a maior subsequência - GULOSO */
    int guloso(int vetor[], int maiorSubs[]) {
        ti = clock();
        //adja = adjacências, maiorSubs = maiorSubsequência 
        int matriz[size][size], adja[size], sizeSubs = 0, posNow = 0, maiorAjda = 0, colunNow;

        //Zera os valores do vetor adjascente 
        for (int i = 0; i < size; i++)
            adja[i] = 0;

        //Monta uma matriz para verificar se o valor da coluna é maior que o da linha e armazena a soma em um vetor
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (j > i) {
                    if (vetor[j] > vetor[i]) {
                        matriz[i][j] = 1;
                        adja[i]++;
                    } else
                        matriz[i][j] = 0;
                } else
                    matriz[i][j] = 0;
            }
        }

        //Imprime os valores da matriz
        printf("\n");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++)
                printf(" %d ", matriz[i][j]);
            printf("\n");
        }

        //Busca a maior subsequência
        int first = buscaMaiorValor(adja, 0);
        maiorSubs[sizeSubs] = vetor[first];
        posNow = first;
        int posNext = posNow + 1;
        colunNow = first;

        do {
            colunNow = posNow;
            maiorAjda = -1;
            for (int i = posNext; i < size; i++) {
                if (adja[i] > maiorAjda && matriz[colunNow][i] == 1) {
                    maiorAjda = adja[i];
                    posNow = i;
                }
            }
            sizeSubs = sizeSubs + 1;
            maiorSubs[sizeSubs] = vetor[posNow];
            posNext = posNow + 1;
        } while (adja[posNow] != 0);

        tf = clock();
        tg[sg] = ((float) (tf - ti)*1000) / CLOCKS_PER_SEC;
        //printf("Tempo Guloso: %f ms", tg[sg]);
        sg++;

        return sizeSubs + 1;
    }

    /* Calcula a maior subsequência em relação a uma posição do vetor - Busca em Profundidade */
    void profundidadePos(int vetor[], int start) {
        /* Incrementa quando aumentamos a profundidade do grafo*/
        aux[level] = vetor[start];
        level++;
        
        /* Monta o grafo na tela do usuário*/
        printf("\n");
        for (int i = 0; i < level; i++)
            printf(" %d ", aux[i]);
        
        /* Verifica se é nível mais profundo que foi alcançado  e printa a maior sequência encontrada até o nível atual */
        if (level > maxLevel)
            maxLevel = level;

        /* Verifica se têm um nível mais profundo */
        for (int i = start; i < size - 1; i++)
            if (vetor[start] < vetor[i + 1])
                profundidadePos(vetor, i + 1);

        /* Decrementa quando retornamos para o vértice pai */
        level--;
        aux[level] = 0;
    }

    /* Calcula a maior subsequência em relação a todas as posições do vetor - Busca em Profundidade */
    int profundidade(int vetor[]) {
        /* Procurando a maior subsequência */
        ti = clock();
        for (int i = 0; i < size - 1; i++){
            printf("\n>>>>>>>>>> Grafo n%d <<<<<<<<<\n", i + 1);
            profundidadePos(vetor, i);
        }
        tf = clock();
        tl[sl] = ((float) (tf - ti)*1000) / CLOCKS_PER_SEC;
        //printf("Tempo Largura: %f ms ", tl[sl]);
        sl++;

        /* Pegando o tamanho da maior subsequência */
        int tamanho = maxLevel;
        maxLevel = 0;
        return tamanho;
    }

    void printGuloso(int vetor[], int resposta[]) {
        for (int i = 0; i < size; i++)
            printf("%d ", vetor[i]);
        int tamanho = guloso(vetor, resposta);
        printf("  //  Maior subsequencia: ");
        for (int i = 0; i < tamanho; i++)
            printf("%d ", resposta[i]);
        printf("  //  Tamanho: %d\n\n", tamanho);
    }

    void printProfundidade(int vetor[]) {
        for (int i = 0; i < size; i++)
            printf("%d ", vetor[i]);
        printf("  //  Grafo utilizado para resolução: \n");
        int tamanho = profundidade(vetor);
        printf("\n//  Tamanho: %d\n\n", tamanho);
    }

    void printfTimeGuloso() {
        float total = 0;
        for (int i = 0; i < sg; i++)
            total = total + tg[i];
        printf("  //  O tempo total do guloso foi: %f ms", total);
    }

    void printfTimeProfundidade() {
        float total = 0;
        for (int i = 0; i < sl; i++)
            total = total + tl[i];
        printf("  //  O tempo total da busca em profundidade foi: %f ms", total);
    }
}
#ifdef __cplusplus
#endif

#endif /* FUN_H */

