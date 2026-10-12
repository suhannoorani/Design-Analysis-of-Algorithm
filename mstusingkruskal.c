#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int u, v, w;
};

int parent[100];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return 0;

    parent[b] = a;
    return 1;
}

int compare(const void *a, const void *b) {
    return ((struct Edge *)a)->w -
           ((struct Edge *)b)->w;
}

int main() {
    struct Edge e[500], temp;
    int n, m, i, count = 0, cost = 0;

    printf("Enter vertices and edges: ");
    scanf("%d%d", &n, &m);

    printf("Enter edges (u v weight), vertices 0 to n-1:\n");
    for (i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);

    for (i = 0; i < n; i++)
        parent[i] = i;

    qsort(e, m, sizeof(struct Edge), compare);

    for (i = 0; i < m && count < n - 1; i++) {
        if (unite(e[i].u, e[i].v)) {
            printf("%d - %d : %d\n",
                   e[i].u, e[i].v, e[i].w);
            cost += e[i].w;
            count++;
        }
    }

    if (count != n - 1)
        printf("Graph is disconnected.\n");
    else
        printf("Minimum cost = %d\n", cost);

    return 0;
}