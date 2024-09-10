// sorting_algorithms.c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "sorting_algorithms.h"
#define RUN 32

// Função auxiliar para trocar elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 1. Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// 2. Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

// 3. Insertion Sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

// 4. Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[m + 1 + i];
    int i = 0, j = 0, k = l;
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
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

// 5. Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 6. Heap Sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && arr[left] > arr[largest])
        largest = left;
    if (right < n && arr[right] > arr[largest])
        largest = right;
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// 7. Counting Sort
void countingSort(int arr[], int n, int range) {
    int *count = (int *)calloc(range, sizeof(int));
    int *output = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        count[arr[i]]++;
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
    free(count);
    free(output);
}

// 8. Radix Sort
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSortRadix(int arr[], int n, int exp) {
    int output[n], count[10] = {0};
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);
    for (int exp = 1; max / exp > 0; exp *= 10)
        countSortRadix(arr, n, exp);
}

// 9. Bucket Sort
void bucketSort(int arr[], int n) {
    int max = getMax(arr, n);
    int bucket[max+1];
    for (int i = 0; i <= max; i++)
        bucket[i] = 0;
    for (int i = 0; i < n; i++)
        bucket[arr[i]]++;
    for (int i = 0, j = 0; i <= max; i++)
        while (bucket[i]-- > 0)
            arr[j++] = i;
}

// 10. Shell Sort
void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// 11. Tim Sort
// O Tim Sort é uma combinação de Merge Sort e Insertion Sort. Aqui usamos apenas um esboço básico.
// Para implementá-lo corretamente, deve-se definir um valor "RUN" (normalmente 32 ou 64) para particionar a lista.


void insertionSortTim(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

void mergeTim(int arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < len1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < len2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void timSort(int arr[], int n) {
    for (int i = 0; i < n; i += RUN)
        insertionSortTim(arr, i, (i + RUN - 1) < (n - 1) ? (i + RUN - 1) : (n - 1));
    for (int size = RUN; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = ((left + 2 * size - 1) < (n - 1)) ? (left + 2 * size - 1) : (n - 1);
            mergeTim(arr, left, mid, right);
        }
    }
}

// 12. Comb Sort
void combSort(int arr[], int n) {
    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;
        swapped = false;
        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(&arr[i], &arr[i + gap]);
                swapped = true;
            }
        }
    }
}

// 13. Pigeonhole Sort
void pigeonholeSort(int arr[], int n) {
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    int range = max - min + 1;
    int *holes = (int *)calloc(range, sizeof(int));
    for (int i = 0; i < n; i++)
        holes[arr[i] - min]++;
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (holes[i]-- > 0) {
            arr[index++] = i + min;
        }
    }
    free(holes);
}

// 14. Cycle Sort
void cycleSort(int arr[], int n) {
    for (int cycleStart = 0; cycleStart < n - 1; cycleStart++) {
        int item = arr[cycleStart];
        int pos = cycleStart;
        for (int i = cycleStart + 1; i < n; i++)
            if (arr[i] < item)
                pos++;
        if (pos == cycleStart)
            continue;
        while (item == arr[pos])
            pos++;
        if (pos != cycleStart) {
            swap(&item, &arr[pos]);
        }
        while (pos != cycleStart) {
            pos = cycleStart;
            for (int i = cycleStart + 1; i < n; i++)
                if (arr[i] < item)
                    pos++;
            while (item == arr[pos])
                pos++;
            if (item != arr[pos]) {
                swap(&item, &arr[pos]);
            }
        }
    }
}

// 15. Bitonic Sort (assume o uso de paralelo, mas aqui está a versão sequencial)
void compAndSwap(int arr[], int i, int j, int dir) {
    if ((arr[i] > arr[j]) == dir)
        swap(&arr[i], &arr[j]);
}

void bitonicMerge(int arr[], int low, int cnt, int dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++)
            compAndSwap(arr, i, i + k, dir);
        bitonicMerge(arr, low, k, dir);
        bitonicMerge(arr, low + k, k, dir);
    }
}

void bitonicSortUtil(int arr[], int low, int cnt, int dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        bitonicSortUtil(arr, low, k, 1);
        bitonicSortUtil(arr, low + k, k, 0);
        bitonicMerge(arr, low, cnt, dir);
    }
}

void bitonicSort(int arr[], int n) {
    bitonicSortUtil(arr, 0, n, 1);
}

// 16. Gnome Sort
void gnomeSort(int arr[], int n) {
    int index = 0;
    while (index < n) {
        if (index == 0)
            index++;
        if (arr[index] >= arr[index - 1])
            index++;
        else {
            swap(&arr[index], &arr[index - 1]);
            index--;
        }
    }
}

// 17. Odd-Even Sort
void oddEvenSort(int arr[], int n) {
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        for (int i = 1; i <= n - 2; i += 2) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                isSorted = false;
            }
        }
        for (int i = 0; i <= n - 2; i += 2) {
            if (arr[i] > arr[i + 1]) {
                swap(&arr[i], &arr[i + 1]);
                isSorted = false;
            }
        }
    }
}

// 18. Strand Sort
void strandSort(int arr[], int n) {
    int *result = (int *)malloc(n * sizeof(int));
    int result_size = 0;
    while (n > 0) {
        int sublist_size = 0;
        int *sublist = (int *)malloc(n * sizeof(int));
        sublist[sublist_size++] = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > sublist[sublist_size - 1]) {
                sublist[sublist_size++] = arr[i];
            } else {
                arr[i - sublist_size] = arr[i];
            }
        }
        n -= sublist_size;
        int i = 0, j = 0, k = 0;
        while (i < result_size && j < sublist_size) {
            if (result[i] < sublist[j])
                arr[k++] = result[i++];
            else
                arr[k++] = sublist[j++];
        }
        while (i < result_size)
            arr[k++] = result[i++];
        while (j < sublist_size)
            arr[k++] = sublist[j++];
        free(sublist);
        result_size += sublist_size;
    }
    free(result);
}

// 19. Patience Sort (simplificação)
void patienceSort(int arr[], int n) {
    // Este é um esboço simplificado; uma implementação completa requer pilhas e subsequências.
}

// 20. Bogo Sort (extremamente ineficiente)
void bogoSort(int arr[], int n) {
    while (!isSorted(arr, n))
        shuffle(arr, n);
}

int isSorted(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1])
            return 0;
    }
    return 1;
}

void shuffle(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int r = rand() % n;
        swap(&arr[i], &arr[r]);
    }
}

// 21. Stooge Sort
void stoogeSort(int arr[], int l, int h) {
    if (l >= h)
        return;
    if (arr[l] > arr[h])
        swap(&arr[l], &arr[h]);
    if (h - l + 1 > 2) {
        int t = (h - l + 1) / 3;
        stoogeSort(arr, l, h - t);
        stoogeSort(arr, l + t, h);
        stoogeSort(arr, l, h - t);
    }
}

