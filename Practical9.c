#include <stdio.h>
#include <stdlib.h>

#define N 300

void countingSort(int a[], int size, int max) {
    int count[max], output[size], i;

    for (i = 0; i <= max; ++i)
        count[i] = 0;

    for (i = 0; i < size; i++)
        count[a[i]]++;

    for (i = 1; i <= max; i++)
        count[i] += count[i - 1];

    for (i = size - 1; i >= 0; i--)
        output[--count[a[i]]] = a[i];

    for (i = 0; i < size; i++)
        a[i] = output[i];
}

void printArr(int a[]) {
    int i;
    printf("{");
    for (i = 0; i < N; i++) {
        printf(" %d", a[i]);
    }
    printf(" }\n");
}

int main() {
    int a[N], i, max = 0;

    for (i = 0; i < N; i++) {
        a[i] = rand() % 100;
        if(a[i]>max)
            max = a[i];
    }

    printf("Unsorted : ");
    printArr(a);

    countingSort(a, N, max);

    printf("Counting Sort : ");
    printArr(a);
    return 0;
}
