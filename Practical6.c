#include <stdio.h>
#include <sys/time.h>

#define N 1000

void printArr(int a[]) {
    int i;
    printf("{");
    for (i = 0; i < N; i++) {
        printf(" %d", a[i]);
    }
    printf(" }\n");
}

int linearSearch(int a[], int val) {
    for (int i = 0; i <= N; i++)
        if (a[i] == val)
            return i;
    return -1;
}

int binarySearch(int a[], int start, int end, int val) {
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    if (a[mid] == val)
        return mid;
    if (a[mid] > val)
        return binarySearch(a, start, mid - 1, val);
    return binarySearch(a, mid + 1, end, val);
}

void calculateTime(int method, int a[], int val) {
    int ans;
    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);

    switch (method) {
        case 1:
            ans = linearSearch(a, val);
            break;
        case 2:
            ans = binarySearch(a, 0, N, val);
            break;
    }

    gettimeofday(&tv2, NULL);

    printf("%d\n", ans);
    printf("Time : %ld uSec\n", tv2.tv_usec - tv1.tv_usec);
}


int main() {
    int a[N], i, n;

    for (i = 0; i < N; i++) {
        a[i] = i + 1;
    }

    printf("Array : ");
    printArr(a);

    printf("Value to Find : ");
    scanf("%d", &n);

    printf("\nLinear Search : ");
    calculateTime(1, a, n);

    printf("Binary Search : ");
    calculateTime(2, a, n);

    return 0;
}
