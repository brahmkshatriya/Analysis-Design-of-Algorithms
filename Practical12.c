#include <stdio.h>

int mat[10][10];

int que[10], visited[10];
int n, f = 0, r = -1;

void bfs(int root) {
    for (int i = 0; i < n; ++i)
        if (mat[root][i] && !visited[i])
            que[++r] = i;

    if (f <= r) {
        visited[que[f]] = 1;
        bfs(que[f++]);
    }
}

int main() {
    int i, j;

    printf("Enter number of Nodes :");
    scanf(" %d", &n);

    for (i = 0; i < n; ++i) {
        printf("Enter adjacent matrix of %d : \n", i);
        for (j = 0; j < n; ++j) {
            scanf("%d", &mat[i][j]);
        }
    }

    for (i = 0; i < n; ++i) {
        que[i] = 0;
        visited[i] = 0;
    }

    int v;
    printf("Enter starting vertex : ");
    scanf("%d", &v);

    bfs(v);

    printf("\nBFS :");
    for (i = 0; i < n; ++i) {
        if (visited[i])
            printf("%d", i);
        else {
            printf("\nAll nodes cannot be visited");
            break;
        }
    }

    return 0;
}