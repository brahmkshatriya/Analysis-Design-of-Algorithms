#include <stdio.h>

int mat[10][10];

int n,visited[10];

void dfs(int root) {
    visited[root] = 1;
    printf("\nVisited %d",root);
    for (int i = 0; i < n; ++i) {
        if(visited[i]!=1 && mat[root][i] == 1){
            dfs(i);
        }
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

    printf("\nDFS : ");

    dfs(0);
    return 0;
}