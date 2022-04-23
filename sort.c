#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "utils.h"

/* BUBBLESORT(arr, size):
 *     noSwap = false
 *     while (not noSwap):
 *         noSwap = true
 *         for i = 0; i < size - 1; i += 1:
 *             if arr[i + 1] < arr[i]:
 *                 swap(arr[i + 1], arr[i]);
 *                 noSwap = false
 */
void bubbleSort(int *arr, size_t size) {
    char noSwap = 0;
    int *i;
    while (!noSwap) {
        noSwap = 1;
        for (i = arr; i < arr + size; i++) {
            if (*(i + 1) < *i) {
                intSwap(i, i + 1);
                noSwap = 0;
            }
        }
    }
}

/* SELECTIONSORT(arr, size):
 *     for i = 0; i < size - 1; i += 1:
 *         min = i
 *         for j = i + 1; j < size - 1; j += 1:
 *             if arr[j] < arr[minimum]:
 *                 minimum = j
 *         swap(arr[i], arr[minimum])
 */
void selectionSort(int *arr, size_t size) {
    int *minimum, *i, *j;
    for (i = arr; i < arr + size; i++) {
        minimum = i;
        for (j = i + 1; j < arr + size; j++)
            if (*j < *minimum)
                minimum = j;
        intSwap(i, minimum);
    }
}

/* INSERTIONSORT(arr, size):
 *     for i = 1; i < size; i += 1:
 *         key = arr[i]
 *         for j = i - 1; j >= 0 and key < arr[j] j -= 1:
 *             arr[j + 1] = arr[j]
 *         arr[j + 1] = key
 */
void insertionSort(int *arr, size_t size) {
    int *i, *j, key;
    for (i = arr + 1; i <= arr + size - 1; i++) {
        key = *i;
        for (j = i - 1; j >= arr && key < *j; j--) {
            *(j + 1) = *j;
        }
        *(j + 1) = key;
    }
}

/*
 * MERGE(arr, p, q, r):
 *     n1 = len(arr[p..q])
 *     n2 = len(arr[q+1..r])
 *     L = copy(arr[p..q])
 *     M = copy(arr[q+1..r])
 *     i = j = 0
 *     k = p
 *     while i < n1 && j < n2:
 *         if (L[i] > M[i]):
 *             arr[k] = L[i]
 *             i += 1
 *         else:
 *             arr[k] = M[i]
 *             j += 1
 *         k += 1
 *     while i < n1:
 *         arr[k] = L[i]
 *         i += 1
 *     while j < n1:
 *         arr[k] = M[j]
 *         j += 1
 * 
 * __MERGESORT__(arr, l, r):
 *     if r < l:
 *         return
 *     m = l + (r - l) / 2
 *     __MERGESORT__(arr, l, m)
 *     __MERGESORT__(arr, m + 1, r)
 *     MERGE(arr, l, m, r)
 * 
 * MERGESORT(arr, size)
 *     __MERGESORT__(arr, 0, size - 1)
 */
void merge(int *arr, int p, int q, int r) {
    size_t n1 = q - p + 1, n2 = r - q;
    int L[n1], M[n2];
    memcpy(L, arr + p, n1 * sizeof(int));
    memcpy(M, arr + q + 1, n2 * sizeof(int));
    int *i = L, *j = M, *k = arr + p, *iE = L + n1, *jE = M + n2;
    while ((i < iE) && (j < jE)) {
        if (*i < *j) {
            *k = *i;
            i++;
        } else {
            *k = *j;
            j++;
        }
        k++;
    }
    while (i < iE) {
        *k = *i;
        k++;
        i++;
    }
    while (j < jE) {
        *k = *j;
        k++;
        j++;
    }
}

void __mergeSort__(int *arr, int l, int r) {
    if (r <= l) return;
    int m = l + (r - l) / 2;
    __mergeSort__(arr, l, m); 
    __mergeSort__(arr, m + 1, r);
    merge(arr, l, m, r);
}

void mergeSort(int *arr, size_t size) {
    __mergeSort__(arr, 0, size - 1);
}

/*
 * partition(array, leftmostIndex, rightmostIndex)
 *   set rightmostIndex as pivotIndex
 *   storeIndex <- leftmostIndex - 1
 *   for i <- leftmostIndex + 1 to rightmostIndex
 *   if element[i] < pivotElement
 *     swap element[i] and element[storeIndex]
 *     storeIndex++
 *   swap pivotElement and element[storeIndex+1]
 * return storeIndex + 1
 * 
 * __quickSort__(array, leftmostIndex, rightmostIndex)
 *   if (leftmostIndex < rightmostIndex)
 *     pivotIndex <- partition(array,leftmostIndex, rightmostIndex)
 *     quickSort(array, leftmostIndex, pivotIndex - 1)
 *     quickSort(array, pivotIndex, rightmostIndex)
 * 
 * quickSort(array, size)
 *   __quickSort__(arr, 0, size - 1)
 */
int partition(int *arr, int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            intSwap(arr + i, arr + j);
        }
    }
    intSwap(arr + i + 1, arr + r);
    return i + 1;
}

void __quickSort__(int *arr, int l, int r) {
    if (l >= r) return;
    int pi = partition(arr, l, r);
    __quickSort__(arr, l, pi - 1);
    __quickSort__(arr, pi + 1, r);
}

void quickSort(int *arr, size_t size) {
    __quickSort__(arr, 0, size - 1);
}

/*
 * frequencySort(arr, size):
 * mx = largest element of arr
 * count = [mx + 1] {0..0}
 * foreach element of arr as e:
 *      count[e]++;
 * i = 0;
 * for j = 0; j < mx + 1; j++:
 *      while count[j] > 0:
 *          arr[i++] = j;
 *          count[j]--;
 */
void frequencySort(int *arr, size_t size) {
    int mx = arr[0];
    for (size_t i = 0; i < size; i++)
        if (arr[i] > mx) mx = arr[i];
    int *freq = calloc(mx + 1, sizeof(int));
    for (size_t i = 0; i < size; i++) freq[arr[i]]++;
    size_t i = 0;
    for (size_t j = 0; j < mx + 1; j++) {
        while (freq[j] > 0) {
            arr[i++] = j;
            freq[j]--;
        }
    }
}
