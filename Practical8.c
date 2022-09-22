#include <stdio.h>
#include <stdlib.h>

#define N 300

int partition(int a[], int left, int right) {

    int pivot = a[right];
    int i = (left - 1), temp;

    for (int j = left; j < right; j++) {
        if (a[j] <= pivot) {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[right];
    a[right] = temp;

    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
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
    int a[N], i;

    for (i = 0; i < N; i++) {
        a[i] = rand() % 100;
    }

    printf("Unsorted : ");
    printArr(a);

    quickSort(a, 0, N);

    printf("Quick Sort : ");
    printArr(a);
    return 0;
}
