#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sorting_algorithms.h"

#define NUM_ALGORITHMS 21

// Função para gerar um vetor de tamanho n com valores aleatórios
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;
    }
}

// Função para medir o tempo de execução
double measureTime(void (*sortFunc)(int[], int), int arr[], int n) {
    clock_t start, end;
    start = clock();
    sortFunc(arr, n);
    end = clock();
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Lista de algoritmos de ordenação
void (*sortingAlgorithms[NUM_ALGORITHMS])(int[], int) = {
    bubbleSort, selectionSort, insertionSort, mergeSort, quickSort,
    heapSort, countingSort, radixSort, bucketSort, shellSort,
    timSort, combSort, pigeonholeSort, cycleSort, bitonicSort,
    gnomeSort, oddEvenSort, strandSort, patienceSort, bogoSort, stoogeSort
};

// Função principal
int main() {
    int sizes[] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);

    srand(time(0)); // Semente para números aleatórios

    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];
        printf("Tamanho do vetor: %d\n", size);
        for (int j = 0; j < NUM_ALGORITHMS; j++) {
            int *arr = (int *)malloc(size * sizeof(int));
            generateRandomArray(arr, size);

            // Medir o tempo do algoritmo j
            double timeTaken = measureTime(sortingAlgorithms[j], arr, size);
            printf("Algoritmo %d - Tempo: %f segundos\n", j + 1, timeTaken);

            free(arr);
        }
        printf("\n");
    }

    return 0;
}
