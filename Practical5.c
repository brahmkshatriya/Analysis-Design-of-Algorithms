#include <stdio.h>
#include <stdlib.h>

#define N 7

int maximum(int a[], int start, int end) {
    if (start == end)
        return a[start];

    if (start + 1 == end) {
        if (a[start] > a[end])
            return a[start];
        return a[end];
    }

    int mid = (start + end) / 2;
    int max1 = maximum(a, start, mid);
    int max2 = maximum(a, mid + 1, end);

    if (max1 > max2)
        return max1;
    return max2;
}


int minimum(int a[], int start, int end) {
    if (start == end)
        return a[start];

    if (start + 1 == end) {
        if (a[start] < a[end])
            return a[start];
        return a[end];
    }

    int mid = (start + end) / 2;
    int min1 = minimum(a, start, mid);
    int min2 = minimum(a, mid + 1, end);

    if (min1 < min2)
        return min1;
    return min2;
}

int main() {
    int a[N], i;
    printf("Array :");
    for (i = 0; i < N; i++) {
        a[i] = rand() % 15;
        printf(" %d", a[i]);
    }
    printf("\nMinimum : %d", minimum(a, 0, N));
    printf("\nMaximum : %d", maximum(a, 0, N));
    return 0;
}


