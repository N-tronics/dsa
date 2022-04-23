#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include "sllist.h"
#include "heap.h"
#include "sort.h"

#define SIZE 1000
#define MAX  1000

int prnt = 0;
char *prntFile;
FILE *file;

void printArr(int *arr) {
    if (!prnt) return;
    for (int *i = arr; i < arr + SIZE; i++) {
        fprintf(file, "%d ", *i);
    }
    fprintf(file, "\n\n");
}

int main(int argc, char **argv) {
    if (argc < 2) {
        prnt = 0;
    } else {
        prnt = 1;
        prntFile = argv[1];
    }
    
    if (prnt)
        file = fopen(prntFile, "w");
    int *origArr = calloc(SIZE, sizeof(int)), *sortArr = calloc(SIZE, sizeof(int));
    if (origArr == NULL || sortArr == NULL) {
        printf("Couldn't allocate enough memory\n");
        return 1;
    }
    for (int *i = origArr; i < origArr + SIZE; i++)
        *i = rand() % (MAX + 1);

    srand(time(NULL));

    clock_t cpuTime;
    double elapsed;
    if (prnt)
        fprintf(file, "UNSORTED ARRAY:\n");
    printf("\033[32mUnsorted Array (%d)\033[m\n", SIZE);
    printArr(origArr);

    memcpy(sortArr, origArr, SIZE * sizeof(int));
    cpuTime = clock();
    bubbleSort(sortArr, SIZE);
    cpuTime = clock() - cpuTime;
    elapsed = (double)(cpuTime) / CLOCKS_PER_SEC;
    if (prnt)
        fprintf(file, "BUBBLE SORT:\n");
    printf("\033[32mBubble sort [%lf s]\033[m\n", elapsed);
    printArr(sortArr);

    memcpy(sortArr, origArr, SIZE * sizeof(int));
    cpuTime = clock();
    selectionSort(sortArr, SIZE);
    cpuTime = clock() - cpuTime;
    elapsed = (double)(cpuTime) / CLOCKS_PER_SEC;
    if (prnt)
        fprintf(file, "SELECTION SORT:\n");
    printf("\033[32mSelection sort [%lf s]\033[m\n", elapsed);
    printArr(sortArr);

    memcpy(sortArr, origArr, SIZE * sizeof(int));
    cpuTime = clock();
    insertionSort(sortArr, SIZE);
    cpuTime = clock() - cpuTime;
    elapsed = (double)(cpuTime) / CLOCKS_PER_SEC;
    if (prnt)
        fprintf(file, "INSERTION SORT:\n");
    printf("\033[32mInsertion sort [%lf s]\033[m\n", elapsed);
    printArr(sortArr);

    memcpy(sortArr, origArr, SIZE * sizeof(int));
    cpuTime = clock();
    mergeSort(sortArr, SIZE);
    cpuTime = clock() - cpuTime;
    elapsed = (double)(cpuTime) / CLOCKS_PER_SEC;
    if (prnt)
        fprintf(file, "MERGE SORT:\n");
    printf("\033[32mMerge sort [%lf s]\033[m\n", elapsed);
    printArr(sortArr);

    memcpy(sortArr, origArr, SIZE * sizeof(int));
    cpuTime = clock();
    quickSort(sortArr, SIZE);
    cpuTime = clock() - cpuTime;
    elapsed = (double)(cpuTime) / CLOCKS_PER_SEC;
    if (prnt)
        fprintf(file, "QUICK SORT:\n");
    printf("\033[32mQuick sort [%lf s]\033[m\n", elapsed);
    printArr(sortArr);

    memcpy(sortArr, origArr, SIZE * sizeof(int));
    cpuTime = clock();
    frequencySort(sortArr, SIZE);
    cpuTime = clock() - cpuTime;
    elapsed = (double)(cpuTime) / CLOCKS_PER_SEC;
    if (prnt)
        fprintf(file, "FREQUENCY SORT:\n");
    printf("\033[32mFrequency sort [%lf s]\033[m\n", elapsed);
    printArr(sortArr);

    if (prnt)
        fclose(file);
    free(origArr);
    free(sortArr);
}
