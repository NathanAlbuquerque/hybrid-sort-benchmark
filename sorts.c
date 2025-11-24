#include "sorts.h"

void insertionSort(int *arr, int n) {
    int i, j, temp;

    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

// Função auxiliar que intercala dois subvetores: arr[l..m] e arr[m+1..r]
void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; 
    j = 0; 
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

// Função principal do Merge Sort
void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void hybridSort(int *arr, int l, int r, int k) {
    // Implementar aqui...
}





// #include <stdio.h>
// #include <stdlib.h>

// #define TAM 5

// int vetor[TAM] = {4,1,3,5,2};
// int passos = 0;

// void listar(int v[], int tamanho);

// void merge(int v[], int inicio,int meio, int fim){ //função pra intercalar duas subpartes ordenadas do vetor
//     int i, j, k, n1 = meio - inicio + 1;
//     int n2 = fim - meio;

//     int *esq = malloc(n1 *sizeof(int));
//     int *dir = malloc(n2 *sizeof(int));

//     for (i = 0; i < n1; i++)
//         esq[i] = v[inicio + i];
//     for (j = 0; j < n2; j++)
//         dir[j] = v[meio + 1 + j];

//     i = 0;
//     j = 0;
//     k = inicio;

//     while(i < n1 && j < n2){
//         if (esq[i] <= dir[j])
//             v[k++] = esq[i++];
//         else
//             v[k++] = dir[j++];
//     }

//     while(i < n1)
//         v[k++] = esq[i++];
//     while(j < n2)
//         v[k++] = dir[j++];

//     free(esq);
//     free(dir);
// }

// void mergeSort(int v[], int inicio, int fim){ // função principal
    
//     if(inicio < fim){
//         int meio = inicio + (fim - inicio)/2;
//         mergeSort(v, inicio, meio);
//         mergeSort(v, meio + 1, fim);
//         merge(v, inicio, meio, fim);
//     }

// }

// void listar(int v[], int tamanho){
//   int i;
//   printf("\n\nListando\n");
//   for (i = 0; i < tamanho; i++){
//     printf("%d ", v[i]);
//   }
// }

// int main() {

//   listar(vetor, TAM);
//   mergeSort(vetor, 0, TAM - 1);
//   listar(vetor, TAM);

//   printf("\nPassos: %d\n",passos);
 
//   return (EXIT_SUCCESS);
// }