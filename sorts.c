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

void merge(int *arr, int l, int m, int r) {
    // Implementar aqui...
}

void mergeSort(int *arr, int l, int r) {
    // Implementar aqui...
}

void hybridSort(int *arr, int l, int r, int k) {
    // Implementar aqui...
}
