#include <stdio.h>
#define MAX 100
#define INF 99999

struct Edge {
    int u, v, w;
};

int main() {
    struct Edge e[MAX];
    int n, m, src, dist[100];
    int i, j, changed;

    printf("Enter vertices and edges: ");
    scanf("%d%d", &n, &m);

    printf("Enter edges (u v weight):\n");
    for (i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

    printf("Enter source vertex: ");
    scanf("%d", &src);

    for (i = 0; i < n; i++)
        dist[i] = INF;
    dist[src] = 0;

    for (i = 1; i < n; i++) {
        changed = 0;

        for (j = 0; j < m; j++) {
            int u = e[j].u, v = e[j].v, w = e[j].w;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                changed = 1;
            }
        }

        if (!changed)
            break;
    }

    for (j = 0; j < m; j++) {
        int u = e[j].u, v = e[j].v, w = e[j].w;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Negative weight cycle detected.\n");
            return 0;
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