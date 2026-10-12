#include <stdio.h>
#define MAX 20

int g[MAX][MAX], visited[MAX], n;

void dfs(int v) {
    int i;

    visited[v] = 1;
    printf("%d ", v);

    for (i = 0; i < n; i++) {
        if (g[v][i] && !visited[i])
            dfs(i);
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 or 1):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    dfs(start);

    return 0;
}