#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"
#include "utils.h"

#define TAMANHO 10000
#define N0 45 // Valor exemplo de n0 (ajustar depois)

int main() {
    srand(time(NULL));

    printf("=== Hybrid Sort Benchmark ===\n");
    printf("Tamanho dos vetores: %d\n", TAMANHO);

    int *vetor_original = (int*)malloc(TAMANHO * sizeof(int));
    int *vetor_teste = (int*)malloc(TAMANHO * sizeof(int));

    gera_vetor(vetor_original, TAMANHO, 2); 
    copia_vetor(vetor_teste, vetor_original, TAMANHO);
    
    clock_t inicio = clock();
    insertionSort(vetor_teste, TAMANHO);
    clock_t fim = clock();

    double tempo_gasto = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo Insertion (Dummy): %f segundos\n", tempo_gasto);

    free(vetor_original);
    free(vetor_teste);

    return 0;
}