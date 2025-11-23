#ifndef SORTS_H
#define SORTS_H

// Insertion Sort
void insertionSort(int *arr, int n);

// Merge Sort
void mergeSort(int *arr, int l, int r);
void merge(int *arr, int l, int m, int r);

// Hybrid Sort (Merge + Insertion)
void hybridSort(int *arr, int l, int r, int k); // k é o n0

#endif