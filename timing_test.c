/*
 * Programa: Benchmark de Algoritmos de Ordenação com Múltiplos Tamanhos de Vetor
 * 
 * Descrição: Este programa mede o tempo de execução de 21 diferentes algoritmos de ordenação
 *            para vetores de tamanhos variáveis. Ele gera vetores de números aleatórios e calcula
 *            o tempo que cada algoritmo leva para ordenar esses vetores.
 * 
 * Bibliotecas utilizadas:
 *  - stdio.h: para entrada e saída padrão (printf).
 *  - stdlib.h: para alocação dinâmica de memória (malloc, free) e geração de números aleatórios (rand).
 *  - time.h: para medir o tempo de execução (clock, CLOCKS_PER_SEC).
 *  - sorting_algorithms.h: cabeçalhos dos algoritmos de ordenação implementados externamente.
 * 
 * Algoritmos implementados:
 *  - Bubble Sort, Selection Sort, Insertion Sort, Merge Sort, Quick Sort, Heap Sort,
 *    Counting Sort, Radix Sort, Bucket Sort, Shell Sort, Tim Sort, Comb Sort, Pigeonhole Sort,
 *    Cycle Sort, Bitonic Sort, Gnome Sort, Odd-Even Sort, Strand Sort, Patience Sort, Bogo Sort,
 *    Stooge Sort.
 * 
 * Autor: Lucas Kriesel Sperotto
 * Data: 25/09/2024
 */

#include <stdio.h>     // Biblioteca para funções de entrada e saída
#include <stdlib.h>    // Biblioteca para alocação de memória e funções randômicas
#include <time.h>      // Biblioteca para medir o tempo de execução
#include "sorting_algorithms.h"  // Cabeçalhos dos algoritmos de ordenação

#define NUM_ALGORITHMS 21  // Define o número total de algoritmos de ordenação disponíveis

// Função para gerar um vetor de tamanho n com valores aleatórios
void generateRandomArray(int arr[], int n) {
    // Percorre o vetor e atribui um valor aleatório a cada posição
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % n;  // Gera números aleatórios entre 0 e n-1
    }
}

// Função para medir o tempo de execução de um algoritmo de ordenação
double measureTime(void (*sortFunc)(int[], int), int arr[], int n) {
    clock_t start, end;  // Variáveis para armazenar o tempo inicial e final
    start = clock();     // Armazena o tempo inicial antes da execução do algoritmo
    sortFunc(arr, n);    // Executa o algoritmo de ordenação
    end = clock();       // Armazena o tempo após a execução do algoritmo
    // Retorna o tempo gasto em segundos
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// Vetor de ponteiros para funções, armazenando os algoritmos de ordenação
void (*sortingAlgorithms[NUM_ALGORITHMS])(int[], int) = {
    bubbleSort, selectionSort, insertionSort, mergeSort, quickSort,
    heapSort, countingSort, radixSort, bucketSort, shellSort,
    timSort, combSort, pigeonholeSort, cycleSort, bitonicSort,
    gnomeSort, oddEvenSort, strandSort, patienceSort, bogoSort, stoogeSort
};

// Função principal
int main() {
    // Vetor contendo os diferentes tamanhos de vetores que serão ordenados
    int sizes[] = {10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);  // Calcula o número de diferentes tamanhos de vetores

    srand(time(0));  // Inicializa o gerador de números aleatórios com base no tempo atual

    // Loop para testar cada tamanho de vetor
    for (int i = 0; i < numSizes; i++) {
        int size = sizes[i];  // Pega o tamanho atual do vetor
        printf("Tamanho do vetor: %d\n", size);  // Imprime o tamanho do vetor

        // Loop para testar cada algoritmo de ordenação
        for (int j = 0; j < NUM_ALGORITHMS; j++) {
            int *arr = (int *)malloc(size * sizeof(int));  // Aloca dinamicamente memória para o vetor
            generateRandomArray(arr, size);                // Gera um vetor aleatório com o tamanho fornecido

            // Medir o tempo de execução do algoritmo j
            double timeTaken = measureTime(sortingAlgorithms[j], arr, size);
            printf("Algoritmo %d - Tempo: %f segundos\n", j + 1, timeTaken);  // Exibe o tempo gasto pelo algoritmo

            free(arr);  // Libera a memória alocada dinamicamente para o vetor
        }

        printf("\n");  // Imprime uma linha em branco para separar os resultados dos diferentes tamanhos
    }

    return 0;  // Retorna 0, indicando que o programa terminou com sucesso
}
