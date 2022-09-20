#include <stdio.h>
#include <sys/time.h>

long linearSearch(int n) {
    long res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

int binarySearch(long n) {
    long res;
    if (n == 1)
        return 1;
    else
        res = n * recursive(n - 1);
    return res;
}

void calculateTime(int method, int n) {
    long ans;
    struct timeval tv1, tv2;
    gettimeofday(&tv1, NULL);

    switch (method) {
        case 1:
            ans = iterative(n);
            break;
        case 2:
            ans = recursive(n);
            break;
    }

    gettimeofday(&tv2, NULL);

    printf("%ld\n", ans);
    printf("Time : %ld uSec\n", tv2.tv_usec - tv1.tv_usec);
}


int main() {
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);

    printf("Iterative : ");
    calculateTime(1, n);

    printf("Recursive : ");
    calculateTime(2, n);

    return 0;
}
