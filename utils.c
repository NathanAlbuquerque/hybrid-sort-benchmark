#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void gera_vetor(int *arr, int n, int tipo) {
    for (int i = 0; i < n; i++) {
        if (tipo == 1) { // Ordenado
            arr[i] = i;
        } else if (tipo == 2) { // Inverso
            arr[i] = n - i;
        } else { // Aleatório
            arr[i] = rand() % (n * 10);
        }
    }
}

void copia_vetor(int *dest, int *src, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

void imprime_vetor(int *arr, int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}