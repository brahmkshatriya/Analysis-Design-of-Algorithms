#include<stdio.h>

int main() {
    float w[10], v[10], ratio[10], inc[10] = {0}, M, u, temp, tp = 0;
    int n, i, j;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter weight and profit of each item: \n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &w[i], &v[i]);
    }
    printf("The weights are: ");
    for (i = 0; i < n; i++) {
        printf(" %f ", w[i]);
    }
    printf("\nThe Profits are: ");
    for (i = 0; i < n; i++) {
        printf(" %f ", v[i]);
    }
    printf("\nEnter the Capacity of Bag: ");
    scanf("%f", &M);
    for (i = 0; i < n; i++) {
        ratio[i] = v[i] / w[i];
    }
    //Sorting the ratio in descending order along with weights and profits
    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (ratio[j] < ratio[j + 1]) {
                temp = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = temp;

                temp = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp;

                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }


    u = M;
    for (i = 0; i < n; i++) {
        if (w[i] > u)
            break;
        else {
            inc[i] = 1.0;
            tp = tp + v[i];
            u = u - w[i];
        }
    }
    if (i < n) {
        inc[i] = u / w[i];
        tp = tp + (inc[i] * v[i]);
    }
    printf("\nThe result Array is: ");
    for (i = 0; i < n; i++) {
        printf("%f\t", inc[i]);
    }
    printf("\nMaximum profit is: %f\n", tp);
}
