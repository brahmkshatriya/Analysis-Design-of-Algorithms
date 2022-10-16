#include <stdio.h>

#define INF 99999
#define V 5

int G[V][V] = {
        {INF, 9,  75, INF, INF},
        {9, INF,  95,  19, 42},
        {75,  95, INF, 51, 66},
        {INF, 19, 51, INF, 31},
        {INF, 42, 66,  31, INF}
};


int parent[V];

int find(int i) {
    while (parent[i])
        i = parent[i];
    return i;
}

int uni(int i, int j) {
    if (i != j) {
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main() {
    int i, j, a, b, u, v, no_of_edges = 1;
    int min, min_cost = 0;

    printf(" Edge : Weight");
    while (no_of_edges < V) {
        for (i = 0, min = INF; i < V; i++)
            for (j = 0; j < V; j++)
                if (G[i][j] < min) {
                    min = G[i][j];
                    a = u = i;
                    b = v = j;
                }

        u = find(u);
        v = find(v);
        if (uni(u, v)) {
            no_of_edges++;
            printf("\n%d - %d : %d", a, b, min);
            min_cost += min;
        }
        G[a][b] = G[b][a] = INF;
    }
    printf("\nMinimum G = %d\n", min_cost);
    return 0;
}

