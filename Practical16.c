#include<stdio.h>

int c[20][20];

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int w[10], v[10], M, n, i, j, inc[10] = {0};
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter weight and profit of each item: \n");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }
    printf("The weights are: ");
    for (i = 0; i < n; i++) {
        printf(" %d ", w[i]);
    }
    printf("\nThe Profits are: ");
    for (i = 0; i < n; i++) {
        printf(" %d ", v[i]);
    }
    printf("\nEnter the Capacity of Bag: ");
    scanf("%d", &M);
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= M; j++) {
            if (i == 0 || j == 0) {
                c[i][j] = 0;
            } else if (w[i - 1] <= j) {
                c[i][j] = max(v[i - 1] + c[i - 1][j - w[i - 1]], c[i - 1][j]);
            } else {
                c[i][j] = c[i - 1][j];
            }
        }
    }
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= M; j++) {
            printf(" %d ", c[i][j]);
        }
        printf("\n");
    }
    printf("Max profit is: %d\n", c[n][M]);
    i = n;
    j = M;
    while (i >= 0) {
        if (c[i][j] != c[i - 1][j]) {
            inc[i - 1] = 1;
            i--;
            j = j - w[i - 1];
        } else {
            i--;
        }
    }
    printf("Included items array is: ");
    for (i = 0; i < n; i++) {
        printf(" %d ", inc[i]);
    }
    printf("\nItems Included are : ");
    for (i = 0; i < n; i++) {
        if (inc[i] == 1)
            printf(" %d ", i + 1);
    }
    printf("\n");
    return 0;
}
