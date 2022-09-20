#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#define N 1000

void printArr(int a[]) {
    int i;
    printf("{");
    for (i = 0; i < N; i++) {
        printf(" %d", a[i]);
    }
    printf(" }\n");
}

void bubbleSort(int a[]) {
    int i, j, temp;
    for (i = 0; i < N - 1; ++i)
        for (j = 0; j < N - 1; ++j)
            if (a[i] < a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}

void semiOptimized(int a[]) {
    int i, j, temp;
    for (i = 0; i < N - 1; ++i)
        for (j = 0; j < N - i - 1; ++j)
            if (a[j + 1] < a[j]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
}

void optimized(int a[]) {
    int i, j, temp;
    char flag;
    for (i = 0; i < N - 1; ++i) {
        flag = 't';
        for (j = 0; j < N - i - 1; ++j)
            if (a[j + 1] < a[j]) {

                flag = 'f';

                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }

        if (flag == 't')
            break;
    }
}

void calculateTime(int method, int a[]) {

    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);

    switch (method) {
        case 1:
            bubbleSort(a);
            break;
        case 2:
            semiOptimized(a);
            break;
        case 3:
            optimized(a);
            break;
    }

    gettimeofday(&tv2, NULL);

    printArr(a);
    printf("Time : %ld uSec\n", tv2.tv_usec - tv1.tv_usec);
}

int main() {
    int a[N], b[N], c[N], i;

    for (i = 0; i < N; i++) {
        a[i] = rand() % 100;
        b[i] = a[i];
        c[i] = a[i];
    }

    printf("Unsorted : ");
    printArr(a);

    printf("\nClassical : ");
    calculateTime(1, a);

    printf("Semi Opti : ");
    calculateTime(2, b);

    printf("Optimized : ");
    calculateTime(3, c);
}