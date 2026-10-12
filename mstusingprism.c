#include <stdio.h>
#define MAX 20
#define INF 99999

int main() {
    int g[MAX][MAX], selected[MAX] = {0};
    int n, i, j, edges = 0;
    int min, u = -1, v = -1, cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    selected[0] = 1;

    while (edges < n - 1) {
        min = INF;
        u = v = -1;

        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] && g[i][j] != 0 &&
                        g[i][j] < min) {
                        min = g[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u == -1) {
            printf("Graph is disconnected.\n");
            return 0;
        }

        printf("%d - %d : %d\n", u, v, min);
        cost += min;
        selected[v] = 1;
        edges++;
    }

    printf("Minimum cost = %d\n", cost);
    return 0;
}