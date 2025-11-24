#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorts.h"
#include "utils.h"

#define REPETICOES_MEDIA 5000

int main() {
    srand(time(NULL));
    
    printf("=== Buscando o N0 (Crossover Point) ===\n");
    printf("Tamanho;Tempo_Insertion;Tempo_Merge;Vencedor\n");

    for (int n = 5; n <= 500; n++) {
        
        double total_insertion = 0;
        double total_merge = 0;

        int *vetor = (int*)malloc(n * sizeof(int));
        int *copia = (int*)malloc(n * sizeof(int));

        for (int r = 0; r < REPETICOES_MEDIA; r++) {
            gera_vetor(vetor, n, 0); 

            copia_vetor(copia, vetor, n);
            clock_t t1 = clock();
            insertionSort(copia, n);
            clock_t t2 = clock();
            total_insertion += (double)(t2 - t1);

            copia_vetor(copia, vetor, n);
            t1 = clock();
            mergeSort(copia, 0, n - 1);
            t2 = clock();
            total_merge += (double)(t2 - t1);
        }

        double tempo_medio_ins = total_insertion / CLOCKS_PER_SEC;
        double tempo_medio_mer = total_merge / CLOCKS_PER_SEC;

        printf("%d;%.6f;%.6f;%s\n", 
            n, 
            tempo_medio_ins, 
            tempo_medio_mer,
            (tempo_medio_ins < tempo_medio_mer) ? "Insertion" : "MERGE VENCEU"
        );

        free(vetor);
        free(copia);
    }

    return 0;
}