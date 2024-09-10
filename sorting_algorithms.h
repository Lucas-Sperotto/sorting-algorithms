// sorting_algorithms.h
#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

// Declarações das funções de ordenação

// Bubble Sort
void bubbleSort(int arr[], int n);

// Selection Sort
void selectionSort(int arr[], int n);

// Insertion Sort
void insertionSort(int arr[], int n);

// Merge Sort
void mergeSort(int arr[], int l, int r);

// Quick Sort
void quickSort(int arr[], int low, int high);

// Heap Sort
void heapSort(int arr[], int n);

// Counting Sort
void countingSort(int arr[], int n, int range);

// Radix Sort
void radixSort(int arr[], int n);

// Bucket Sort
void bucketSort(int arr[], int n);

// Shell Sort
void shellSort(int arr[], int n);

// Tim Sort
void timSort(int arr[], int n);

// Comb Sort
void combSort(int arr[], int n);

// Pigeonhole Sort
void pigeonholeSort(int arr[], int n);

// Cycle Sort
void cycleSort(int arr[], int n);

// Bitonic Sort
void bitonicSort(int arr[], int n);

// Gnome Sort
void gnomeSort(int arr[], int n);

// Odd-Even Sort
void oddEvenSort(int arr[], int n);

// Strand Sort
void strandSort(int arr[], int n);

// Patience Sort
void patienceSort(int arr[], int n);

// Bogo Sort (Cuidado: extremamente ineficiente)
void bogoSort(int arr[], int n);

// Stooge Sort
void stoogeSort(int arr[], int l, int h);

#endif // SORTING_ALGORITHMS_H
