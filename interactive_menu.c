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

// Função para exibir o menu
void displayMenu() {
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
    int size, choice;
    srand(time(0)); // Semente para números aleatórios

    // Solicitar o tamanho do vetor ao usuário
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    generateRandomArray(arr, size);

    // Exibir o menu de escolha de algoritmos
    displayMenu();
    scanf("%d", &choice);

    if (choice < 1 || choice > NUM_ALGORITHMS) {
        printf("Escolha inválida!\n");
    } else {
        // Medir o tempo do algoritmo escolhido
        double timeTaken = measureTime(sortingAlgorithms[choice - 1], arr, size);
        printf("Tempo para o algoritmo %d: %f segundos\n", choice, timeTaken);
    }

    free(arr);
    return 0;
}
