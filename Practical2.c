#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#define N 300

void printArr(int a[]) {
    int i;
    printf("{");
    for (i = 0; i < N; i++) {
        printf(" %d", a[i]);
    }
    printf(" }\n");
}

void insertionSort(int *a) {
    for (int step = 1; step < N; step++) {
        int key = a[step], j;

        for (j = step - 1; key < a[j] && j >= 0; --j) {
            a[j + 1] = a[j];
        }
        a[j + 1] = key;
    }
}

int main() {
    int a[N], i;

    for (i = 0; i < N; i++) {
        a[i] = rand() % 100;
    }

    printf("Unsorted : ");
    printArr(a);

    printf("\nInsertion Sort : ");
    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);

    insertionSort(a);

    gettimeofday(&tv2, NULL);

    printArr(a);
    printf("Time : %ld uSec\n", tv2.tv_usec - tv1.tv_usec);
}