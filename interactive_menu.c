/*
 * Programa: Benchmark de Algoritmos de Ordenação
 * 
 * Descrição: Este programa permite ao usuário selecionar entre 21 diferentes algoritmos de ordenação para
 *            ordenar um vetor de números aleatórios e medir o tempo de execução do algoritmo escolhido.
 * 
 * Bibliotecas utilizadas:
 *  - stdio.h: para entrada e saída padrão (printf, scanf).
 *  - stdlib.h: para alocação dinâmica de memória (malloc, free) e geração de números aleatórios (rand).
 *  - time.h: para medir o tempo de execução de um algoritmo (clock, CLOCKS_PER_SEC).
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

// Função para exibir o menu de seleção dos algoritmos
void displayMenu() {
    // Imprime as opções de algoritmos para o usuário escolher
    printf("Escolha o algoritmo de ordenação:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Quick Sort\n");
    printf("6. Heap Sort\n");
    printf("7. Counting Sort\n");
    printf("8. Radix Sort\n");
    printf("9. Bucket Sort\n");
    printf("10. Shell Sort\n");
    printf("11. Tim Sort\n");
    printf("12. Comb Sort\n");
    printf("13. Pigeonhole Sort\n");
    printf("14. Cycle Sort\n");
    printf("15. Bitonic Sort\n");
    printf("16. Gnome Sort\n");
    printf("17. Odd-Even Sort\n");
    printf("18. Strand Sort\n");
    printf("19. Patience Sort\n");
    printf("20. Bogo Sort\n");
    printf("21. Stooge Sort\n");
    printf("Digite o número do algoritmo desejado: ");
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
    int size, choice;           // Variáveis para armazenar o tamanho do vetor e a escolha do usuário
    srand(time(0));             // Inicializa o gerador de números aleatórios com base no tempo atual

    // Solicita ao usuário o tamanho do vetor
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);         // Lê o tamanho do vetor

    int *arr = (int *)malloc(size * sizeof(int));  // Aloca dinamicamente memória para o vetor
    generateRandomArray(arr, size);                // Gera um vetor aleatório com o tamanho fornecido

    // Exibe o menu de algoritmos de ordenação
    displayMenu();
    scanf("%d", &choice);       // Lê a escolha do algoritmo feita pelo usuário

    // Verifica se a escolha é válida
    if (choice < 1 || choice > NUM_ALGORITHMS) {
        printf("Escolha inválida!\n");  // Imprime mensagem de erro se a escolha não for válida
    } else {
        // Mede o tempo de execução do algoritmo escolhido
        double timeTaken = measureTime(sortingAlgorithms[choice - 1], arr, size);
        printf("Tempo para o algoritmo %d: %f segundos\n", choice, timeTaken);
    }

    free(arr);  // Libera a memória alocada dinamicamente para o vetor
    return 0;   // Retorna 0, indicando que o programa terminou com sucesso
}
