#include<stdio.h>

int main() {
    int n, c, coins[10], i, j, coins_needed[10], new_c;
    int a[20][20], temp1, temp2, pointer, count = 0;
    printf("How many coins you want to enter: ");
    scanf("%d", &n);
    printf("Enter the coins: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }
    printf("How much Change you want: ");
    scanf("%d", &c);
    for (i = 0; i < n; i++) {
        for (j = 0; j <= c; j++) {
            if (j == 0) {
                a[i][j] = 0;
            }
            if (i > 0 && coins[i] > j) {
                a[i][j] = a[i - 1][j];
            } else if (i == 0 && coins[i] == 1) {
                a[i][j] = j;
            } else {
                temp1 = a[i - 1][j];
                temp2 = 1 + a[i][j - coins[i]];
                if (a[temp1] <= a[temp2])
                    a[i][j] = temp1;
                else
                    a[i][j] = temp2;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j <= c; j++) {
            printf(" %d ", a[i][j]);
        }
        printf("\n");
    }
    printf("The minimum number of coins to get change of rs. %d is %d\n", c, a[n - 1][c]);
    i = n - 1;
    j = c;
    new_c = c;
    while (new_c > 0) {
        pointer = a[i][j];
        if (a[i - 1][j] == pointer) {
            i--;
        } else {
            coins_needed[count] = coins[i];
            count++;
            new_c = new_c - coins[i];
            j = new_c;
        }
    }
    printf("Coins needed are:");
    for (i = 0; i < count; i++) {
        printf(" %d", coins_needed[i]);
    }
    printf("\n");
}