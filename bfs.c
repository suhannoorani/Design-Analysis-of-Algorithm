#include <stdio.h>
#define MAX 20

int main() {
    int g[MAX][MAX], visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int n, start, i, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix (0 or 1):\n");
    for (i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS traversal: ");

    while (front < rear) {
        u = queue[front++];
        printf("%d ", u);

        for (i = 0; i < n; i++) {
            if (g[u][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }

    return 0;
}