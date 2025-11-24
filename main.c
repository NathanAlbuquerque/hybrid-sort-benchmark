#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "sorts.h"
#include "utils.h"

#define TAMANHO 10000
#define REPETICOES 100
#define N0_HIBRIDO 175 // Ajustar

typedef struct {
    double min;
    double max;
    double media;
    double moda;
    double desvio_padrao;
} Estatisticas;

int cmp_func(const void *a, const void *b) {
    double da = *(double*)a;
    double db = *(double*)b;
    return (da > db) - (da < db);
}

Estatisticas calcular_estatisticas(double tempos[], int n) {
    Estatisticas est;
    est.min = tempos[0];
    est.max = tempos[0];
    double soma = 0.0;

    for (int i = 0; i < n; i++) {
        if (tempos[i] < est.min) est.min = tempos[i];
        if (tempos[i] > est.max) est.max = tempos[i];
        soma += tempos[i];
    }
    est.media = soma / n;

    double soma_variancia = 0.0;
    for (int i = 0; i < n; i++) {
        soma_variancia += pow(tempos[i] - est.media, 2);
    }
    est.desvio_padrao = sqrt(soma_variancia / n);

    qsort(tempos, n, sizeof(double), cmp_func);
    
    double moda = tempos[0];
    int max_cont = 1;
    int atual_cont = 1;

    for (int i = 1; i < n; i++) {
        if (fabs(tempos[i] - tempos[i-1]) < 0.000001) {
            atual_cont++;
        } else {
            if (atual_cont > max_cont) {
                max_cont = atual_cont;
                moda = tempos[i-1];
            }
            atual_cont = 1;
        }
    }
    if (atual_cont > max_cont) {
        moda = tempos[n-1];
    }
    est.moda = moda;

    return est;
}

void rodar_cenario(int tipo_vetor, char *nome_cenario) {
    int *vetor_origem = (int*)malloc(TAMANHO * sizeof(int));
    int *vetor_trabalho = (int*)malloc(TAMANHO * sizeof(int));
    double tempos[REPETICOES];
    Estatisticas est;

    printf("\n--- Cenario: %s ---\n", nome_cenario);
    printf("| %-15s | %-10s | %-10s | %-10s | %-10s | %-10s |\n", 
           "Algoritmo", "Min(s)", "Max(s)", "Media(s)", "Moda(s)", "Desvio P.");
    printf("|-----------------|------------|------------|------------|------------|------------|\n");

    gera_vetor(vetor_origem, TAMANHO, tipo_vetor);

    char *nomes_algos[] = {"Insertion", "Merge", "Hibrido"};

    for (int algo = 1; algo <= 3; algo++) {
        
        for (int i = 0; i < REPETICOES; i++) {
            copia_vetor(vetor_trabalho, vetor_origem, TAMANHO);

            clock_t inicio, fim;
            
            inicio = clock();

            if (algo == 1) {
                insertionSort(vetor_trabalho, TAMANHO);
            } else if (algo == 2) {
                mergeSort(vetor_trabalho, 0, TAMANHO - 1);
            } else if (algo == 3) {
                hybridSort(vetor_trabalho, 0, TAMANHO - 1, N0_HIBRIDO);
            }

            fim = clock();

            tempos[i] = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        }

        est = calcular_estatisticas(tempos, REPETICOES);

        printf("| %-15s | %10.6f | %10.6f | %10.6f | %10.6f | %10.6f |\n", 
               nomes_algos[algo-1], est.min, est.max, est.media, est.moda, est.desvio_padrao);
    }
    
    printf("------------------------------------------------------------------------------------\n");

    free(vetor_origem);
    free(vetor_trabalho);
}

int main() {
    srand(time(NULL));

    printf("==================================================\n");
    printf("     HYBRID SORT BENCHMARK (TAMANHO: %d)\n", TAMANHO);
    printf("     REPETICOES POR TESTE: %d\n", REPETICOES);
    printf("     N0 DEFINIDO: %d\n", N0_HIBRIDO);
    printf("==================================================\n");

    rodar_cenario(1, "Vetor ORDENADO");

    rodar_cenario(2, "Vetor INVERSO");

    rodar_cenario(0, "Vetor ALEATORIO");

    return 0;
}