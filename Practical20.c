#include<stdio.h>
#include<string.h>

int main() {
    char s1[10], s2[10];
    int m, n, i, j, shift = 0;
    printf("Enter the String 1: ");
    scanf("%s", s1);
    printf("Enter the String 2: ");
    scanf("%s", s2);
    n = strlen(s1);
    m = strlen(s2);
    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (s1[i + j] != s2[j]) {
                shift++;
                break;
            } else if (s1[i + j] == s2[j]) {
                continue;
            }
        }
        if (j == m)
            break;
    }
    if (shift == (n - m) + 1) {
        printf("\nNOT FOUND");
    } else
        printf("\nPattern found after shift: %d\n", shift);
}
