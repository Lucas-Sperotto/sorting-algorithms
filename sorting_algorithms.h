/*
 * Arquivo: sorting_algorithms.h
 * 
 * Descrição: Este arquivo contém as declarações de 21 diferentes funções de ordenação,
 *            cada uma implementando um algoritmo de ordenação específico.
 * 
 * Observações: Alguns algoritmos, como o Bogo Sort, são extremamente ineficientes e
 *              são incluídos por motivos didáticos. Cada função tem uma breve explicação
 *              sobre seu objetivo e as variações de parâmetros conforme necessário.
 * 
 * Autor: Lucas Kriesel Sperotto
 * Data: 25/09/2024
 */

#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

// Declarações das funções de ordenação

// Bubble Sort: Algoritmo simples de ordenação que compara e troca elementos adjacentes.
void bubbleSort(int arr[], int n);

// Selection Sort: Algoritmo que seleciona o menor elemento e o coloca em sua posição correta.
void selectionSort(int arr[], int n);

// Insertion Sort: Algoritmo que insere elementos em suas posições corretas em um vetor já parcialmente ordenado.
void insertionSort(int arr[], int n);

// Merge Sort: Algoritmo recursivo de divisão e conquista, que divide o vetor em duas metades e as ordena separadamente.
void mergeSort(int arr[], int l, int r);

// Quick Sort: Algoritmo de divisão e conquista que seleciona um pivô e particiona o vetor ao redor do pivô.
void quickSort(int arr[], int low, int high);

// Heap Sort: Algoritmo baseado na estrutura de dados heap, que constrói um heap e ordena o vetor.
void heapSort(int arr[], int n);

// Counting Sort: Algoritmo de ordenação não-comparativa, ideal para valores inteiros limitados por um intervalo (range).
void countingSort(int arr[], int n, int range);

// Radix Sort: Algoritmo de ordenação que ordena números inteiros com base em dígitos, começando pelo dígito menos significativo.
void radixSort(int arr[], int n);

// Bucket Sort: Algoritmo que distribui os elementos em baldes (buckets) e os ordena individualmente.
void bucketSort(int arr[], int n);

// Shell Sort: Algoritmo de ordenação que utiliza a técnica de "gap", generalizando o Insertion Sort.
void shellSort(int arr[], int n);

// Tim Sort: Algoritmo de ordenação híbrido baseado em Merge Sort e Insertion Sort, utilizado na biblioteca padrão do Python.
void timSort(int arr[], int n);

// Comb Sort: Variante do Bubble Sort que compara e troca elementos com um intervalo (gap) decrescente.
void combSort(int arr[], int n);

// Pigeonhole Sort: Algoritmo adequado para ordenar listas onde os elementos têm um número limitado de valores possíveis.
void pigeonholeSort(int arr[], int n);

// Cycle Sort: Algoritmo que minimiza o número de trocas para conseguir a ordenação.
void cycleSort(int arr[], int n);

// Bitonic Sort: Algoritmo paralelo que divide o vetor em subpartes bitônicas e as ordena.
void bitonicSort(int arr[], int n);

// Gnome Sort: Algoritmo semelhante ao Insertion Sort, mas com uma abordagem diferente para mover os elementos.
void gnomeSort(int arr[], int n);

// Odd-Even Sort: Algoritmo que funciona comparando e trocando pares de elementos adjacentes, semelhante ao Bubble Sort.
void oddEvenSort(int arr[], int n);

// Strand Sort: Algoritmo que constrói uma lista ordenada removendo subsequências ordenadas do vetor original.
void strandSort(int arr[], int n);

// Patience Sort: Algoritmo inspirado no jogo de cartas paciência, utilizado para encontrar subsequências ordenadas.
void patienceSort(int arr[], int n);

// Bogo Sort: Algoritmo extremamente ineficiente que tenta ordenar o vetor de forma aleatória até que ele esteja ordenado.
void bogoSort(int arr[], int n);

// Stooge Sort: Algoritmo recursivo ineficiente que ordena os elementos trocando-os em intervalos específicos.
void stoogeSort(int arr[], int l, int h);

#endif // SORTING_ALGORITHMS_H
