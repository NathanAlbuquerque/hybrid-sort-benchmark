#include "sorts.h"

void insertionSort(int *arr, int n) {
    // Implementar aqui...
}

void merge(int *arr, int l, int m, int r) {
    // Implementar aqui...
}

void mergeSort(int *arr, int l, int r) {
    // Implementar aqui...
}

void hybridSort(int *arr, int l, int r, int k) {
    // Implementar aqui...
}




// Código de insertionSort enviodo pelo Jonathan para referência:

// #include <stdio.h>
// #include <stdlib.h>

// #define TAM 5

// int vetor[TAM] = {5,4,3,2,1};
// int passos = 0;


// void listar(int v[], int tamanho);

// void insertSort(int v[], int tamanho){
//   int temp,j;

//   for (int i = 1; i < tamanho; i++){
//     temp = v[i];
//     j = i - 1;
//     while (j >= 0 && temp < v[j]){
//       passos++;
//       v[j + 1] = v[j];
//       j--;
//     }
//     v[j + 1] = temp;
//   }
// }

// void listar(int v[], int tamanho){
//   int i;
//   printf("\n\nListando\n");
//   for (i = 0; i < tamanho; i++){
//     printf("%d ", v[i]);
//   }
// }

// int main(int argc, char** argv) {

//   listar(vetor, TAM);
//   insertSort(vetor, TAM);
//   listar(vetor, TAM);

//   printf("\nPassos: %d\n",passos);


 
//   return (EXIT_SUCCESS);
// }
