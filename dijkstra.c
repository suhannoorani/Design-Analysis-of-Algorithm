#include <stdio.h>
#define MAX 20
#define INF 99999

int main() {
    int g[MAX][MAX], dist[MAX], visited[MAX] = {0};
    int n, src, i, j, u, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 means no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            scanf("%d", &g[i][j]);
            if (i != j && g[i][j] == 0)
                g[i][j] = INF;
        }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    for (i = 0; i < n; i++)
        dist[i] = INF;

    dist[src] = 0;

    for (i = 0; i < n; i++) {
        min = INF;
        u = -1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] && g[u][j] != INF &&
                dist[u] + g[u][j] < dist[j])
                dist[j] = dist[u] + g[u][j];
        }
    }

    printf("Vertex\tDistance\n");
    for (i = 0; i < n; i++) {
        if (dist[i] == INF)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, dist[i]);
    }

    return 0;
}