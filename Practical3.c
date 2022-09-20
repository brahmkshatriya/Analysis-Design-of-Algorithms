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

void selectionSort(int *a) {
    int min, i, j, temp;
    for (i = 0; i < N - 1; ++i) {
        min = i;

        for (j = i + 1; j < N; ++j)
            if (a[j] < a[min])
                min = j;

        temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}

int main() {
    int a[N], i;

    for (i = 0; i < N; i++) {
        a[i] = rand() % 100;
    }

    printf("Unsorted : ");
    printArr(a);

    printf("\nSelection Sort : ");
    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);

    selectionSort(a);

    gettimeofday(&tv2, NULL);

    printArr(a);
    printf("Time : %ld uSec\n", tv2.tv_usec - tv1.tv_usec);
}