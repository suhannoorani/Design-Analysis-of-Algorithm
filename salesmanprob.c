#include <stdio.h>
#define MAX 10
#define INF 999999

int n, cost[MAX][MAX];
int visited[MAX], best = INF;

void tsp(int city, int count, int total) {
    int i;

    if (total >= best)
        return;

    if (count == n) {
        if (cost[city][0] != 0 &&
            total + cost[city][0] < best)
            best = total + cost[city][0];
        return;
    }

    for (i = 0; i < n; i++) {
        if (!visited[i] && cost[city][i] != 0) {
            visited[i] = 1;
            tsp(i, count + 1, total + cost[city][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    int i, j;

    printf("Enter number of cities (max 10): ");
    scanf("%d", &n);

    if (n < 2 || n > MAX) {
        printf("Invalid number of cities.\n");
        return 0;
    }

    printf("Enter cost matrix (0 means no edge):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    visited[0] = 1;
    tsp(0, 1, 0);

    if (best == INF)
        printf("No complete tour exists.\n");
    else
        printf("Minimum tour cost = %d\n", best);

    return 0;
}